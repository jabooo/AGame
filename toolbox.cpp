#include "toolbox.h" // class's header file


// class constructor
Toolbox::Toolbox()
{
	// insert your code here
}

// increments a location in a direction
Location Toolbox::incDir2d(Location loc, int dir, int mag)
{
        int curX = loc.xloc;
        int curY = loc.yloc;
        if (dir == 1)
        {
            curY=curY+mag;
            curX=curX;
        }
        else if (dir == 2)
        {
            curY=curY+mag;
            curX=curX+mag;
        }
        else if (dir == 3)
        {
            curY=curY;
            curX=curX+mag;
        }
        else if (dir == 4)
        {
            curY=curY-mag;
            curX=curX+mag;
        }
        else if (dir == 5)
        {
            curY=curY-mag;
            curX=curX;
        }
        else if (dir == 6)
        {
            curY=curY-mag;
            curX=curX-mag;
        }
        else if (dir == 7)
        {
            curY=curY;
            curX=curX-mag;
        }
        else if (dir == 8)
        {
            curY=curY+mag;
            curX=curX-mag;
        }
        loc.xloc=curX;
        loc.yloc=curY;
        return loc;

    
}

// class destructor
Toolbox::~Toolbox()
{
	// insert your code here
}
