/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */
#include <iostream>

#include "../headers/Philosopher.h"
#include "../headers/Parameters.h"

using namespace std;

Philosopher::Philosopher(Table &table, Fork &rightFork, Fork &leftFork)
        : id(current_id++), table(table), right_fork(rightFork), left_fork(leftFork), life(&Philosopher::dine, this),
          state(State::SLEEPING) {}

Philosopher::~Philosopher() {
    life.join();
}

void Philosopher::eat() {
    if (&left_fork == &right_fork)
        cerr << "Left and right forks should not be "
                "the same!";

    state = State::WAITING_FOR_FORKS;

    lock(left_fork.mutex, right_fork.mutex);    // ensures there are no deadlocks
    lock_guard<mutex> left_lock(left_fork.mutex, adopt_lock);
    lock_guard<mutex> right_lock(right_fork.mutex, adopt_lock);

    state = State::EATING;

    chrono::milliseconds eating_time(EATING_TIME);
    this_thread::sleep_for(eating_time);
}

void Philosopher::think() {
    state = State::THINKING;

    chrono::milliseconds thinking_time(THINKING_TIME);
    this_thread::sleep_for(thinking_time);
}

void Philosopher::dine() {
    table.wait_for_all();

    while (table.no_of_ready_philosophers) {
        think();
        eat();
    }
}
