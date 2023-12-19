#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <stdbool.h>


typedef int queue_type;

typedef struct node {
	struct node* next;
	queue_type data;
}node;

typedef struct queue {
	node* head;
	node* tail;

	int size;
}queue;

void queue_init(queue* pq);
void queue_destroy(queue* pq);


void push_data(queue* pq, queue_type data);
void pop_data(queue* pq);

queue_type get_front(queue* pq);
queue_type get_back(queue* pq);

bool empty(queue* pq);
int size(queue* pq);

void print(queue* pq);