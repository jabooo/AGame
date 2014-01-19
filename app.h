#ifndef APP_H
#define APP_H
using namespace std;
#include "board.h"
#include "blip.h"

/*
 * No description
 */
class App
{
	public:
		// class constructor
		App();
		// class destructor
		~App();
};

class Sandbox : public App
{
    public:
        // core functionality
        bool core();
};

class Pulse : public App
{
      
    public:
        // core functionality
        bool core();
        
};  

#endif // APP_H
