// Implement Single Linked List
// By [ Taher Anaya ]
// In [ 8/21/2021 ]
// At [ 1:44 PM ]
#include <bits/stdc++.h>

using namespace std;

template<class T>
struct node {
    T value;
    node *next;
};

template<class T>
class SingleLinkedList {


    node<T> *head;
public:

    SingleLinkedList() {
        head = nullptr;
    }

    void insertNodeAtBegin(int value) {
        auto *newNode = new node<int>({value, nullptr});
        newNode->next = head;
        head = newNode;
    }

    void insertNodeBefore(int value, int before) {
        auto *newNode = new node<int>({value, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;
            node<T> *previous = nullptr;

            while (current->value != before && current->next != nullptr) {
                previous = current;
                current = current->next;
            }

            if (current->value == before) {
                if (previous == nullptr) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->next = previous->next;
                    previous->next = newNode;
                }
            } else {
                current->next = newNode;
            }

        }
    }

    void insertNodeAfter(int value, int after) {
        auto *newNode = new node<int>({value, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {

            auto *temp = head;
            while (temp->value != after && temp->next != nullptr) temp = temp->next;
            if (temp->value == after) newNode->next = temp->next;
            temp->next = newNode;

        }
    }

    void insertNodeToEnd(int value) {
        auto *newNode = new node<int>({value, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {
            auto *temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }

    void insertAsc(int value) {

        auto *newNode = new node<int>({value, nullptr});

        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;
            node<T> *previous = nullptr;

            while (current->value <= value && current->next != nullptr) {
                previous = current;
                current = current->next;
            }

            if (current->value > value) {
                newNode->next = current;
                previous != nullptr ? previous->next = newNode : head = newNode;
            } else {
                current->next = newNode;
            }

        }

    }

    void insertDesc(int value) {

        auto *newNode = new node<int>({value, nullptr});

        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;
            node<T> *previous = nullptr;

            while (current->value >= value && current->next != nullptr) {
                previous = current;
                current = current->next;
            }

            if (current->value < value) {
                newNode->next = current;
                previous != nullptr ? previous->next = newNode : head = newNode;
            } else {
                current->next = newNode;
            }

        }

    }

    void deleteNodeFromBegin() {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            auto *temp = head;
            head = head->next;
            delete (temp);
        }
    }

    void deleteNodeFromEnd() {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            node<T> *previous = nullptr;
            auto *current = head;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
            delete (current);
        }
    }

    void deleteNode(int value) {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            node<T> *previous = nullptr;
            auto *current = head;
            while (current->value != value && current->next != nullptr) {
                previous = current;
                current = current->next;
            }

            if (current->value == value) {

                if (previous == nullptr) {
                    auto *temp = head;
                    head = head->next;
                    temp->next = nullptr;
                    delete (temp);
                } else {
                    previous->next = current->next;
                    current->next = nullptr;
                    delete (current);
                }

            } else {
                cout << "Item Not Found" << endl;
            }

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