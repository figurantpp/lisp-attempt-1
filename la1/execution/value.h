//
// Created by figurantpp on 09/02/23.
//

#ifndef LATTEMPT_VALUE_H
#define LATTEMPT_VALUE_H

#include "../common/list.h"
#include "binding.h"

struct Value;
typedef struct Value Value;

struct LA1_State;
typedef struct LA1_State LA1_State;

struct DataClosure {
    LinkedList *environment;
    LinkedList *parameters;
    Value *body_source;
};

typedef struct DataClosure DataClosure;

typedef Value *ClosureFunction(LA1_State *state, LinkedList *parameters, void *extra);

typedef struct {
    ClosureFunction *function;
    void *extra;
} Closure;

#define LA1_VALUE_TYPE_X() \
    X(NUMBER) \
    X(LIST) \
    X(SYMBOL) \
    X(CLOSURE) \


enum ValueType {
#define X(name) LA1_VALUE_##name,
    LA1_VALUE_TYPE_X()
#undef X
};

typedef enum ValueType ValueType;

union UntaggedValue {
    LinkedList *list;
    KnownSymbol symbol;
    long number;
    Closure *closure;
};

typedef union UntaggedValue UntaggedValue;

struct Value {
    ValueType type;
    UntaggedValue content;
};

const char *la1_get_type_name(ValueType type);

Value *la1_list_into_value(LinkedList *value);

Value *la1_number_into_value(long value);

Value *la1_symbol_into_value(KnownSymbol symbol);

Closure *la1_create_closure(ClosureFunction *function, void *extra);

Value *la1_closure_into_value(Closure *closure);

void la1_expect_type(Value *value, ValueType type);

void la1_expect_size(LinkedList *list, unsigned int size);

void la1_display_value(Value *value);


#endif //LATTEMPT_VALUE_H
