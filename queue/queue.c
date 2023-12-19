#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void queue_init(queue* pq) {
	assert(pq != NULL);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}


void queue_destroy(queue* pq) {
	assert(pq != NULL);

	if (pq->head == pq->tail && pq->head == NULL) {
		printf("there is no node in the queue\n");
		return;
	}

	node* cur = pq->tail;
	while (cur != pq->tail) {
		node* next = cur->next;
		free(cur);

		cur = next;
	}
	free(cur);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}


void push_data(queue* pq, queue_type data) {
	assert(pq != NULL);

	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL) {
		printf("malloc failed when pushing data\n");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;

	// the first time pushing data
	if (pq->head == pq->tail && pq->head == NULL) {
		pq->head = pq->tail = newnode;
		++(pq->size);
		return;
	}

	// newnode -> tail -> ... -> head
	newnode->next = pq->tail;
	pq->tail = newnode;

	++(pq->size);
}


void pop_data(queue* pq) {
	assert(pq != NULL);

	if (pq->head == pq->tail && pq->head == NULL) {
		printf("there is no node in the queue\n");
		return;
	}

	// there is noly one node in the queue
	if (pq->head == pq->tail) {
		free(pq->head);
		pq->head = pq->tail = NULL;
		--(pq->size);
		return;
	}

	node* tmp = pq->tail->next;
	free(pq->tail);
	pq->tail = tmp;

	--(pq->size);
}

queue_type get_front(queue* pq) {
	assert(pq != NULL);

	if (pq->head == pq->tail && pq->head == NULL) {
		printf("there is no node in the queue\n");
		return;
	}

	return pq->head->data;
}

queue_type get_back(queue* pq) {
	assert(pq != NULL);

	if (pq->head == pq->tail && pq->head == NULL) {
		printf("there is no node in the queue\n");
		return;
	}

	return pq->tail->data;
}

bool empty(queue* pq) {
	return pq->size == 0;
}

int size(queue* pq) {
	return pq->size;
}

void _print(node* ptr) {
	if (ptr == NULL) {
		return;
	}
	_print(ptr->next);
	
	if (ptr->next == NULL) {
		printf("%d", ptr->data);
	}
	else {
		printf(" <- %d", ptr->data);
	}
}


void print(queue* pq) {
	assert(pq != NULL);

	if (pq->head == pq->tail && pq->head == NULL) {
		printf("there is no node in the queue\n");
		return;
	}

	_print(pq->tail);
	printf("\n");
}