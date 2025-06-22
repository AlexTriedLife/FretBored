//
// Created by alexm on 2025-06-21.
//

#ifndef IINSTRUMENT_H
#define IINSTRUMENT_H
#include <string>
#include <vector>

class IInstrument {
public:
    virtual ~IInstrument() = default;
    virtual std::string getName() const = 0;
    virtual unsigned int getStringCount() const = 0;
    virtual std::vector<std::string> getTuning(std::string& tuningName) const = 0;

};

#endif //IINSTRUMENT_H
