//
// Created by Luiza on 26.04.2026.
//

#ifndef SHARE_THE_BILL_2_0_MENIU_H
#define SHARE_THE_BILL_2_0_MENIU_H

#include<iostream>
#include "Group.h"

class Meniu {

private :
    Group activeGroup;
    bool isRunning;

    void userMenu();
    void expenseMenu();
    void groupMenu();
    void fileMenu();

public:
    Meniu();
    Meniu(const Group& g);
    Meniu( const Meniu& m);
    Meniu& operator=(const Meniu& m);
    ~Meniu();


    friend std::ostream& operator<<(std::ostream& out, const Meniu& m);
    friend std::istream& operator>>(std::istream& in, Meniu& m);


    void run();



};




#endif //SHARE_THE_BILL_2_0_MENIU_H