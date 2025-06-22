//
// Created by alexm on 2025-06-21.
//

#ifndef IFRET_H
#define IFRET_H

class IFret {
    public:
    virtual ~IFret() = default;
    // Index of the string since there is no such thing as the 0 string
    virtual unsigned int getStringIndex() const = 0;
    // number of the fret since 0 is a valid fret number
    virtual unsigned int getFretNumber() const = 0;


    // note of the fret this object is representing
    virtual std::string getNoteName() const = 0;
};

#endif //IFRET_H
