Smart Home Systems Assignment
----------

Your task is to create a smart home system (SHM) which will facilitate the residents through automation. The system will use the smartphone GPS (which everybody
carries around most of the time) to locate the user (imagine the smartphone always send the GPS location to the smart home system). 

For example, when you drive back home. As you reach the vicinity of the house (within 2km radius), the SHM will turn on both the aircond and the water heater. 
As you reach 5 meters away from outside the garage door, the SHM will open it to allow you to park. As you park, the garage will automatically shut the door. 
As you walk to the kitchen, the light will automatically turned on.

Assume you don't have the GPS device and you have not decided which GPS chip to use. But you know the GPS has the following common GPS API:
```
typedef struct GpsCoordinate GpsCoordinate;
struct GpsCoordinate {
  float x;
  float y;   
};
 
void getGpsCoordinate(GpsCoordinate *gps);
```
Implement the main function of the SHM called `doSmartThings()`. The function calls the GPS function given to find out the location of the owner and do the 
smart things explained above. Assume the house is located at `x=200, y=5345`. The outside garage door is at `x=220, y=5300`. The center of the garage is
 `x=215, y=5300` (5m radius). And the center of the kitchen is `x=196, y=5400` (50m radius). 

You have the following API for smart home control:
```
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

void turn(Device device, State state);

Eg. turn(KITCHEN_LIGHT, ON);
    turn(WATER_HEATER, OFF);
```
Mock the following functions
```
void getGpsCoordinate(GpsCoordinate *gps);
void turn(Device device, State state);
```
