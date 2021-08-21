// Implement Simple Queue Using Array
// By [ Taher Anaya ]
// In [ 8/21/2021 ]
// At [ 8:21 PM ]
#include <bits/stdc++.h>

using namespace std;

template<class T>
class Queue {

    T *arr;
    int front, rear;
    int size{};

public:

    Queue() {
        size = 100;
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    explicit Queue(int size) {
        this->size = size;
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    void enQueue(T value) {
        if (front == rear && front == -1) {
            arr[++rear] = value;
            front++;
        } else if (rear == size - 1) {
            cout << "Full Queue, You Can Not Enqueue Other Elements" << endl;
        } else {
            arr[++rear] = value;
        }
    }

    T deQueue() {
        if (front == -1 && front == rear || front > rear) {
            cout << "Empty Queue, There Is No Elements To Pop Them" << endl;
            return -1;
        } else {
            T temp = arr[front++];

            for (int i = 0; i < rear - 1; ++i)
                arr[i] = arr[i + 1];
            front--;
            rear--;

            return temp;

        }
    }

    T top() {
        if (front == -1 && front == rear || front > rear) {
            cout << "Empty Queue, There Is No Elements To Pop Them" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    void display() {
        cout << "[ ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << "]";
        cout << endl;
    }

};

int main() {

    return 0;
}