#include "window.h"

#include <random>
#include <vector>

using namespace std;

#include <QPainter>

Window::Window(size_t w, size_t h, unsigned s, double p, unsigned long i) :
QWidget(nullptr), Width(w), Height(h), Scale(s), Size(Width * Height),
World(Size, 0), Prob(p), Interval(i), step(0){
    setFixedSize(Width * Scale, Height * Scale);

    random_device rd;
    mt19937_64 gen(rd());
    bernoulli_distribution d(Prob);
    for(size_t i = 0; i < Size; ++i){
        World[i] = d(gen);
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
            QColor color;
            if(test(i, j)){
                color = Qt::black;
            }
            else{
                color = Qt::white;
            }
            painter.fillRect(j * Scale, i * Scale, Scale, Scale, color);
        }
    }
}

static vector<unsigned char>
countAlive(const size_t Width, const size_t Height,
           vector<unsigned char> &World){
    const size_t Size = Width * Height;
    const int offsets[][2] = {
        {-1, -1}, {0, -1}, {+1, -1},
        {-1,  0},          {+1,  0},
        {-1, +1}, {0, +1}, {+1, +1}
    };
    vector<unsigned char> Result(Size, 0);
    auto increase = [&](size_t pos){
        for(auto offset : offsets){
            int X = (pos / Width + offset[0]) % Height;
            int Y = (pos % Width + offset[1]) % Width;
            ++Result[X * Width + Y];
        }
    };
    for(size_t i = 0; i < Size; ++i){
        if(World[i]){
            increase(i);
        }
    }
    return Result;
}

// Conway
static void rule23_3(const size_t Width, const size_t Height,
                     vector<unsigned char> &World){
    const size_t Size = Width * Height;
    auto Res = countAlive(Width, Height, World);
    for(size_t i = 0; i < Size; ++i){
        if(World[i] &&
           !(Res[i] == 2 || Res[i] == 3)){   // alive -> dead
            World[i] = false;
        }
        else if(!World[i] && Res[i] == 3){  // dead -> alive
            World[i] = true;
        }
    }
}

// High Life
static void rule23_36(const size_t Width, const size_t Height,
                      vector<unsigned char> &World){
    const size_t Size = Width * Height;
    auto Res = countAlive(Width, Height, World);
    for(size_t i = 0; i < Size; ++i){
        if(World[i] &&
           !(Res[i] == 2 || Res[i] == 3)){
            World[i] = false;
        }
        else if(!World[i] &&
                (Res[i] == 3 || Res[i] == 6)){
            World[i] = true;
        }
    }
}

void Window::evolve(Window *w){
    while(true){
        rule23_36(w->Width, w->Height, w->World);
        ++w->step;
        w->update();
        QThread::msleep(w->Interval);
    }
}

bool Window::test(size_t i, size_t j){
    return World[i * Width + j];
}
