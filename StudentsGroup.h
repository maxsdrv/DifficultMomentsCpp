#ifndef DIFFICULTMOMENTSCPP_STUDENTSGROUP_H
#define DIFFICULTMOMENTSCPP_STUDENTSGROUP_H

#include <vector>
#include <algorithm>
#include <fstream>

#include "Student.h"
#include "IRepository.h"
#include "IMethods.h"

class StudentsGroup : public IRepository, IMethods{
public:
    explicit StudentsGroup(std::vector<Student> students);
    void Open() override;
    void Save() override;
    double GetAverageScore(const FullName& name) override;
    std::string GetAllInfo(const FullName& name) override;
    std::string GetAllInfo() override;

private:
    std::vector<Student> m_arrayStudents;
};


#endif //DIFFICULTMOMENTSCPP_STUDENTSGROUP_H
