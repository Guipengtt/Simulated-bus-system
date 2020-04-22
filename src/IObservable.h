
#include <vector>

#include "src/IObserver.h"
#include "src/bus.h"

#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
  * @brief This is a concrete class which equal as ISubject class in observer
  * Pattern. It provides mutiple methond to add, clear and update observers.
  */
class IObservable {
 public:
    /**
    * @brief This function is to add observer to observer_
    * vector.
    */
    void RegisterObserver(IObserver*);
    /**
    * @brief This function is to clear all observers.
    */
    void ClearObserver();
    /**
    * @brief This function is to Update observers.
    */
    void NotifyObservers(BusData*);

 private:
    std::vector<IObserver*> observer_;
};
#endif  // SRC_IOBSERVABLE_H_
