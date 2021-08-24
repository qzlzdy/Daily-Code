#include "window.h"

#include <random>
#include <vector>

using namespace std;

#include <QLabel>
#include <QPainter>

static vector<unsigned char>
countAlive(const size_t Width, const size_t Height,
           vector<char> &World){
    const size_t Size = Width * Height;
    const int offsets[][2] = {
        {-1, -1}, {0, -1}, {+1, -1},
        {-1,  0},          {+1,  0},
        {-1, +1}, {0, +1}, {+1, +1}
    };
    vector<unsigned char> Result(Size, 0);
    auto increase = [&](size_t idx){
        int pos = idx;
        for(auto offset : offsets){
            int X = (pos / Width + offset[0] + Height) % Height;
            int Y = (pos % Width + offset[1] + Width) % Width;
            ++Result[X * Width + Y];
        }
    };
    for(size_t i = 0; i < Size; ++i){
        if(World[i] > 0){
            increase(i);
        }
    }
    return Result;
}

static void applyRule(tuple<set<unsigned char>, set<unsigned char>,
                            unsigned> &rule,
                      const size_t Width, const size_t Height,
                      vector<char> &World){
    const size_t Size = Width * Height;
    auto Res = countAlive(Width, Height, World);
    for(size_t i = 0; i < Size; ++i){
        if(World[i] > 0 && get<0>(rule).find(Res[i]) == get<0>(rule).end()){
            World[i] = -get<2>(rule);
        }
        else if(World[i] == 0 &&
                get<1>(rule).find(Res[i]) != get<1>(rule).end()){
            World[i] = 1;
        }
        else if(World[i] < 0){
            ++World[i];
        }
    }
}

Window::Window(size_t w, size_t h, unsigned s,
               Rule r, double p, unsigned long i) :
QWidget(nullptr), Width(w), Height(h), Scale(s), Size(Width * Height),
World(Size, 0), Prob(p), Interval(i), step(0){
    setFixedSize(Width * Scale, Height * Scale);

    random_device rd;
    mt19937_64 gen(rd());
    bernoulli_distribution d(Prob);
    for(size_t i = 0; i < Size; ++i){
        World[i] = d(gen);
    }

    set<unsigned char> KeepIf = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    set<unsigned char> BirthIf = {};
    unsigned silent = 0;
    switch(r){
    case RULE23_3:
        KeepIf = {2, 3};
        BirthIf = {3};
        break;
    case RULE23_36:
        KeepIf = {2, 3};
        BirthIf = {3, 6};
        break;
    case RULE4567_345:
        KeepIf = {4, 5, 6, 7};
        BirthIf = {3, 4, 5};
        break;
    case RULE125_36:
        KeepIf = {1, 2, 5};
        BirthIf = {3, 6};
        break;
    case RULE34578_3678:
        KeepIf = {3, 4, 5, 7, 8};
        BirthIf = {3, 6, 7, 8};
        break;
    case RULE1358_357:
        KeepIf = {1, 3, 5, 8};
        BirthIf = {3, 5, 7};
        break;
    case RULE245_368:
        KeepIf = {2, 4, 5};
        BirthIf = {3, 6, 8};
        break;
    case RULE238_357:
        KeepIf = {2, 3, 8};
        BirthIf = {3, 5, 7};
        break;
    case RULE5678_35678:
        KeepIf = {5, 6, 7, 8};
        BirthIf = {3, 5, 6, 7, 8};
        break;
    case RULE34_34:
        KeepIf = {3, 4};
        BirthIf = {3, 4};
        break;
    case RULE5_345:
        KeepIf = {5};
        BirthIf = {3, 4, 5};
        break;
    case RULE235678_3678:
        KeepIf = {2, 3, 5, 6, 7, 8};
        BirthIf = {3, 6, 7, 8};
        break;
    case RULE_2:
        KeepIf = {};
        BirthIf = {2};
        break;
    case RULE12345_3:
        KeepIf = {1, 2, 3, 4, 5};
        BirthIf = {3};
        break;
    case RULE235678_378:
        KeepIf = {2, 3, 5, 6, 7, 8};
        BirthIf = {3, 7, 8};
        break;
    case RULE2345_45678:
        KeepIf = {2, 3, 4, 5};
        BirthIf = {4, 5, 6, 7, 8};
        break;
    case RULE1_1:
        KeepIf = {1};
        BirthIf = {1};
        break;
    case RULE1357_1357:
        KeepIf = {1, 3, 5, 7};
        BirthIf = {1, 3, 5, 7};
        break;
    case RULE05678_3458:
        KeepIf = {0, 5, 6, 7, 8};
        BirthIf = {3, 4, 5, 8};
        break;
    case RULE3456_278_6:
        KeepIf = {3, 4, 5, 6};
        BirthIf = {2, 7, 8};
        silent = 6;
        break;
    case RULE3458_37_4:
        KeepIf = {3, 4, 5, 8};
        BirthIf = {3, 7};
        silent = 4;
        break;
    case RULE6_246_3:
        KeepIf = {6};
        BirthIf = {2, 4, 6};
        silent = 3;
        break;
    case RULE12_34_3:
        KeepIf = {1, 2};
        BirthIf = {3, 4};
        silent = 3;
        break;
    case RULE124_3_3:
        KeepIf = {1, 2, 4};
        BirthIf = {3};
        silent = 3;
        break;
    }
    RuleTuple = make_tuple(KeepIf, BirthIf, silent);

    MainLoop = QThread::create(evolve, this);
    MainLoop->start();
}

Window::~Window(){
    MainLoop->terminate();
    MainLoop->wait();
}

void Window::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for(size_t i = 0; i < Height; ++i){
        for(size_t j = 0; j < Width; ++j){
            QColor color;
            switch(test(i, j)){
            case 1:
                color = Qt::black;
                break;
            case 0:
                color = Qt::white;
                break;
            case -1:
                color = Qt::gray;
                break;
            }
            painter.fillRect(j * Scale, i * Scale, Scale, Scale, color);
        }
    }
}

void Window::evolve(Window *w){
    while(true){
        applyRule(w->RuleTuple, w->Width, w->Height, w->World);
        ++w->step;
        w->update();
        QThread::msleep(w->Interval);
    }
}

int Window::test(size_t i, size_t j){
    if(World[i * Width + j] > 0){
        return 1;
    }
    if(World[i * Width + j] < 0){
        return -1;
    }
    return 0;
}
