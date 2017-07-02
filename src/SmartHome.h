#ifndef _SMARTHOME_H
#define _SMARTHOME_H
#include "getgpscoordinate.h"

GpsCoordinate getGpsCoordinate();
double distanceFormula(GpsCoordinate x_y);
void doSmartThings();

#endif // _SMARTHOME_H
