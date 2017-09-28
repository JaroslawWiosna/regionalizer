/**
 * \class Coordinates
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "Coordinates.hpp"

Coordinates::Coordinates(geo_location width,geo_location length)
        : width(width),length(length){
/*
    width.total_deegres_value=width.degrees+float(width.minutes)/60+float(width.seconds)/3600;
    length.total_deegres_value=length.degrees+float(length.minutes)/60+float(length.seconds)/3600;
*/
}

float Coordinates::distanceFrom(Coordinates differentCity){
/*
	float distance=0;
	float distance_width=0,distance_length=0;
	distance_width=(width.total_deegres_value)-((differentCity.width.total_deegres_value);	
	distance_length=(length.total_deegres_value)-(differentCity.length.total_deegres_value);
	distance=sqrt(pow(distance_width,2)+distance_length,2))*111,3;
	return distance;
*/
	return 0;
}
