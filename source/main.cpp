#include <iostream>
#include <thread>
#include "../headers/Table.h"
#include "../headers/Philosopher.h"
#include "../headers/Parameters.h"
#include "../headers/Visualizer.h"

using namespace std;

inline void start_the_feast() {
    Table table;
    vector<shared_ptr<Philosopher> > philosophers;

    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        if (i != NUMBER_OF_PHILOSOPHERS - 1) {
            philosophers.emplace_back(new Philosopher(table, *table.forks[i], *table.forks[i + 1]));
        } else {
            philosophers.emplace_back(new Philosopher(table, *table.forks[i], *table.forks[0]));
        }
    }

    Visualizer *visualizer = new Visualizer(philosophers, table);

    this_thread::sleep_for(chrono::seconds(FEAST_TIME));
    table.no_of_ready_philosophers = 0;

    delete visualizer;
    philosophers.clear();
}

int main() {
    start_the_feast();

    return 0;
}
