#ifndef WINDOW_H
#define WINDOW_H

#include <vector>

#include <QThread>
#include <QWidget>

class Window final : public QWidget
{
    Q_OBJECT
public:
    explicit Window(size_t Width, size_t Height, unsigned Scale = 1,
                    double Prob = 0.3, unsigned long Interval = 40);
    ~Window();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    static void evolve(Window *window);
    bool test(size_t i, size_t j);
    const size_t Width;
    const size_t Height;
    const size_t Scale;
    const size_t Size;
    std::vector<unsigned char> World;
    const double Prob;
    const unsigned long Interval;
    QThread *MainLoop;
    uint64_t step;
};

#endif // WINDOW_H
