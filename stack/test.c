#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"


void stack_test() {
	stack st;
	stack_init(&st);
	// printf("top: %d \n", get_top(&st));

	push_data(&st, 10);
	printf("top: %d \n", get_top(&st));
	
	push_data(&st, 20);
	printf("top: %d \n", get_top(&st));

	push_data(&st, 30);
	printf("top: %d \n", get_top(&st));

	stack_destory(&st);
	stack_print(&st);
}




int main() {
	stack_test();

}