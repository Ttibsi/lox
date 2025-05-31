#ifndef clox_scanner_h
#define clox_scanner_h

struct Scanner {
    char* start;
    char* current; 
    int line = 1; 

    Scanner(std::string_view source) {
        start = &source.at(0);
        current = &source.at(0);
    } 
};
