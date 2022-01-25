#include <iostream>
#include <vector>
using namespace std;

const int LEN = 3; // Length of queue (Note: the number values actually can be stored is LEN - 1)

int queue[LEN]; // Queue (empty index -> 0)
int tail = 0; // Index where a new value is added (0 ~ LEN-1)
int head = 0; // Index of the beginning of added value (0 ~ LEN-1)

// Initialize queue
void init() {
    head = tail = 0;
}

// Check if queue is full
bool isFull() {
    return (
        head == (tail + 1)
        or (head == 0 and tail == LEN-1)
    );
}

// Check if queue is empty
bool isEmpty() {
    return (head == tail);
}

// Return a head value
int peek() {
    if (isEmpty()) {
        cout << "queue is empty." << endl;
        return -1;
    }
    int v = queue[head];
    return v;
}

// Insert a value into tail
void enqueue(int v) {
    if (isFull()) {
        cout << "queue is full." << endl;
        return;
    }
    queue[tail++] = v;
    if (tail == LEN) tail = 0; // back to 0 if tail reaches the end
}

// Extract a head value and switch a head location
int dequeue() {
    if (isEmpty()) {
        cout << "queue is empty." << endl;
        return -1;
    }
    int v = queue[head];
    head++; // A subject value is switched
    if (head == LEN) head = 0; // back to 0 if head reaches the end
    return v;
}

void testQueue() {
    // Check queue is empty at the beginning
    assert(isFull() == false);
    assert(isEmpty() == true);

    // Make queue full
    for (int i = 1; i <= LEN-1; i++) { enqueue(i); }

    // Check queue is full
    assert(isFull() == true);
    assert(isEmpty() == false);

    // Initialize queue
    init();

    // Add 1 to queue {} -> {1}
    enqueue(1);
    assert(queue[0] == 1);
    // Add 2 to queue {1} -> {1, 2}
    enqueue(2);
    assert(queue[1] == 2);

    // {1, 2} -> {2} : 1 is removed
    assert(peek() == 1);
    dequeue(); 
    // {2} -> {} : 2 is removed
    assert(peek() == 2);
    dequeue();
    assert(isEmpty() == true);

    cout << "Tests Done!" << endl;
}

int main() {
    testQueue();
}