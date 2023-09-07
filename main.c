#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front,rear,size,capacity;
    int* array;
    // Định nghĩa cấu trúc dữ liệu Queue
    // Bao gồm các thành phần như front, rear, size, capacity, và array.
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if(!queue){
        perror("Fail to create queue");
        exit(1);
    }

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity-1;
    queue->array = (int*)malloc(sizeof(int) * capacity);

    if(!queue->array){
        perror("faile to create string for queue!");
        exit(1);
    }
    return queue;
    // Triển khai hàm tạo Queue mới
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
    // Triển khai hàm kiểm tra Queue có đầy không
}

int isEmpty(struct Queue* queue) {
    return(queue->size == 0);
    // Triển khai hàm kiểm tra Queue có trống không
}

void enqueue(struct Queue* queue, int item) {
    if(isFull(queue)){
        printf("queue is full, cannot add new item!");
        return;
    }

    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d be add on queue. \n",item); 
    // Triển khai hàm thêm phần tử vào Queue
}

int dequeue(struct Queue* queue) {
    if(isEmpty(queue)){
        printf("queue is empty, cannot take item!");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size--;
    return item;
    // Triển khai hàm lấy phần tử từ Queue
}

int main() {
    struct Queue* queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    // Thêm phần tử mới vào Queue
    enqueue(queue, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("Front item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);

    return 0;
}
