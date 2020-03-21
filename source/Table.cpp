/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */

#include "../headers/Table.h"
#include "../headers/Parameters.h"

Table::Table() {
    no_of_ready_philosophers = 0;
    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        forks.emplace_back(new Fork());
    }
}

Table::~Table() {
    forks.clear();
}

void Table::wait_for_all() {
    std::unique_lock<std::mutex> lk(cv_m);
    no_of_ready_philosophers++;
    cv.wait(lk, [&] { return no_of_ready_philosophers >= NUMBER_OF_PHILOSOPHERS; });
    cv.notify_all();
}


