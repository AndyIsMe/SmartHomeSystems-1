#include "unity.h"
#include "SmartHome.h"
#include "mock_getgpscoordinate.h"


void setUp(void){}
void tearDown(void){}

GpsCoordinate within_2000_HouseC = {
	220,
	5400,
};

GpsCoordinate within_5_Outside_Garage_Door = {
	218,
	5298,
};

GpsCoordinate Exactly_At_Garage = {
	215,
	5300,
};

GpsCoordinate Exactly_At_Kitchen = {
	196,
	5400,
};



void test_smarthome_when_within_radius_of_2km_expect_Aircond_and_WaterHeater_turnOn(void)
{
		getGpsCoordinate_ExpectAndReturn(within_2000_HouseC);
		turn_Expect(AIRCOND, ON);
		turn_Expect(WATER_HEATER, ON);
		doSmartThings();
    
}

void test_smarthome_when_within_radius_of_5m_expect_GarageDoor_open(void){
	getGpsCoordinate_ExpectAndReturn(within_5_Outside_Garage_Door);
	turn_Expect(AIRCOND, ON);
	turn_Expect(WATER_HEATER, ON);
	turn_Expect(GARAGE_DOOR, ON);
	doSmartThings();

}

void test_smarthome_when_the_car_is_exactly_at_Garage(void){
	getGpsCoordinate_ExpectAndReturn(Exactly_At_Garage);
	turn_Expect(AIRCOND, ON);
	turn_Expect(WATER_HEATER, ON);
	turn_Expect(GARAGE_DOOR, OFF);
	doSmartThings();

}

void test_smarthome_when_user_is_exactly_at_the_kitchen(void){
	getGpsCoordinate_ExpectAndReturn(Exactly_At_Kitchen);
	turn_Expect(AIRCOND, ON);
	turn_Expect(WATER_HEATER, ON);
	turn_Expect(KITCHEN_LIGHT, ON);
	doSmartThings();

}




