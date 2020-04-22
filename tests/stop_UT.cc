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

class StopTests: public :: testing:: Test{
protected:
  Stop *s1, *s2, *s3;
  Passenger *p1;
  virtual void SetUp(){
    p1 = new Passenger(2, "Jackie");
  }
  virtual void TearDown(){
    delete p1;
  }

};

TEST_F(StopTests, constructor){
  s1 = new Stop(2);
  s2 = new Stop(4, 23.29823, -23.438348);
  EXPECT_EQ(s1->GetId(), 2);
  EXPECT_EQ(s2->GetId(), 4);
}

TEST_F(StopTests, GetId_Method){
  s1 = new Stop(8);
  s2 = new Stop(9);

  EXPECT_EQ(s1->GetId(), 8);
  EXPECT_EQ(s2->GetId(), 9);
}

TEST_F(StopTests, GetLongitude_method){
  s1 = new Stop(2);
  s2 = new Stop(4, 23.29823, -23.438348);

  EXPECT_EQ(s1->GetLongitude(), 44.973723);
  EXPECT_EQ(s2->GetLongitude(), 23.29823);

}

TEST_F(StopTests, GetLatitude_method){
  s1 = new Stop(2);
  s2 = new Stop(4, 23.29823, -23.438348);

  EXPECT_EQ(s1->GetLatitude(), -93.235365);
  EXPECT_EQ(s2->GetLatitude(), -23.438348);

}
