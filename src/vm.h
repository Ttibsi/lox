#ifndef clox_vm_h
#define clox_vm_h

#include <deque>
#include <functional> 
#include <string_view> 
 
#include "chunk.h"
#include "value.h" 

enum class InterpretResult {
    OK,
    COMPILE_ERROR,
    RUNTIME_ERROR 
}; 
 
template <typename T, typename... U>
concept any_of = (std::same_as<T, U> || ...); 
template <typename T>
concept binary_operator = any_of<T, std::plus<>, std::minus<>, std::multiplies<>, std::divides<>>;

struct VM {
    Chunk* stored_chunk;
    uint8_t ip; 
    std::deque<Value> stack = {}; 
    
    InterpretResult interpret(std::string_view);
    InterpretResult run(); 
    void reset_stack(); 

    template <binary_operator OP>
    Value bin_op() {
        Value a =  stack.at(0);
        stack.pop_front(); 
        Value b = stack.at(0);
        stack.pop_front();

        stack.push_front(OP{}(a, b));
        return stack.at(0);
    }
}; 
 
#endif // clox_vm_h 
