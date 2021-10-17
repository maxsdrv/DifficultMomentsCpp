#ifndef DIFFICULTMOMENTSCPP_IMETHODS_H
#define DIFFICULTMOMENTSCPP_IMETHODS_H

#include <string>

#include "FullName.h"

class IMethods {
    virtual double GetAverageScore(const FullName& name) = 0;
    virtual std::string GetAllInfo(const FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

#endif //DIFFICULTMOMENTSCPP_IMETHODS_H
