
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_interface.h"
#include "config_manager.h"
#include "IObserver.h"

class Route;
class Bus;
class Stop;


class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Update();
        void TogglePause();
        void AddListener(std::string*, IObserver*);
        void ClearListeners();

    private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;
        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;

        int busId = 1000;
};

#endif // VISUALIZATION_SIMULATOR_H_
