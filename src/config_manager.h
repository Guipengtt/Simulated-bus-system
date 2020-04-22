#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_

#include <vector>
#include <string>


class Route;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
* @brief This class is to manage config
*/
class ConfigManager {
 public:
       /**
       * @brief This is constructor
       */
       ConfigManager();
       /**
       * @brief This class is to deconstructor
       */
       ~ConfigManager();
       /**
       * @brief This function is to read the config.text
       */
       void ReadConfig(const std::string filename);

       std::vector<Route *> GetRoutes() const { return routes; }
 private:
       std::vector<Route *> routes;
};
#endif  // SRC_CONFIG_MANAGER_H_
