//
// Created by mwisniewski on 3/18/20.
//

#include "../headers/Table.h"
#include "../headers/Parameters.h"

Table::Table() {
    for (int i = 0; i < NUMBER_OF_PHILOSOPHERS; i++) {
        forks.emplace_back(new Fork());
    }
}

Table::~Table() {
    forks.clear();
}


