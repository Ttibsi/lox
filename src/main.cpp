#include "common.h"
#include "chunk.h" 
#include "debug.h" 

int main(int argc, const char* argv[]) {
    Chunk chunk = {}; 
    chunk.push_back(OpCode::Return); 

    disasm(chunk, "test");
 
    return 0; 
} 
