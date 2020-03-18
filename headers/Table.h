/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */

#ifndef DINING_PHILOSOPHERS_PROBLEM_TABLE_H
#define DINING_PHILOSOPHERS_PROBLEM_TABLE_H


#include <vector>
#include <memory>
#include "Fork.h"

/*! \class Table
    \brief A class that simulates table.

    Table being used while dining.
*/
class Table {
public:
    std::vector< std::unique_ptr<Fork> > forks;
    volatile bool ready;

    Table();
};


#endif //DINING_PHILOSOPHERS_PROBLEM_TABLE_H