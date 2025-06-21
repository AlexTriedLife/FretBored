#include <iostream>
#include <filesystem>
#include "Scale.h"


int main(int argc, const char * argv[]) {
    std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
    Scale major = Scale(R"(data/scales/major.json)");
    std::string root = "C#";
    std::vector<std::string> notes = major.getNotes(root);
    for (const std::string& note : notes) {
        std::cout << note << "\n";
    }

}