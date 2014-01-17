#ifndef MENU_H
#define MENU_H
using namespace std;
#include "board.h"
#include "blip.h"

/*
An attempt at classification of generic int responses
0: Failure
1: Success
2: Referenced object does not exist
3: Location out of bounds


/*
 * No description
 */
class Menu
{
	public:
		// class constructor
		Menu();
		// class destructor
		~Menu();
		// core functionality
};

class DevMenu : public Menu
{
    public:
        // core functionality
        bool core();
        // checks for a blip at a given location
        //string checkBlip (Board* boardp, int id, int xloc, int yloc);
};

#endif // MENU_H
