//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_STATES_H
#define FELICIACHENCS3AFINAL_STATES_H
#include <map>
#include "statesEnum.h"

class States {
private:
    std::map<statesEnum, bool> map;
    void load();
public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state);
};


#endif //FELICIACHENCS3AFINAL_STATES_H
