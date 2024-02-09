#include <iostream>
#include "stringhelper.h"

using std::cout, std::cin, std::endl, std::string;

size_t countString(string searchString, string source) {
    size_t stringCount = 0;
    size_t sourceIndex = source.find(searchString);
    size_t searchLength = searchString.length();
    while (sourceIndex != string::npos) {
        // if spaces on both sides
        if ((sourceIndex == 0 || isspace(source.at(sourceIndex-1))) && 
           (sourceIndex+searchLength >= source.length() || isspace(source.at(sourceIndex+searchLength)))) {
                stringCount++;
        }
        sourceIndex = source.find(searchString, sourceIndex+searchLength);
    }
    return stringCount;
}

string removeString(string removeString, string source) {
    size_t removeCount = 0;
    size_t removeLength = removeString.length();
    size_t index = source.find(removeString);
    while (index != string::npos) {
       size_t offset = removeLength;
       if ((index == 0 || isspace(source.at(index-1))) && 
           (index+removeLength >= source.length() || isspace(source.at(index+removeLength)))) {
                source.erase(index, removeLength);
                removeCount++;
                offset = 0;
        }

        index = source.find(removeString, index+offset);
    }
    cout << "Removed '" << removeString << "' " << removeCount << " times" << endl;
    return source;
}