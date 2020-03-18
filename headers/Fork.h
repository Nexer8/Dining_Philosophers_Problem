/*!
 *  \author    Mariusz Wiśniewski
 *  \date      3/18/20
 */

#ifndef DINING_PHILOSOPHERS_PROBLEM_FORK_H
#define DINING_PHILOSOPHERS_PROBLEM_FORK_H


#include <mutex>

/*! \class Fork
    \brief A class that simulates fork.

    Forks being used while dining.
*/
class Fork {
public:
    std::mutex mutex;
};


#endif //DINING_PHILOSOPHERS_PROBLEM_FORK_H
