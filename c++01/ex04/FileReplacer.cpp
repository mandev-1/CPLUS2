#include "FileReplacer.hpp"
#include <iostream>
#include <sstream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

void FileReplacer::replace() {
    std::ifstream inFile(filename.c_str());  // Changed here
    if (!inFile.is_open()) {
        throw std::runtime_error("Cannot open input file");
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());  // Changed here
    if (!outFile.is_open()) {
        inFile.close();
        throw std::runtime_error("Cannot create output file");
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();

    if (s1.empty()) {
        outFile << content;
        inFile.close();
        outFile.close();
        return;
    }

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos += s2.length();
    }

    outFile << content;
    inFile.close();
    outFile.close();
}
