#include "window.h"

#include <random>
#include <vector>

using namespace std;

#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPainter>

static vector<pair<int, int>>
countAlive(const size_t Width, const size_t Height,
           vector<Cell> &World){
    const size_t Size = Width * Height;
    const int offsets[][2] = {
        {-1, -1}, {0, -1}, {+1, -1},
        {-1,  0},          {+1,  0},
        {-1, +1}, {0, +1}, {+1, +1}
    };
    vector<pair<int, int>> Result(Size, make_pair(-1, -1));
    auto increase = [&](size_t idx, Cell::Gender sex){
        int pos = idx;
        for(auto offset : offsets){
            size_t X = (pos / Width + offset[0] + Height) % Height;
            size_t Y = (pos % Width + offset[1] + Width) % Width;
            size_t I = X * Width + Y;
            switch(sex){
            case Cell::Male:
                if(Result[I].first == -1){
                    Result[I].first = idx;
                }
                else{
                    Result[I].first = -2;
                }
                break;
            case Cell::Female:
                if(Result[I].second == -1){
                    Result[I].second = idx;
                }
                else{
                    Result[I].second = -2;
                }
                break;
            }
        }
    };
    for(size_t i = 0; i < Size; ++i){
        if(World[i].isFertile()){
            increase(i, World[i].getSex());
        }
    }
    return Result;
}

static void applyRule(const size_t Width, const size_t Height,
                      vector<Cell> &World){
    const size_t Size = Width * Height;
    auto Res = countAlive(Width, Height, World);
    for(size_t i = 0; i < Size; ++i){
        if(!World[i].isAlive() && Res[i].first >= 0 && Res[i].second >= 0){
            World[i].birth(World[Res[i].first], World[Res[i].second]);
        }
        else if(World[i].isAlive()){
            World[i].grow();
        }
    }
}

Window::Window(size_t w, size_t h, unsigned s, double p, unsigned long i) :
QWidget(nullptr), Width(w), Height(h), Scale(s), Size(Width * Height),
World(Size), Prob(p), Interval(i), step(0){
    QDesktopWidget *desktop = QApplication::desktop();
    size_t windowWidth = Width * Scale;
    size_t windowHeight = Height * Scale;
    setGeometry((desktop->width() - windowWidth) / 2,
                (desktop->height() - windowHeight) / 2,
                windowWidth, windowHeight);

    random_device rd;
    mt19937_64 gen(rd());
    bernoulli_distribution d(Prob);
    for(size_t i = 0; i < Size; ++i){
        if(d(gen)){
            World[i].birth();
        }
    }

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
            painter.fillRect(j * Scale, i * Scale, Scale,
                             Scale, getColor(i, j));
        }
    }
}

void Window::evolve(Window *w){
    while(true){
        applyRule(w->Width, w->Height, w->World);
        ++w->step;
        w->update();
        QThread::msleep(w->Interval);
    }
}

QColor Window::getColor(size_t i, size_t j){
    const Cell &cell = World[i * Width + j];
    if(!cell.isAlive()){
        return Qt::white;
    }
    auto x = cell.getCharacter();
    return QColor((x >> 16) & 0xff, (x >> 8) & 0xff, x & 0xff);
}
