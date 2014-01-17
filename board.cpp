#include "board.h"
#include "blip.h"
#include <iostream>
using namespace std;

// class constructor
Board::Board(int w, int h)
{
    //allocate space for the grid
    {
        Blip** col;
        col = new Blip* [h];
	    grid = new Blip** [h];
	    for (int i=0; i<h ; i++)
	    {
            grid [i] = new Blip* [w];
        }
        width = w;
        height = h;
     }
}

//  return the width of the board
int Board::getWidth()
{
    return width;
}

// return the height of the board
int Board::getHeight()
{
    return height;
}

// check if given coordinates are allowed to have the given action performed on them
int Board::isAllowed(int xpos, int ypos)
{
    if (inBound(xpos, ypos) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// check if given coordinates are within the parameters of the board
int Board::inBound(int xpos, int ypos)
{
    if (xpos < width)
    {
       if(ypos < height)
       {
           return 1;
       }
       else
       {
           return 0;
       }
    }
    else
    {
        return 0;
    }
}

// creating a blip
int Board::create_blip(int id,int xpos, int ypos)
{
    if(isAllowed(xpos, ypos)==1)
    {
        grid [xpos] [ypos] = new Blip(this, id, xpos, ypos);        
        return 1;
    }
    else
    {
        return 3;
    }
}

// check if there's a blip at some location with given id
int Board::checkIfBlipId(int id, int xpos, int ypos)
{
    if(isAllowed(xpos, ypos)==1)
    {
            if (grid [xpos] [ypos]->id == id)
            {
                return 1;
            }
            else
            {
                return 0;
            }        
    }
    else
    {
        return 3;
    }
}

// Move a Blip by its pointer id
int Board::move_by_id(Blip* someBlip, int newX, int newY)
{
    if (isAllowed(newX, newY)==1)
    {
	grid[someBlip->xloc][someBlip->yloc] = NULL;
	grid[newX][newY] = someBlip;
	someBlip->move(newX, newY);
	return 1;
    }
    else
    return 0;
}

// Move a Blip by its coordinates
int Board::move_by_loc(int curX, int curY, int newX, int newY)
{
    if (inBound(newX, newY)==1)
    {
	Blip* workingBlip = grid [curX] [curY];
	grid [curX] [curY] = NULL;
    grid [newX] [newY] = workingBlip; 
	workingBlip->move(newX, newY); 
    return 1; 
    }        
}

// Directional movement of a blip by coordinates
int Board::dir_move_by_loc(int curX, int curY, int dir)
{
    int newX;
    int newY;
    if (dir == 1)
    {
        newY=curY+1;
        newX=curX;
    }
    if (dir == 2)
    {
        newY=curY+1;
        newX=curX+1;
    }
    if (dir == 3)
    {
        newY=curY;
        newX=curX+1;
    }
    if (dir == 4)
    {
        newY=curY-1;
        newX=curX+1;
    }
    if (dir == 5)
    {
        newY=curY-1;
        newX=curX;
    }
    if (dir == 6)
    {
        newY=curY-1;
        newX=curX-1;
    }
    if (dir == 7)
    {
        newY=curY;
        newX=curX-1;
    }
    if (dir == 8)
    {
        newY=curY+1;
        newX=curX-1;
    }
    if (isAllowed(newX, newY)==1)
    {
	Blip* workingBlip = grid [curX] [curY];
	grid [curX] [curY] = NULL;
    grid [newX] [newY] = workingBlip; 
	workingBlip->move(newX, newY); 
    return 1; 
    }
}

// print the grid
int Board::dev_print_bin()
{
    using namespace std;
    cout << endl << endl << endl;
      for (int i=0; i<this->getHeight() ; i++)
      {
          for (int j=0; i<this->getWidth() ; i++)
          {
              if (grid [j] [i]->id == 1)
              {
                   cout << "|";
              }
              else
              {
                   cout << "_";
              }
              if (j==(width-1))
              {
                   cout << endl;
              }
          }    
      }
}


// class destructor
Board::~Board()
{
	// insert your code here
}
