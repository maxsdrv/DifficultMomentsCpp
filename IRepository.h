#ifndef DIFFICULTMOMENTSCPP_IREPOSITORY_H
#define DIFFICULTMOMENTSCPP_IREPOSITORY_H

class IRepository {
    virtual void Open() = 0;
    virtual void Save() = 0;
};

#endif //DIFFICULTMOMENTSCPP_IREPOSITORY_H
