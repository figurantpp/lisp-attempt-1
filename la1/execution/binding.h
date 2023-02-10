//
// Created by figurantpp on 09/02/23.
//

#ifndef LATTEMPT_BINDING_H
#define LATTEMPT_BINDING_H

#include "../common/list.h"
#include <stddef.h>

struct Value;

typedef struct Value Value;

typedef void *KnownSymbol;

struct Binding {
    KnownSymbol symbol;
    Value *value;
};

typedef struct Binding Binding;

struct Bindings {
    Binding *content;
    size_t size;
    size_t capacity;
};

typedef struct Bindings Bindings;

Bindings *la1_bindings_create();

Bindings *la1_bindings_create_with_capacity(size_t capacity);

void la1_bindings_add(Bindings *bindings, KnownSymbol key, Value *value);

int la1_bindings_lookup(Bindings *bindings, KnownSymbol key, Value **result);

typedef struct {
    LinkedList *list;
} BindingStack;

BindingStack *la1_binding_stack_create();

void la1_binding_stack_push(BindingStack *stack, Bindings *bindings);

void la1_binding_stack_pop(BindingStack *stack);

int la1_binding_stack_lookup(BindingStack *stack, KnownSymbol key, Value **result);

#endif //LATTEMPT_BINDING_H
