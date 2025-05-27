#include "vm.h"
#include "debug.h" 

#include <print> 

InterpretResult VM::interpret(Chunk* chunk) {
    stored_chunk = chunk; 
    return run();
} 

InterpretResult VM::run() {
    for (int idx = 0; idx < stored_chunk->size(); idx++) {
        Operation op = stored_chunk->at(idx); 
 
        if constexpr (DEBUG) {
            disasm_instruction(idx, op, 0);
        } 
 
        switch (op.opcode) {
            case OpCode::Constant: {
                Value c = op.vals.at(0);
                std::println("{}", c);
                break; 
            } 
            case OpCode::Return: return InterpretResult::OK;
        } 
    } 
} 
