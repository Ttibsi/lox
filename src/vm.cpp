#include "vm.h"
#include "debug.h" 
#include "compiler.h" 
 
#include <print> 

InterpretResult VM::interpret(std::string_view source) {
    compile(source);
    return InterpretResult::OK;
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
            case OpCode::Add:
                bin_op<std::plus<>>();
                break;
            case OpCode::Subtract:
                bin_op<std::minus<>>();
                break; 
            case OpCode::Multiply:
                bin_op<std::multiplies<>>();
                break;
            case OpCode::Divide:
                bin_op<std::divides<>>();
                break; 
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
