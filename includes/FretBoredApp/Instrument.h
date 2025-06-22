//
// Created by alexm on 2025-06-21.
//

#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <cstdint>

#include "IInstrument.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>



class Instrument : public IInstrument {
    public:
    explicit Instrument(const std::string& jsonPath);
    std::string getName() const override;
    unsigned int getStringCount() const override;
    std::vector<std::string> getTuning(std::string &tuningName) const override;
    ~Instrument();
private:
    unsigned int m_string_count;
    std::string m_name;
    std::map<std::string, std::vector<std::string>> m_tuning;



};



#endif //INSTRUMENT_H
