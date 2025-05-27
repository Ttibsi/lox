#include "chunk.h" 
#include "debug.h" 
#include "vm.h" 
 
int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;
 
    VM vm; 
    Chunk chunk = {}; 
    chunk.push_back({OpCode::Constant, {1.2}, 1}); 
    chunk.push_back({OpCode::Constant, {3.4}, 1}); 
    chunk.push_back({OpCode::Add, {}, 1}); 
    chunk.push_back({OpCode::Constant, {5.6}, 1}); 
    chunk.push_back({OpCode::Divide, {}, 1}); 
    chunk.push_back({OpCode::Return, {}, 2}); 

    //disasm(chunk, "test");
    vm.interpret(&chunk);
 
    return 0; 
} 
