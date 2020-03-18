#include <iostream>
#include <thread>
#include "../headers/Table.h"
#include "../headers/Philosopher.h"

using namespace std;

void start_the_feast() {
    Table table;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "The feast has started!\n";

    vector<Philosopher *> philosophers(NUMBER_OF_PHILOSOPHERS);

    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        auto aux = unique_ptr<Fork>(new Fork());
        table.forks.emplace_back(move(aux));
    }

    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        if (i != NUMBER_OF_PHILOSOPHERS - 1) {
            philosophers[i] = new Philosopher(table, *table.forks[i], *table.forks[i+1]);
        }
        else {
            philosophers[i] = new Philosopher(table, *table.forks[i], *table.forks[0]);
        }
    }

    table.ready = true;
    this_thread::sleep_for(chrono::seconds(5));
    table.ready = false;

    cout << "The feast is over and nobody is dead!\n";
}

int main() {

    start_the_feast();

    return 0;
}
