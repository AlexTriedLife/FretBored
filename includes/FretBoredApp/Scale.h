//
// Created by alexm on 2025-06-21.
//

#ifndef SCALE_H
#define SCALE_H
#include "IScale.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>


class Scale : public IScale {
public:
    explicit Scale(const std::string& jsonPath);
    ~Scale();
    std::string getName() const override;
    std::vector<std::string> getNotes(std::string &root) const override;

private:
    std::vector<int> m_intervals;
    std::string m_name;




};



#endif //SCALE_H
