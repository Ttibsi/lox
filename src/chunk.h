#ifndef clox_chunk_h
#define clox_chunk_h

#include <vector> 

#include "common.h"

enum class OpCode {
    Return 
};

using Chunk = std::vector<OpCode>;
 
#endif // clox_chunk_h
