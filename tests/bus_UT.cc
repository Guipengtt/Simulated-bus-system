
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/bus.h"
#include "../src/stop.h"
#include "../src/passenger.h"
#include "../src/route.h"
#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/random_passenger_generator.h"

using namespace std;

class BusTests: public :: testing:: Test {
  protected:
    Bus *bus1, *bus2, *bus3;
    Route *CC1_EB, *CC1_WB, *CC2_EB, *CC2_WB;
    Passenger *p1, *p2, *p3;

    virtual void SetUp(){

      //THIS PART IS FROM bus_driver.cc file

      Stop ** CC_EB_stops = new Stop *[3];
      Stop ** CC_WB_stops = new Stop *[3];
      std::list<Stop *> CC_EB_stops_list;
      std::list<Stop *> CC_WB_stops_list;

      //Eastbound stops
      Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
      Stop stop_CC_EB_2(1); //student union station
      Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave

      //Westbound stops
      Stop stop_CC_WB_1(6, 47, -96); //st paul 2
      Stop stop_CC_WB_2(7, 46, -95); //st paul 1
      Stop stop_CC_WB_3(8, 45, -94); //before transit


      CC_EB_stops_list.push_back(&stop_CC_EB_1);
      CC_EB_stops[0] = &stop_CC_EB_1;
      CC_EB_stops_list.push_back(&stop_CC_EB_2);
      CC_EB_stops[1] = &stop_CC_EB_2;
      CC_EB_stops_list.push_back(&stop_CC_EB_3);
      CC_EB_stops[2] = &stop_CC_EB_3;


      CC_WB_stops_list.push_back(&stop_CC_WB_1);
      CC_WB_stops[0] = &stop_CC_WB_1;
      CC_WB_stops_list.push_back(&stop_CC_WB_2);
      CC_WB_stops[1] = &stop_CC_WB_2;
      CC_WB_stops_list.push_back(&stop_CC_WB_3);
      CC_WB_stops[2] = &stop_CC_WB_3;


      double * CC_EB_distances = new double[2];
      double * CC_WB_distances = new double[2];
      CC_EB_distances[0] = 5;
      CC_EB_distances[1] = 4;


      CC_WB_distances[0] = 6;
      CC_WB_distances[1] = 10;



      list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
      CC_EB_probs.push_back(.15); //WB
      CC_EB_probs.push_back(.3); //CMU
      CC_EB_probs.push_back(.025); //O&W
      CC_EB_probs.push_back(.05); //Pre-transit
      CC_EB_probs.push_back(.05); //STP 1
      CC_EB_probs.push_back(0); //STP 1
      //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
      //        remove possibility of generating passengers with nowhere to go
      list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
      CC_WB_probs.push_back(.35); //stp 2
      CC_WB_probs.push_back(.05); //stp 1
      CC_WB_probs.push_back(.01); //post-transit
      CC_WB_probs.push_back(.01); //O&W
      CC_WB_probs.push_back(.02); //CMU
      CC_WB_probs.push_back(0); //WB

      RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
      RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);

      CC1_EB = new Route("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 3, &CC_EB_generator);
      CC1_WB = new Route("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 3, &CC_WB_generator);
      CC2_EB = new Route("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 3, &CC_EB_generator);
      CC2_WB = new Route("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 3, &CC_WB_generator);
    }

    virtual void TearDown() {

      delete CC1_EB;
      delete CC1_WB;
      delete CC2_EB;
      delete CC2_WB;
      p1 = NULL;
      p2 = NULL;
      p3 = NULL;
      bus1 = NULL;
      bus2 = NULL;
      bus3 = NULL;

    }

};

//Fix constructor test base on the feedback of iteration 1
TEST_F(BusTests, Constructor){
  bus1 = new Bus("B1", CC1_EB, CC1_WB);
  bus2 = new Bus("B2", CC2_EB, CC2_WB, 30);

  EXPECT_EQ(bus1->GetName(), "B1");
  EXPECT_EQ(bus2->GetName(), "B2");
  EXPECT_EQ(bus1->GetCapacity(), 60);
  EXPECT_EQ(bus2->GetCapacity(), 30);
  EXPECT_EQ(bus1->GetNumPassengers(), 0);
  EXPECT_EQ(bus2->GetNumPassengers(), 0);
}

TEST_F(BusTests, IsTripComplete_Method){

  bus1 = new Bus("B1", CC1_EB, CC1_WB);
  bus2 = new Bus("B2", CC2_EB, CC2_WB);

  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);

  bus1->GetNextStop();
  bus1->GetNextStop();
  EXPECT_EQ(bus1->IsTripComplete(), false);
}


TEST_F(BusTests, LoadPassenger_Method){
  bus1 = new Bus("B1", CC1_EB, CC1_WB);
  bus2 = new Bus("B2", CC1_EB, CC1_WB, 0);
  p1 = new Passenger();
  EXPECT_EQ(bus1->GetCapacity()>0, true);
  EXPECT_EQ(bus1->LoadPassenger(p1), true);

  EXPECT_EQ(bus2->GetCapacity()>0, false);
  EXPECT_EQ(bus2->LoadPassenger(p1), false);
}

TEST_F(BusTests, Move_method){

  bus1 = new Bus("B1", CC1_EB, CC1_WB, 3, 6);
  bus2 = new Bus("B1", CC2_EB, CC2_WB, 4, 0);
  EXPECT_EQ(bus1->GetNextStop() != NULL, true);
  EXPECT_EQ(bus2->GetNextStop() != NULL, true);
  EXPECT_EQ(bus1->GetNextStop() == NULL, false);
  EXPECT_EQ(bus2->GetNextStop() == NULL, false);

}

TEST_F(BusTests, Update_Method){

  bus1 = new Bus("B1", CC1_EB, CC1_WB);
  bus2 = new Bus("B1", CC2_EB, CC2_WB);

  bus1->Update();

  EXPECT_EQ(bus1->Move(), true);
  EXPECT_EQ(bus2->Move(), false);
}
