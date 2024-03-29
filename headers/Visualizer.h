/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/25/20
 */

#ifndef DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H
#define DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H


#include <thread>
#include <ncurses.h>
#include "Philosopher.h"


/*! \class Visualizer
    \brief A class that is responsible for the visual part happening on the screen.

    Visualizer that runs ncurses.
*/
class Visualizer {
private:
    std::thread thread;
    WINDOW *window;
    std::vector<std::shared_ptr<Philosopher>> &philosophers;
    Table &table;

    struct Window_params {
        int x_max;
        int y_max;
        int x_margin;
        int y_margin;
        int separator;
    } params;

    void init();

    void update_screen();

    void update();

public:
    Visualizer(std::vector<std::shared_ptr<Philosopher> > &philosophers, Table &table);

    ~Visualizer();
};


#endif //DINING_PHILOSOPHERS_PROBLEM_VISUALIZER_H
