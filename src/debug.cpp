#include <print>

#include "debug.h"

void disasm(const Chunk& chunk, const std::string& name) {
    std::println("== {} ==", name);

    for (int offset = 0; offset < chunk.size();) {
        offset = disasm_instruction(chunk, offset);
    }
} 

int disasm_instruction(const Chunk& chunk, int offset) {
    std::print("{:04} ", offset);

    switch(chunk.at(offset)) {
        case OpCode::Return:
            return simpleInstruction("OP_RETURN", offset); 
        default:
            std::println("Unknown opcode at idx: {}", offset); 
    } 
 
} 

int simpleInstruction(std::string_view name, int offset) {
    std::println("{}", name); 
    return ++offset; 
} 
