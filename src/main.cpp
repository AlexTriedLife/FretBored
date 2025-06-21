#include <iostream>
#include <filesystem>
#include "Scale.h"


int main(int argc, const char * argv[]) {
    std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    Scale major = Scale(R"(data/scales/major.json)");
    Scale minor = Scale(R"(data/scales/minor.json)");
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