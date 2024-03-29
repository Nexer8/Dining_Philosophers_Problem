/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */

#ifndef DINING_PHILOSOPHERS_PROBLEM_PHILOSOPHER_H
#define DINING_PHILOSOPHERS_PROBLEM_PHILOSOPHER_H


#include <string>
#include <thread>

#include "Fork.h"
#include "Table.h"

static int current_id = 0;
enum class State {
    SLEEPING,
    THINKING,
    EATING,
    WAITING_FOR_FORKS
};

/*! \class Philosopher
    \brief A class that simulates philosopher.

    Philosopher that sits at a dining table.
*/
class Philosopher {
private:
    int id;
    volatile State state;
    Table &table;
    Fork &left_fork;
    Fork &right_fork;
    std::thread life;

public:
    Philosopher(Table &table, Fork &rightFork, Fork &leftFork);

    ~Philosopher();

    void dine();

    void think();

    void eat();

    int get_id() { return id; }

    State get_state() { return state; }
};


#endif //DINING_PHILOSOPHERS_PROBLEM_PHILOSOPHER_H
