#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

enum class InterpretResult {
    OK,
    COMPILE_ERROR,
    RUNTIME_ERROR 
}; 
 
struct VM {
    Chunk* stored_chunk;
    uint8_t ip; 
    
    InterpretResult interpret(Chunk*);
    InterpretResult run(); 
}; 
 
#endif // clox_vm_h 
