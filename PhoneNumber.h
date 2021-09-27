#ifndef DIFFICULTMOMENTSCPP_PHONENUMBER_H
#define DIFFICULTMOMENTSCPP_PHONENUMBER_H

#include "stdfax.h"


class PhoneNumber {
public:
    PhoneNumber(int countryCode, int towCode, std::string number, std::optional<int> addNumber = 0);

    /*Getters and Setters*/
    [[nodiscard]] int getCountryCode() const;
    [[nodiscard]] int getTownCode() const;
    [[nodiscard]] const std::string& getNumber() const;
    [[nodiscard]] std::optional<int> getAddNumber() const;
    void setCountryCode(int code);
    void setTownCode(int code);
    void setNumber(std::string number);

    friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& pN);
private:
    int m_countryCode;
    int m_townCode;
    std::string m_Number;
    std::optional<int> m_addNumber;
};


#endif //DIFFICULTMOMENTSCPP_PHONENUMBER_H
