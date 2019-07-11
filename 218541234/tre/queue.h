#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

struct queue {
    int head, tail;
    int size;
    double *elem;
};

void init(queue &q, int maxdim);
void deinit(queue &q);
void print(const queue &q);
bool enqueue(queue &q, double n);
bool first(queue &q, double &out);
bool dequeue(queue &q);

#endif
