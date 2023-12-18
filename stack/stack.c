#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void stack_init(stack* ps) {
	if (ps == NULL) {
		printf("stack is undefined\n");
		return;
	}

	ps->top = -1;
	ps->capacity = 4;

	ps->ptr = (stack_type*)malloc(ps->capacity * sizeof(stack_type));
	if (ps->ptr == NULL) {
		printf("malloc failed when creating for a stack");
		return;
	}
}


void stack_destory(stack* ps) {
	if (ps == NULL) {
		printf("stack is undefined\n");
		return;
	}

	free(ps->ptr);
	ps->top = -1;
	ps->capacity = 0;
}

void push_data(stack* const ps, stack_type data) {
	if (ps == NULL) {
		printf("stack is undefined\n");
		return;
	}

	if (ps->top + 1 >= ps->capacity) {
		stack_type* tmp = (stack_type*)realloc(ps->ptr, ps->capacity * 2 * sizeof(stack_type));
		if (tmp == NULL) {
			printf("realloc failed when pushing data\n");
			return;
		}
		ps->ptr = tmp;
		ps->capacity *= 2;
	}
	ps->ptr[++(ps->top)] = data;
}

void pop_data(stack* const ps) {
	if (ps == NULL || ps->top == -1) {
		printf("stack is undefined or stack is empty");
		return;
	}

	ps->top--;
}

void stack_print(const stack* ps) {
	if (ps == NULL || ps->top == -1) {
		printf("stack is undefined or stack is empty");
		return;
	}

	for (int i = 0; i <= ps->top; ++i) {
		printf("%d ", ps->ptr[i]);
	}
	printf("\n");
}

stack_type get_top(const stack* ps) {
	if (ps == NULL || ps->top == -1) {
		printf("stack is undefined or stack is empty");
		exit(1);
	}

	return ps->ptr[ps->top];
}