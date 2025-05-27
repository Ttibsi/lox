#include "chunk.h" 
#include "debug.h" 

int main(int argc, const char* argv[]) {
    Chunk chunk = {}; 
    chunk.push_back({OpCode::Constant, {1.2}, 1});
    chunk.push_back({OpCode::Constant, {2.4}, 1});
    chunk.push_back({OpCode::Return, {}, 2}); 

    disasm(chunk, "test");
 
    return 0; 
} 
