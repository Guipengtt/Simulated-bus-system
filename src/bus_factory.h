/**
 * @file BUS_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "src/bus.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is to generate Bus randomly (small, regular, large)
 */
class BusFactory{
 public:
     /**
     * @brief This function is used to generate a kind of bus
     */
    static Bus* Generate(std::string name, Route* in, Route* out, double speed);
 private:
    static int SizeGeneration();
};
#endif  // SRC_BUS_FACTORY_H_
