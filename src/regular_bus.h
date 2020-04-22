
#ifndef SRC_REGULAR_BUS_H_
#define SRC_REGULAR_BUS_H_

#include <string>

#include "src/bus.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to create regular bus
 */
class RegularBus: public Bus{
 public:
      /**
       * @brief This is constuctor
       */
      RegularBus(std::string name, Route * out, Route * in, int capacity = 60,
                                          double speed = 1);
      /**
       * @brief This is function is to report information
       */
      void Report(std::ostream& out);
};
#endif  // SRC_REGULAR_BUS_H_
