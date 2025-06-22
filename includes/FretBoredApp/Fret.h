//
// Created by alexm on 2025-06-21.
//

#ifndef FRET_H
#define FRET_H
#include <string>

#include "IFret.h"



class Fret : public IFret {
    public:
    explicit Fret(unsigned int stringIndex, unsigned int fretNumber,const std::string& OpenStringNote);
    unsigned int getStringIndex() const override;
    unsigned int getFretNumber() const override;
    std::string getNoteName() const override;
    ~Fret();

private:
    unsigned int m_stringIndex{};
    unsigned int m_fretNumber{};
    std::string m_openStringNote;

};



#endif //FRET_H
