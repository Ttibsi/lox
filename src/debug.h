#ifndef clox_debug_h
#define clox_debug_h

#include <string> 
#include <string_view> 

#include "chunk.h" 

void disasm(const Chunk&, const std::string&);
int disasm_instruction(const Chunk&, int); 

int simpleInstruction(std::string_view, int); 

#endif // clox_debug_h 
