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
            if (!stack.empty()) {
                std::println("        [{}]", stack);
            } 
            disasm_instruction(idx, op, 0);
        } 
 
        switch (op.opcode) {
            case OpCode::Constant: {
                stack.push_front(op.vals.at(0)); 
                break; 
            } 
            case OpCode::Negate: {
                Value top = stack.at(0);  
                stack.pop_front();
                stack.push_front(-top);
                break; 
            } 
            case OpCode::Return: {
                std::println("{}", stack.at(0));
                stack.pop_front(); 
                return InterpretResult::OK;
            } 
        } 
    } 
    
    return InterpretResult::OK; 
} 

void VM::reset_stack() {
    stack.clear();
} 
