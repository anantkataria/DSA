#include<bits/stdc++.h>
using namespace std;

// CIRCULAR ARRAY IMPLEMENTATION


// class Queue {
// public:
// 	int front;
// 	int rear;
// 	int size;
// 	unsigned capacity;
// 	int* array;
// };

// Queue* createQueue(unsigned capacity){
// 	Queue* queue = new Queue();
// 	queue -> capacity = capacity;
// 	queue -> front = 0;
// 	queue -> size = 0;
// 	queue -> rear = capacity - 1;
// 	queue -> array = new int[queue->capacity];
// 	return queue;
// }

// int isFull(Queue* queue){
// 	return (queue->size == queue->capacity);
// }

// int isEmpty(Queue* queue){
// 	return (queue->size == 0);
// }

// void enqueue(Queue* queue, int item){
// 	if(isFull(queue))
// 		return;
// 	queue->rear = (queue->rear + 1)%queue->capacity;
// 	queue->array[queue->rear] = item;
// 	queue->size += 1;
// 	cout << item << " enqueued to queue" << endl;
// }

// int dequeue(Queue* queue){
// 	if(isEmpty(queue))
// 		return INT_MIN;
// 	int item = queue->array[queue->front];
// 	queue->front = (queue->front+1)%queue->capacity;
// 	queue->size -= 1;
// 	return item;
// }

// int front(Queue* queue){
// 	if(isEmpty(queue))
// 		return INT_MIN;
// 	return queue->array[queue->front];
// }

// int rear(Queue* queue){
// 	if(isEmpty(queue))
// 		return INT_MIN;
// 	return queue->array[queue->rear];
// }

// int main() {
// 	Queue* queue = createQueue(1000);
// 	enqueue(queue, 10);
// 	enqueue(queue, 20);
// 	enqueue(queue, 30);
// 	enqueue(queue, 40);

// 	cout << dequeue(queue) << " dequeued from queue" << endl;
// 	cout << "Front item is " << front(queue) << endl;
// 	cout << "Rear item is " << rear(queue) << endl;

// 	return 0;
// }


// LINKED LIST IMPLEMENTATION

struct QNode {
	int data;
	QNode* next;
	QNode(int d){
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue() {
		front = rear = NULL;
	}
	void enQueue(int x){
		QNode* temp = new QNode(x);
		if(rear == NULL){
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	void deQueue() {
		if(front == NULL)
			return;
		QNode* temp = front;
		front = front -> next;
		if(front == NULL)
			rear = NULL;
		delete(temp);
	}
};

int main() {
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.deQueue();
	cout << "Queue front : " << (q.front)->data << endl;
	cout << "Queue rear : " << (q.rear)->data;
	return 0;
}