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

class RouteTests:public ::testing::Test {
 protected:
    Route *CC1_EB, *CC1_WB, *CC2_EB, *CC2_WB;

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
      CC2_EB = new Route("Campus Connector 1- Eastbound", CC_EB_stops, CC_EB_distances, 6, &CC_EB_generator);
      CC2_WB = new Route("Campus Connector 1- Westbound", CC_WB_stops, CC_WB_distances, 6, &CC_WB_generator);
    }

    virtual void TearDown() {

      delete CC1_EB;
      delete CC1_WB;
      delete CC2_EB;
      delete CC2_WB;

    }
};

//Fix Route constructor depend on iteration1 feedback
TEST_F(RouteTests, constructor){
    Stop stop1(6, 47, -96);
    EXPECT_EQ(CC1_EB->GetName(), "Campus Connector 1- Eastbound");
    EXPECT_EQ(stop1.GetId(), 6);
    EXPECT_EQ(stop1.GetLongitude(), 47);
    EXPECT_EQ(stop1.GetLatitude(), -96);

}

TEST_F(RouteTests, Report_method){
  EXPECT_EQ(CC1_EB->GetName(), "Campus Connector 1- Eastbound");
  EXPECT_EQ(CC1_WB->GetName(), "Campus Connector 1- Westbound");
  EXPECT_EQ(CC2_EB->GetName(),"Campus Connector 1- Eastbound");

}

//Fix Route constructor depend on iteration1 feedback
TEST_F(RouteTests, IsAtEnd_method){
  EXPECT_EQ(CC1_EB->IsAtEnd(), false);
  EXPECT_EQ(CC1_WB->IsAtEnd(), false);

  CC1_EB->ToNextStop();
  CC1_EB->ToNextStop();
  CC1_EB->ToNextStop();
  CC1_EB->ToNextStop();
  EXPECT_EQ(CC1_EB->IsAtEnd(), true);

  CC1_WB->ToNextStop();
  CC1_WB->ToNextStop();
  CC1_WB->ToNextStop();
  CC1_WB->ToNextStop();
  EXPECT_EQ(CC1_WB->IsAtEnd(), true);
}
