#include <iostream>
#include <filesystem>
#include "Scale.h"
#include "Instrument.h"

void testScale() {
    const Scale major = Scale(R"(data/scales/major.json)");
    const Scale minor = Scale(R"(data/scales/minor.json)");
    std::string root = "C#";
    std::vector<std::string> majorNotes = major.getNotes(root);
    std::vector<std::string> minorNotes = minor.getNotes(root);
    std::cout << root << " " << major.getName() << " scale:" << std::endl;
    for (const std::string& note : majorNotes) {
        std::cout << note << "\n";
    }
    std::cout << root << " " << minor.getName() << " scale:" << std::endl;
    for (const std::string& note : minorNotes) {
        std::cout << note << "\n";
    }
}
void testInstrument() {
    const Instrument guitar(R"(data/instruments/guitar.json)");
    const Instrument bass(R"(data/instruments/bass.json)");
    std::string tuning_name = "Standard";
    auto guitarTuning = guitar.getTuning(tuning_name);
    auto bassTuning = bass.getTuning(tuning_name);

    for (std::string& note: guitarTuning) {
        std::cout << note << "\n";
    }
    for (std::string& note: bassTuning) {
        std::cout << note << "\n";
    }

}

int main(int argc, const char * argv[]) {
    std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    testScale();
    testInstrument();


}