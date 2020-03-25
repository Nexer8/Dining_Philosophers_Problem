//
// Created by mwisniewski on 3/25/20.
//

#ifndef DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H
#define DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H


#include <thread>
#include <ncurses.h>
#include "Philosopher.h"

class Visualizer {
private:
    std::thread thread;
    WINDOW *window;
    std::vector<std::shared_ptr<Philosopher>> philosophers;
    Table &table;

    struct Params {
        int x_max;
        int y_max;
        int x_margin;
        int y_margin;
        int separator;
    } window_params;

    void init();

    void update_screen();

    void update();

public:
    Visualizer(std::vector<std::shared_ptr<Philosopher> > &philosophers, Table &table);

    ~Visualizer();
};


#endif //DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H
