/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */

#ifndef DINING_PHILOSOPHERS_PROBLEM_TABLE_H
#define DINING_PHILOSOPHERS_PROBLEM_TABLE_H


#include <vector>
#include <memory>
#include <condition_variable>
#include "Fork.h"

/*! \class Table
    \brief A class that simulates table.

    Table being used while dining.
*/
class Table {
private:
    std::condition_variable cv;
    std::mutex cv_m;

public:
    std::vector< std::unique_ptr<Fork> > forks;
    volatile int no_of_ready_philosophers;

    Table();
    ~Table();
    void wait_for_all();
};


#endif //DINING_PHILOSOPHERS_PROBLEM_TABLE_H
