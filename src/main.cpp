#include <iostream>
#include <print>
#include <string> 
#include <string_view> 
 
#include "chunk.h" 
#include "debug.h" 
#include "vm.h" 
 
void repl() {
    std::string line = "";
    VM vm; 
 
    while(true) {
        std::print("> ");

        std::getline(std::cin, line);
        vm.interpret(line); 
    } 
}
 
std::string readFile(std::string_view path) {
    std::string ret = "";
    char c; 

    std::ifstream ifs(path);
    if (ifs.fail()) {
        std::println("Failed to open file {}", path); 
        return ""; 
    }

    while (ifs.get(c)) { ret.push_back(c); }
    return ret; 
}
 
int runFile(std::string_view path) {
    std::string source = readFile(path);
    VM vm; 
    InterpretResult result = vm.interpret(source);
    switch (result) { 
        case InterpretResult::COMPILE_ERROR: return 65; 
        case InterpretResult::RUNTIME_ERROR: return 70; 
        default: return 0; 
    }
}
 
int main(int argc, const char* argv[]) {
    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        return runFile(argv[1]);
    } else {
        std::println("Usage: clox [path]");
    }
 
    return 0; 
} 
