#ifndef clox_debug_h
#define clox_debug_h

#include <string> 
#include <string_view> 

#include "chunk.h" 
#include "value.h" 

const bool DEBUG = true;

void disasm(const Chunk&, std::string_view);
void disasm_instruction(const int, const Operation&, const int); 

void simpleInstruction(std::string_view); 
void constantInstruction(std::string_view, const std::vector<Value>&); 

#endif // clox_debug_h 
