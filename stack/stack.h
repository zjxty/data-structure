#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef int stack_type;

typedef struct stack {
	stack_type* ptr;

	int top;
	int capacity;
}stack;

void stack_init(stack* ps);
void stack_destory(stack* ps);

void push_data(stack* const ps, stack_type data);
void pop_data(stack* const ps);

void stack_print(const stack* ps);

stack_type get_top(const stack* ps);
