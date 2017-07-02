#ifndef _GETGPSCOORDINATE_H
#define _GETGPSCOORDINATE_H



typedef struct GpsCoordinate GpsCoordinate;
struct GpsCoordinate {
  float x;
  float y;   
};
 
//void getGpsCoordinate(GpsCoordinate *gps);

typedef enum {
  GARAGE_DOOR,
  KITCHEN_LIGHT,
  AIRCOND,
  WATER_HEATER,
} Device;

typedef enum {
  OFF,
  ON
} State;

GpsCoordinate getGpsCoordinate();
void turn(Device device, State state);


#endif // _GETGPSCOORDINATE_H
