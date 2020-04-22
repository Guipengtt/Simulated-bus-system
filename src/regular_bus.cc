
#include <list>

#include "src/regular_bus.h"

RegularBus::RegularBus(std::string name, Route * out, Route * in,
  int capacity, double speed):Bus(name, out, in, capacity, speed) {
    name_ = name;
    outgoing_route_ = out;
    incoming_route_ = in;
    passenger_max_capacity_ = capacity;
    speed_ = speed;
    distance_remaining_ = 0;
    next_stop_ = out->GetDestinationStop();
    unloader_ = new PassengerUnloader;
    loader_ = new PassengerLoader;
}

void RegularBus::Report(std::ostream& out) {
    out << "Name: " << name_ << std::endl;
    out << "Type: " << "regular" << std::endl;
    out << "Speed: " << speed_ << std::endl;
    out << "Distance to next stop: " << distance_remaining_ << std::endl;
    out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
                                        it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
