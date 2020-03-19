#include <iostream>
#include <thread>
#include <ncurses.h>
#include "../headers/Table.h"
#include "../headers/Philosopher.h"
#include "../headers/Parameters.h"

using namespace std;

inline void start_the_feast() {
    Table table;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "The feast has started!\n";

    vector< unique_ptr<Philosopher> > philosophers;

    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        if (i != NUMBER_OF_PHILOSOPHERS - 1) {
            philosophers.emplace_back(new Philosopher(table, *table.forks[i], *table.forks[i+1]));
        }
        else {
            philosophers.emplace_back(new Philosopher(table, *table.forks[i], *table.forks[0]));
        }
    }

    table.ready = true;
    this_thread::sleep_for(chrono::seconds(FEAST_TIME));
    table.ready = false;

    philosophers.clear();

    cout << "The feast is over and nobody is dead!\n";
}

int main() {

//    initscr();
//    refresh();
    
    start_the_feast();

//    endwin();
    return 0;
}
