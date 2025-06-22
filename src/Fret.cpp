//
// Created by alexm on 2025-06-21.
//

#include "../includes/FretBoredApp/Fret.h"
#include "../includes/FretBoredApp/Chromatic.h"
#include "../includes/FretBoredApp/Enharmonic.h"
#include <algorithm>

Fret::Fret(unsigned int stringIndex, unsigned int fretNumber,
           const std::string &OpenStringNote) : m_stringIndex(stringIndex), m_fretNumber(fretNumber),
                                                m_openStringNote(OpenStringNote) {}

unsigned int Fret::getStringIndex() const {
    return m_stringIndex;
}

unsigned int Fret::getFretNumber() const {
    return m_fretNumber;
}

std::string Fret::getNoteName() const {
    auto it = std::find(CHROMATIC_SCALE.begin(), CHROMATIC_SCALE.end(),m_openStringNote);
    if (it == CHROMATIC_SCALE.end()) {
        return "invalid note";
    }
    // the index of the open string note in the chromatic scale
    int openNoteIndex = std::distance(CHROMATIC_SCALE.begin(), it);
    int noteIndex = (openNoteIndex + m_fretNumber) % CHROMATIC_SCALE_SIZE;
    return CHROMATIC_SCALE[noteIndex];
}

Fret::~Fret() = default;
