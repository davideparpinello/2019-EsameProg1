#include <iostream>
#include "queue.h"

using namespace std;

void init(queue &q, int maxdim) {
  q.head = q.tail = 0;
  q.size = maxdim + 1;
  q.elem = new double[maxdim + 1];
}

static int next(int n, const queue &q) {
  return ((n + 1) % q.size);
}

void deinit(queue &q) {
  delete [] q.elem;
}

static bool isEmpty(const queue &q) {
  return q.head == q.tail;
}

static bool isFull(const queue &q) {
  return next(q.tail, q) == q.head;
}

void print(const queue &q) {
  for(int i = q.head; i != q.tail; i = next(i, q)) {
    cout << q.elem[i] << endl;
  }
}

bool enqueue(queue &q, double n) {
  bool res = false;
  if(!isFull(q)) {
    q.elem[q.tail] = n;
    q.tail = next(q.tail, q);
    res = true;
  }
  return res;
}

bool first(queue &q, double &out) {
  bool res = false;
  if(!isEmpty(q)) {
    out = q.elem[q.head];
    res = true;
  }
  return res;
}

bool dequeue(queue &q) {
  bool res = false;
  if(!isEmpty(q)) {
    q.head = next(q.head, q);
    res = true;
  }
  return res;
}
