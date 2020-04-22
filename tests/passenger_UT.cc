/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};


TEST_F(PassengerTests, Update_Method_Test){
  passenger = new Passenger();
  passenger -> Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
  passenger -> GetOnBus();
  EXPECT_EQ(passenger->GetTotalWait(), 2);
};

TEST_F(PassengerTests, GetOnBus_Method_Test){
  passenger = new Passenger();
  passenger1 = new Passenger();
  passenger2 = new Passenger();

  passenger -> GetOnBus();
  passenger1 -> GetOnBus();
  passenger2 -> GetOnBus();

  EXPECT_EQ(passenger->GetTotalWait(), 1);
  EXPECT_EQ(passenger1->GetTotalWait(), 1);
  EXPECT_EQ(passenger2->GetTotalWait(), 1);
};

TEST_F(PassengerTests, GetTotalWait_Method_Test){
  passenger = new Passenger();
  passenger1 = new Passenger();
  passenger2 = new Passenger();

  passenger -> GetOnBus();
  for(int i = 0; i < 3; i++){
    passenger -> Update();
  }

  passenger1 -> GetOnBus();
  for(int i = 0; i < 6; i++){
    passenger1 -> Update();
  }

  for(int i = 0; i < 4; i++){
    passenger2 -> Update();
  }

  EXPECT_EQ(passenger->GetTotalWait(), 4);
  EXPECT_EQ(passenger1->GetTotalWait(), 7);
  EXPECT_EQ(passenger2->GetTotalWait(), 4);

}

TEST_F(PassengerTests, IsOnBus_Method_Test){
  passenger = new Passenger();
  passenger1 = new Passenger();
  passenger2 = new Passenger();

  passenger1 -> GetOnBus();
  passenger2 -> Update();

  EXPECT_EQ(passenger->IsOnBus(), false);
  EXPECT_EQ(passenger1->IsOnBus(), true);
  EXPECT_EQ(passenger2->IsOnBus(), false);
}

TEST_F(PassengerTests, GetDestination){
  passenger = new Passenger(2, "jack");
  passenger1 = new Passenger(3, "Charlie");
  passenger2 = new Passenger(5, "Kernel");

  EXPECT_EQ(passenger->GetDestination(), 2);
  EXPECT_EQ(passenger1->GetDestination(), 3);
  EXPECT_EQ(passenger2->GetDestination(), 5);

}

TEST_F(PassengerTests, Report){
  passenger = new Passenger(2, "jack");
  passenger1 = new Passenger(3, "Charlie");
  passenger2 = new Passenger(5, "Kernel");


  string expected_output = "Name: jack";
  string expected_output1 = "Name: Charlie";
  string expected_output2 = "Name: Kernel";

  testing::internal::CaptureStdout();
  passenger -> Report(std::cout);
  string output = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger1 -> Report(std::cout);
  string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger2 -> Report(std::cout);
  string output2 = testing::internal::GetCapturedStdout();

  int p1 = output.find(expected_output);
  int p2 = output1.find(expected_output1);
  int p3 = output2.find(expected_output2);

  EXPECT_EQ(p1, 0);
  EXPECT_EQ(p2, 0);
  EXPECT_EQ(p3, 0);
}

