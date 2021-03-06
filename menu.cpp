// Class automatically generated by Dev-C++ New Class wizard

#include "menu.h" // class's header file

#include <iostream>
using namespace std;
// class constructor
Menu::Menu()
{
	// insert your code here
}

// class destructor
Menu::~Menu()
{
	// insert your code here
}

// core functionality of subclass DevMenu
bool DevMenu::core()
{
bool closeMenu = false;
string input;
Board* boardp;
bool firstTime = true;
    while (closeMenu == 0)
    {
          if (firstTime == false)
          {
              cout << endl << endl << endl << endl;
          }
          else
          {
          firstTime = 0;
          }
          cout << "What would you like to do?" << endl << endl;
          cin >> input;
          if(input == "writestuff")
          {
          
             cout << endl << "What would you like to write?" << endl;
             cin >> input;
             cout << endl << input << endl << endl << "Success!";
          }
          else if(input == "test")
          {
             cout << endl << endl << "___";
          
          }
          else if(input == "close")
          {
             cout << endl << "Closing" <<endl;
             closeMenu = true;
          }   
          else if(input == "createboard")
          {
             int width;
             int height;
             cout << endl << "How big should the board be?" << endl << endl << "Width: ";
             cin >> width;
             cout << endl << "Height: ";
             cin >> height;
             cout << endl << "Creating a " << width << " by " << height << " board...";
             /*
             if (width>10000)
             {
                 cout << endl << "Error, too wide." << endl;
             }
             else if (height> 10000)
             {
                 cout << endl << "Error, too high." << endl;
             }
             else if (width<0)
             {
                 cout << endl << "Error, negative width." << endl;
             }
             else if (height<0)
             {
                 cout << endl << "Error, negative height." << endl;
             }
             else
             {
             */
             boardp = new Board(width, height);
             cout << endl << "Done!";
             //}
          }
          else if(input == "createblip")
          {
             int setid;
             int xloc;
             int yloc;
             cout << endl << endl << "id: ";
             cin >> setid;
             cout << endl << "X coordinate: ";
             cin >> xloc;
             cout << endl << "Y coordinate: ";
             cin >> yloc;
             cout << endl << endl << "Creating a Blip with id " << setid << " at " << xloc << "," << yloc;
             boardp->create_blip(setid, xloc, yloc);
             /*
             cout << endl << endl << "Would you like to check this blip?" << endl << "y/n" << endl << endl;
             cin >> input;
             cout << endl << endl;
             if (input == "y")
             {
                cout << "checking..."<< endl << endl;
                cout << checkBlip(boardp, setid, xloc, yloc)
                if (boardp->checkIfBlipId(setid, xloc, yloc)==1)
                {
                    cout << "Blip here!";
                }
                else if (boardp->checkIfBlipId(setid, xloc, yloc)==0)
                {
                    cout << "Sorry! No blip there.";
                }
                    else if (boardp->checkIfBlipId(setid, xloc, yloc)==3)
                {
                    cout << "Location out of bounds of this board";
                }
             }
             */
          }
          else if (input == "printboard")
          {
              boardp->dev_print_id();
          }
          else if (input == "checklocation")
          {
              int id;
              int xloc;
              int yloc;
              cout << endl << endl << "Where do you want to check?" << endl << endl << "xloc: ";
              cin >> xloc;
              cout << endl << endl << "yloc: ";
              cin >> yloc;
              cout << endl << endl << boardp->checkLocId (xloc, yloc);   
          }
          else if (input == "moveblip")
          {
               int curX;
               int curY;
               int newX;
               int newY;
               cout << endl << endl << "What blip do you want to move?" << endl << endl << "curX: ";
               cin >> curX;
               cout << endl << endl << "curY: ";
               cin >> curY;
               cout << endl << endl << "Where do you want to move it?" << endl << endl << "newX: ";
               cin >> newX;
               cout << endl << endl << "newY: ";
               cin >> newY;
               boardp->move_by_loc(curX, curY, newX, newY);
          }
          else if (input == "shiftblip")
          {
               int curX;
               int curY;
               int dir;
               cout << endl << endl << "What blip do you want to move?" << endl << endl << "curX: ";
               cin >> curX;
               cout << endl << endl << "curY: ";
               cin >> curY;
               cout << endl << endl << "Direction: ";
               cin >> dir;
               boardp->dir_move_by_loc(curX,curY,dir);
          }    
          else if (input == "drawgame")
          {
               boardp->draw_game_board();
          }
          else if (input == "findrange")
          {
               int xpos;
               int ypos;
               int dir;
               cin >> xpos;
               cin >> ypos;
               cin >> dir;
               cout << boardp->checkClosestDir(boardp->grid [xpos] [ypos], dir); 
          }     
          else
          {
             cout << endl << "Input not recognized.";
          }
    }
}

/*
string DevMenu::checkBlip (Board* boardp, int id, int xloc, int yloc)
{
       if (boardp->checkIfBlipId(id, xloc, yloc)==1)
       {
           return "Blip here!";
       }
       else if (boardp->checkIfBlipId(id, xloc, yloc)==0)
       {
           return "Sorry! No blip there.";
       }
       else if (boardp->checkIfBlipId(id, xloc, yloc)==3)
       {
           return "Location out of bounds of this board"
       }
}


*/
