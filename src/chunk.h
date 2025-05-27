#ifndef clox_chunk_h
#define clox_chunk_h

#include <vector> 

#include "value.h" 

enum class OpCode {
    Constant, 
    Add,
    Subtract,
    Multiply,
    Divide, 
    Negate, 
    Return 
};

struct Operation {
    OpCode opcode; 
    ValueArray vals; 
    int lineno; 
}; 
 
using Chunk = std::vector<Operation>;
 
#endif // clox_chunk_h
