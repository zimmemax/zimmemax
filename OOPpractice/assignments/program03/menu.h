#ifndef MENU_H
#define MENU_H

#include "events.hpp"
#include "bats.hpp"
#include "gold.hpp"
#include "map.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"
/*********************************************************************  
 ** Function:  A class that is for menu
 ** Description: primarily interacts with user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  


class Menu
{
    private:
        string user;
    public:
        Menu();
        void user_interaction(int);
        ~Menu();
};


#endif