// Implement Stack Using Array
// By [ Taher Anaya ]
// In [ 8/21/2021 ]
// At [ 4:25 PM ]
#include <bits/stdc++.h>

using namespace std;

template<class T>
class Stack {

    T *arr;
    int cursor;
    int size{};

public:

    Stack() {
        size = 100;
        arr = new T[size];
        cursor = -1;
    }

    explicit Stack(int size) {
        this->size = size;
        arr = new T[size];
        cursor = -1;
    }

    void push(T value) {
        if (cursor == size - 1)
            cout << "Full Stack, You Can Not Push Other Elements" << endl;
        else
            arr[++cursor] = value;
    }

    T pop() {
        if (cursor == -1) {
            cout << "Empty Stack, There Is No Elements To Pop Them" << endl;
            return -1;
        } else {
            return arr[cursor--];
        }
    }

    T top() {
        if (cursor == -1)
            cout << "Empty Stack" << endl;
        else
            return arr[cursor];
    }

    void display() {
        cout << "[ ";
        for (int i = cursor; i > -1; --i)
            cout << arr[i] << " ";
        cout << "]";
        cout << endl;
    }

};

int main() {


    return 0;
}