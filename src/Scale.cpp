//
// Created by alexm on 2025-06-21.
//

#include "../includes/FretBoredApp/Scale.h"


Scale::Scale(const std::string &jsonPath) {
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
        if (json.contains("intervals") && json["intervals"].is_array() && json["intervals"].size() > 0) {
            m_intervals = json["intervals"].get<std::vector<int>>();
        }
        // Check if file contains a name
        if (json.contains("name") && json["name"].is_string())  {
            m_name = json["name"].get<std::string>();
        }


    } catch (nlohmann::json::parse_error &e) {
        std::cerr << "json parse_error in file " << jsonPath << ": " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error in file " << jsonPath << ": " << e.what() << std::endl;
    }
}

std::string Scale::getName() const {
    return m_name;

}

std::vector<std::string> Scale::getNotes(std::string &root) const {
    static const std::vector<std::string> chromatic = {
        "C", "C#", "D", "D#", "E", "F",
        "F#", "G", "G#", "A", "A#", "B"
    };

    /*
     *  search for the root note by checking every element from the start of the array to the end of the array
     *  then returning a pointer to the root note which cannot be modified(const_iterator)
    */

   auto it = std::find(chromatic.begin(), chromatic.end(), root);
    // if the iterator is equal to the end of the vector it means that the root note is not in the vector
    if (it == chromatic.end()) {
        std::cerr << "Root note: " << root << " not found" << std::endl;
        return {};
    }

    //  finds the distance(index) of the pointer from the start of the vector
    //  ex: if the root is D the root index will be equal to 2
    const int rootIndex = std::distance(chromatic.begin(), it);

    // Build the scale
    std::vector<std::string> scale;
    for (int interval: m_intervals) {
        // add the index of the next note to the index of the root we use
        // then modulo by the size of the array to prevent out of bounds indexing / wrap around
        int noteIndex = (rootIndex + interval) % chromatic.size();
        scale.push_back(chromatic[noteIndex]);

    }

    return scale;




}

Scale::~Scale() = default;
