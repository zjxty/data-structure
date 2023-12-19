#define _CRT_SECURE_NO_WARNINGS 1


#include "queue.h"

void queue_test() {
	queue q;
	queue_init(&q);

	push_data(&q, 10);
	push_data(&q, 20);
	push_data(&q, 30);

	print(&q);


	while (q.size) {
		pop_data(&q);
		printf("front : %d back %d \n", get_front(&q), get_back(&q));
		print(&q);
	}

	push_data(&q, 100);
	print(&q);
}





int main() {
	queue_test();

	return 0;
}