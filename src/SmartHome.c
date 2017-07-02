#include "SmartHome.h"
#include "getgpscoordinate.h"
#include <math.h>

GpsCoordinate House = {
	200,
	5345,
};

GpsCoordinate Outside_Garage_Door = {
	220,
	5300,
};

GpsCoordinate Garage = {
	215,
	5300,
};

GpsCoordinate Kitchen = {
	196,
	5400,
};

double distanceFormula(GpsCoordinate x_y){
	return sqrt(pow(x_y.x,2)+pow(x_y.y,2));
}

void doSmartThings(){
	GpsCoordinate gpsC;
	gpsC = getGpsCoordinate();
	
	if ((distanceFormula(gpsC)-distanceFormula(House) <= 2000)){
		
		turn(AIRCOND, ON);
		turn(WATER_HEATER, ON);
		
	}
	if ((distanceFormula(gpsC)-distanceFormula(Outside_Garage_Door) <= 5)&&(distanceFormula(gpsC)!=distanceFormula(Garage))){
		
		turn(GARAGE_DOOR,ON);
		
	}
		if (distanceFormula(gpsC)==distanceFormula(Garage)){
		turn(GARAGE_DOOR,OFF);
		}
	if (distanceFormula(gpsC)==distanceFormula(Kitchen)){
		turn(KITCHEN_LIGHT,ON);
	}
}	
	
	
	