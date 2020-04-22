
#include "visualization_simulator.h"

#include "bus.h"
#include "route.h"
#include "bus_factory.h"
#include "IObservable.h"

bool flag = true;

VisualizationSimulator::VisualizationSimulator(WebInterface* webI, ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {

}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings, const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);
        
        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }

}

void VisualizationSimulator::Update() {

    if(flag == true){
   
        simulationTimeElapsed_++;

        std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
        std::cout << "~~~~~~~~~~" << std::endl;

        std::cout << "~~~~~~~~~~ Generating new busses if needed ";
        std::cout << "~~~~~~~~~~" << std::endl;

    

        // Check if we need to generate new busses
        for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
            // Check if we need to make a new bus
            if (0 >= timeSinceLastBus_[i]) {

                Route * outbound = prototypeRoutes_[2 * i];
                Route * inbound = prototypeRoutes_[2 * i + 1];

                // busses_.push_back(new Bus(std::to_string(busId), outbound->Clone(), inbound->Clone(), 60, 1));
                busses_.push_back(BusFactory::Generate(std::to_string(busId), outbound->Clone(), inbound->Clone(), 1));
                busId++;
                
                timeSinceLastBus_[i] = busStartTimings_[i];
            } else {
                timeSinceLastBus_[i]--;
            }
        }

        
        std::cout << "~~~~~~~~~ Updating busses ";
        std::cout << "~~~~~~~~~" << std::endl;


        // Update busses
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
            busses_[i]->Update();

            if (busses_[i]->IsTripComplete()) {
                webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
                busses_.erase(busses_.begin() + i);
                continue;
            }
            webInterface_->UpdateBus(busses_[i]->GetBusData());

            busses_[i]->Report(std::cout);
        }


        std::cout << "~~~~~~~~~ Updating routes ";
        std::cout << "~~~~~~~~~" << std::endl;
        // Update routes
        for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
            prototypeRoutes_[i]->Update();

            webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

            prototypeRoutes_[i]->Report(std::cout);
        }

    }

}

void  VisualizationSimulator::TogglePause() {
    std::cout << "++++++++++ Pausing ";
    std::cout << "++++++++++" << std::endl;
    if(flag == true){
        flag = false;
    } else{
        flag = true;
    }
}

void VisualizationSimulator::AddListener(std::string* id_, IObserver* bo) {
    std::cout << "******* Add Listener";
    std::cout<< " *******" << std::endl;
    for (std::vector<Bus*>::iterator iter = busses_.begin(); iter!=busses_.end(); iter++) {
        if((*iter)->GetBusData().id == (*id_)) {
            (*iter)->RegisterObserver(bo);
        }
    }
}

void VisualizationSimulator::ClearListeners() {
    std::cout << "******* Clean Listener";
    std::cout<< " *******" << std::endl;
    for (std::vector<Bus*>::iterator iter = busses_.begin(); iter!=busses_.end(); iter++) {
        (*iter) -> ClearObserver();
    }

}