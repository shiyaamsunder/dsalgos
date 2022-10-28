#ifndef QUEUE_H
#define QUEUE_H
#pragma once


#define INTEGER int
#define CHARACTER char
#define MAX_ELEMENT_SIZE (100)

void enqueue(INTEGER data);
void enqueue_c(CHARACTER data);

void dequeue();
void dequeue_c();

int is_empty();

int is_full();

void make_empty();

void display();
#endif
