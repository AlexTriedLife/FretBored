//
// Created by alexm on 2025-06-21.
//

#include "Instrument.h"

Instrument::Instrument(const std::string &jsonPath) {
    // input file stream
    std::fstream ifs(jsonPath);
    if (!ifs) {
        std::cerr << "Error opening file " << jsonPath << std::endl;
        return;
    }
    try {
        nlohmann::json json;
        ifs >> json;

        // Check if file contains a populated array called intervals
        if (json.contains("string_count") && json["string_count"].is_number_unsigned()) {
            m_string_count = json["string_count"].get<unsigned int>();
        }
        // Check if json file has a key called name
        if (json.contains("name") && json["name"].is_string()) {
            m_name = json["name"].get<std::string>();
        }
        if (json.contains("tuning") && json["tuning"].is_object()) {
            for (auto &[tuningName, tuningArray]: json["tuning"].items()) {
                if (tuningArray.is_array()) {
                    // the current tuning ex: (tuningName)"E-standard": (tuningArray){"E","A","D","G","B","E"}
                    std::vector<std::string> tuning;
                    for (const auto& note : tuningArray) {
                        tuning.push_back(note.get<std::string>());
                    }
                    m_tuning[tuningName] = tuning;
                }

            }
        }
    } catch (nlohmann::json::parse_error &e) {
        std::cerr << "json parse_error in file " << jsonPath << ": " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error in file " << jsonPath << ": " << e.what() << std::endl;
    }
}

std::string Instrument::getName() const {
    return m_name;
}


unsigned int Instrument::getStringCount() const {
    return m_string_count;
}

std::vector<std::string> Instrument::getTuning(std::string &tuningName) const {
    return m_tuning.at(tuningName);
}

Instrument::~Instrument() = default;


