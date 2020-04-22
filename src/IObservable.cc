#include <vector>
#include <iterator>

#include "src/IObservable.h"
#include "src/IObserver.h"

void IObservable::RegisterObserver(IObserver* observer) {
    observer_.push_back(observer);
    std::cout << observer_.size() << std::endl;
}

void IObservable::ClearObserver() {
    observer_.clear();
}

void IObservable::NotifyObservers(BusData* info) {
    for (std::vector<IObserver*>::iterator iter = observer_.begin();
    iter != observer_.end(); iter++) {
        (*iter)->Notify(info);
    }
}
