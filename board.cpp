#include "board.h"
#include "blip.h"
#include <iostream>
#include "location.h"
using namespace std;

// class constructor
Board::Board(int w, int h)
{
    // allocates space for the grid
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
     // initializes the board
     initBoard();
}

// initializes the board
int Board::initBoard()
{
    //nulls all cells in the board
    for (int y = 0; y<height; y++)
    {
        for (int x = 0; x<width; x++)
        {
            this->grid [x] [y] = NULL;
        }
    }
}
        
        
// return the width of the board
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
        return 102;
    }
}

// check if there's a blip at some location with given id
int Board::checkLocId(int xpos, int ypos)
{
    if(isAllowed(xpos, ypos)==1)
    {
            if (grid [xpos] [ypos] == NULL)
            {
                return 0;
            }
            else
            {
                return grid [xpos] [ypos] -> id;
            }
    }
    else
    {
        return 102;
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
    return 102;
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
    if (isAllowed(newX, newY)== 1 && isAllowed(curX, curY) == 1 && grid [curX] [curY] != NULL)
    {
	Blip* workingBlip = grid [curX] [curY];
	grid [curX] [curY] = NULL;
    grid [newX] [newY] = workingBlip; 
	workingBlip->move(newX, newY); 
    return 1;
    }
    else 
    {
    return 102;
    }
}

// print the grid in a binary fashon
int Board::dev_print_bin()
{
    using namespace std;
    cout << endl << endl << endl;
    cout << getHeight() << endl;
    cout << getWidth () << endl;
    cout << grid [0] [0]-> id << endl;
    
      for (int j=this->getHeight()-1; j>=0 ; j--)
      {
          //cout << j << endl;
          for (int i=0; i<this->getWidth() ; i++)
          {
              //cout << i << endl;
              
              if (grid [i] [j] == NULL)
              {
                   cout << "_";
              }
              
              else
              {
                   cout << "x";
              }
              if (i==(getWidth()-1))
              {
                   cout << endl;
              }
              
              
          }    
      }
      
}

// print the ids of each space in the grid
int Board::dev_print_id()
{
    using namespace std;

      for (int j=this->getHeight()-1; j>=0 ; j--)
      {
          //cout << j << endl;
          for (int i=0; i<this->getWidth() ; i++)
          {
              //cout << i << endl;
              
              if (grid [i] [j] == NULL)
              {
                   cout << "x";
              }
              
              else
              {
                   cout << grid [i] [j]-> id;
              }
              if (i==(getWidth()-1))
              {
                   cout << endl;
              }
              
              
          }    
      }
      
}

// Prints the board much like an ordinary gameboard, with columns labeled by letters and rows denoted by numbers
int Board :: draw_game_board()
{
    char abc [27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    {
    using namespace std;
    cout << endl << endl << endl;
    //cout << getHeight() << endl;
    //cout << getWidth () << endl;
    //cout << grid [0] [0]-> id << endl;
    
    for (int j=this->getHeight(); j>=0 ; j--)
    {
       //cout << j << endl;
       for (int i=0; i<=this->getWidth() ; i++)
       {
           //cout << i << endl;
           if (j == 0)
           {
                cout << abc[i] << " ";
           }
           else if (i == 0 && j<10)
           {
                cout << j << " ";
           }
           
           else if (i == 0 && j>=10)
           {
                cout << j;
           }
           
           
           else if (grid [i-1] [j-1] == NULL)
           {
                cout << "_ ";
           }
           
           else
           {
                cout << grid [i-1] [j-1]->tag << " ";
           }
           if (i==(getWidth()))
           {
                cout << endl << endl;
           }
              
              
       }    
    }
      
}
}

// checks how far the closest blip in a given direction is
int Board::checkClosestDir(Blip* source, int dir)
{
    int curX = source->getX();
    int curY = source->getY();
    int dist = 0;
    bool found = false;
    while (found == false)
    {
        if (inBound(curX, curY) == 0)
        {
           found = true;
        }
        else if (grid[curX][curY] != NULL)
        {
            found = true;
        }
        dist++;        
    
    }
    return dist;
}


// class destructor
Board::~Board()
{
	// insert your code here
}
