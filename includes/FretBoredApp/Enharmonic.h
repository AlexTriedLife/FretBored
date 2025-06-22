//
// Created by alexm on 2025-06-21.
//

#ifndef ENHARMONIC_H
#define ENHARMONIC_H

#include <unordered_map>
#include <string>

inline const std::unordered_map<std::string, std::string> ENHARMONIC_EQUIVALENTS = {
    {"Db", "C#"}, {"Eb", "D#"}, {"Gb", "F#"},
    {"Ab", "G#"}, {"Bb", "A#"},
    {"Cb", "B"},  {"Fb", "E"},
    {"E#", "F"},  {"B#", "C"}
};


#endif // ENHARMONIC_H

