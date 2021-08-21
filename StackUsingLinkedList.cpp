// Implement Stack Using Linked List
// By [ Taher Anaya ]
// In [ 8/21/2021 ]
// At [ 4:35 PM ]
#include <bits/stdc++.h>

using namespace std;

template<class T>
struct node {
    T value;
    node *next;
};

template<class T>
class Stack {
    node<T> *head;
public:

    Stack() { head = nullptr; }

    // Push = Insert Node At Begin
    void push(int value) {
        auto *newNode = new node<int>({value, nullptr});
        newNode->next = head;
        head = newNode;
    }

    // Pop = Delete Node From Begin
    void pop() {

        if (head == nullptr) {
            cout << "Empty Stack, There Is No Items To Delete Them" << endl;
        } else {
            auto *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete (temp);
        }
    }

    T top() {

        if (head == nullptr) {
            cout << "Empty Stack" << endl;
            return -1;
        } else {
            return head->value;
        }
    }

    void display() {

        if (head == nullptr) {
            cout << "Empty Linked List" << endl;
        } else {

            auto *temp = head;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

int main() {


    return 0;
}