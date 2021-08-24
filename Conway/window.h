#ifndef WINDOW_H
#define WINDOW_H

#include <set>
#include <vector>
#include <tuple>

#include <QThread>
#include <QWidget>

class Window final : public QWidget
{
    Q_OBJECT
public:
    enum Rule{
        RULE23_3,   // Conway
        RULE23_36,  // High Life
        RULE4567_345,   // Assimilation
        RULE125_36, // 2X2
        RULE34578_3678, // Day and Night
        RULE1358_357,   // Amoeba
        RULE245_368,    // Move
        RULE238_357,    // Pseudo Life
        RULE5678_35678, // Diamoeba
        RULE34_34,  // 34
        RULE5_345,  // Long Life
        RULE235678_3678,    // Stains
        RULE_2, // Seeds
        RULE12345_3,    // Maze
        RULE235678_378, // Coagulations
        RULE2345_45678, // Walled Cities
        RULE1_1,    // Gnarl
        RULE1357_1357,  // Replicaor
        RULE05678_3458, // Mystery
        RULE3456_278_6, // Star Wars
        RULE3458_37_4,  // Live on the Edge
        RULE6_246_3,    // Brian 6
        RULE12_34_3,    // Frogs
        RULE124_3_3,    // Like Frogs Rule
    };
    explicit Window(size_t Width, size_t Height, unsigned Scale = 1,
                    Rule R = RULE23_3, double Prob = 0.3,
                    unsigned long Interval = 40);
    ~Window();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    static void evolve(Window *window);
    int test(size_t i, size_t j);
    const size_t Width;
    const size_t Height;
    const size_t Scale;
    const size_t Size;
    std::vector<char> World;
    std::tuple<std::set<unsigned char>,
               std::set<unsigned char>,
               unsigned> RuleTuple;
    const double Prob;
    const unsigned long Interval;
    QThread *MainLoop;
    uint64_t step;
};

#endif // WINDOW_H
