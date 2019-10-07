#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool test_underflow(stack_t* this_)
{
    for(int i = 0; i <= 100; ++i)
        stack_push(this_, i - 1);
    printf("HERE");
    for(int i = 0; i <= 110; ++i)
        printf("%d\n", stack_pop(this_));
    //stack_dump(this_, 0);
    printf("HERE");
    return true;
}

bool test_nullptr(stack_t* this_)
{
    stack_push(nullptr, 0);
    stack_pop (nullptr);
    stack_destruct(nullptr);
    STACKCONSTRUCT(nullptr);
    stack_push(nullptr, 5);
    stack_pop(nullptr);
    //check_size(nullptr, 1);  //err
    return true;
}

bool test_size(stack_t* stack_)
{
    stack_push(stack_, 5);
    int size_ = stack_->size;
    check_size(stack_, NEEDPOP);
    check_size(stack_, NEEDPUSH);  //need push not update hash =>error in hash sum
    check_size(stack_, NEEDPUSH);
    check_size(stack_, NEEDPUSH);
    if (size_ != stack_->size)
    {
        printf("PROBLEM IN STACK_SIZE\n");
        return false;
    }
    printf("stack_size okay\n");
    return true;

}

int main()
{
    struct stack_t a_stack = {};

    STACKCONSTRUCT(&a_stack);

    test_underflow(&a_stack);

    printf("FIRST test passed\n\n\n\n");

    test_size(&a_stack);

    STACKDESTRUCT(&a_stack);

    test_nullptr(&a_stack);
}

