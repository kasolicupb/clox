//
// Created by Andrew Li on 2023/1/5.
//

#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "object.h"
#include "chunk.h"
#include "table.h"
#include "value.h"
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)
#define STACK_MAX 256

typedef struct {
    ObjClosure* closure;
    // stores the caller's ip not callee.
    uint8_t* ip;
    Value* slots;
} CallFrame;

typedef struct {
    Chunk* chunk;
    uint8_t* ip; // Instruction Pointer
    CallFrame frames[FRAMES_MAX];
    int frameCount;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    Obj* objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif //CLOX_VM_H
