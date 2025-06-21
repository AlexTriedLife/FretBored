//
// Created by alexm on 2025-06-21.
//

#ifndef ISCALE_H
#define ISCALE_H
#include <string>
#include <vector>

class IScale {
    public:
    virtual ~IScale() = default;
    virtual std::string getName() const = 0;
    virtual std::vector<std::string> getNotes(std::string &root) const = 0;
};

#endif //ISCALE_H
