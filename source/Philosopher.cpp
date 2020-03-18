//
// Created by mwisniewski on 3/18/20.
//

#include <iostream>
#include <random>

#include "../headers/Philosopher.h"

using namespace std;

Philosopher::Philosopher(Table const &table, Fork &rightFork, Fork &leftFork)
        : id(current_id++), table(table), right_fork(rightFork), left_fork(leftFork), life(&Philosopher::dine, this){}

Philosopher::~Philosopher() {
    life.join();
}

void Philosopher::eat() {
    if (&left_fork == &right_fork)
        cerr << "Left and right forks should not be the same!";

    lock(left_fork.mutex, right_fork.mutex);    // ensures there are no deadlocks
    lock_guard<mutex> a(left_fork.mutex, adopt_lock);
    lock_guard<mutex> b(right_fork.mutex, adopt_lock);

    cout << "Philosopher " + to_string(id) + " started eating.\n";

//    static thread_local uniform_int_distribution<> eat(1, 6);
//    this_thread::sleep_for(chrono::milliseconds(eat(rng) * 50));
    chrono::milliseconds eating_time(EATING_TIME);
    this_thread::sleep_for(eating_time);

    cout << "Philosopher " + to_string(id) + " finished eating.\n";
}

void Philosopher::think() {
    cout << "Philosopher " + to_string(id) + " is thinking.\n";
//    static thread_local uniform_int_distribution<> think(1, 6);
//    this_thread::sleep_for(chrono::milliseconds(think(rng) * 100));

    chrono::milliseconds thinking_time(THINKING_TIME);
    this_thread::sleep_for(thinking_time);
}

void Philosopher::dine() {
    while (table.ready) {
        think();
        eat();
    }
}
