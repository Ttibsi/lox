#include <print>
#include <string> 

#include "debug.h"

void disasm(const Chunk& chunk, std::string_view name) {
    std::println("== {} ==", name);

    int prev_lineno = 0; 
    for (int idx = 0; idx < chunk.size(); idx++) {
        disasm_instruction(idx, chunk.at(idx), prev_lineno);
        prev_lineno = chunk.at(idx).lineno; 
    }
} 

void disasm_instruction(const int idx, const Operation& op, const int prev_lineno) {
    std::print("{:03} ", idx);
    if (idx > 0 && op.lineno == prev_lineno) {
        std::print(" | ");
    } else { 
        std::print("{:03} ", op.lineno);
    } 

    switch(op.opcode) {
        case OpCode::Return:
            simpleInstruction("OP_RETURN"); 
            break; 
        case OpCode::Constant:
            constantInstruction("OP_CONSTANT", op.vals);
            break; 
        case OpCode::Negate:
            simpleInstruction("OP_NEGATE"); 
            break; 
        case OpCode::Add:
            simpleInstruction("OP_ADD");
            break; 
        case OpCode::Subtract:
            simpleInstruction("OP_SUBTRACT");
            break;
        case OpCode::Multiply:
            simpleInstruction("OP_MULTIPLY");
            break;
        case OpCode::Divide:
            simpleInstruction("OP_DIVIDE");
            break; 
        default:
            std::println("Unknown opcode at idx: {}", idx); 
            break; 
    }
} 

void simpleInstruction(std::string_view name) {
    std::println("{}", name);
} 

void constantInstruction(std::string_view name, const std::vector<Value>& vals) {
    std::println("{} '{}' ", name, vals);
}
