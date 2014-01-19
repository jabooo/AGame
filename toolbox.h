#ifndef TOOLBOX_H
#define TOOLBOX_H
#include "location.h"


class Toolbox
{
	public:
		// class constructor
		Toolbox();
		// increments a location in a direction by a magnitude
		Location incDir2d(Location loc, int dir, int mag);
		// class destructor
		~Toolbox();
};

#endif // TOOLBOX_H
