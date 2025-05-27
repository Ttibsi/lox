#ifndef clox_vm_h
#define clox_vm_h

#include <deque>
 
#include "chunk.h"
#include "value.h" 

enum class InterpretResult {
    OK,
    COMPILE_ERROR,
    RUNTIME_ERROR 
}; 
 
struct VM {
    Chunk* stored_chunk;
    uint8_t ip; 
    std::deque<Value> stack = {}; 
    
    InterpretResult interpret(Chunk*);
    InterpretResult run(); 
    void reset_stack(); 
}; 
 
#endif // clox_vm_h 
