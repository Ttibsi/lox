#include "chunk.h" 
#include "debug.h" 
#include "vm.h" 
 
int main(int argc, const char* argv[]) {
    (void)argc;
    (void)argv;
 
    VM vm; 
    Chunk chunk = {}; 
    chunk.push_back({OpCode::Constant, {1.2}, 1});
    chunk.push_back({OpCode::Constant, {2.4}, 1});
    chunk.push_back({OpCode::Negate, {}, 1}); 
    chunk.push_back({OpCode::Return, {}, 2}); 

    //disasm(chunk, "test");
    vm.interpret(&chunk);
 
    return 0; 
} 
