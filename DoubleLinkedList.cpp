// Implement Double Linked List
// By [ Taher Anaya ]
// In [ 8/21/2021 ]
// At [ 3:11 PM ]
#include <bits/stdc++.h>

using namespace std;

template<class T>
struct node {
    T value;
    node *previous;
    node *next;
};

template<class T>
class DoubleLinkedList {

    node<T> *head;
public:

    DoubleLinkedList() {
        head = nullptr;
    }

    void insertNodeAtBegin(int value) {
        auto *newNode = new node<int>({value, nullptr, nullptr});
        if (head != nullptr) {
            newNode->next = head;
            head->previous = newNode;
        }
        head = newNode;
    }

    void insertNodeBefore(int value, int before) {
        auto *newNode = new node<int>({value, nullptr, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;

            while (current->value != before && current->next != nullptr) current = current->next;

            if (current->value == before) {
                if (current == head) {
                    newNode->next = head;
                    head->previous = newNode;
                    head = newNode;
                } else {
                    newNode->next = current;
                    newNode->previous = current->previous;
                    current->previous->next = newNode;
                    current->previous = newNode;
                }
            } else {
                current->next = newNode;
                newNode->previous = current;
            }

        }
    }

    void insertNodeAfter(int value, int after) {
        auto *newNode = new node<int>({value, nullptr, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;
            while (current->value != after && current->next != nullptr) current = current->next;

            if (current->value == after) {

                if (current->next == nullptr) {
                    current->next = newNode;
                    newNode->previous = current;
                } else {

                    newNode->previous = current;
                    newNode->next = current->next;
                    current->next = newNode;
                    newNode->next->previous = newNode;

                }

            } else {
                current->next = newNode;
                newNode->previous = current;
            }

        }
    }

    void insertNodeToEnd(int value) {
        auto *newNode = new node<int>({value, nullptr, nullptr});
        if (head == nullptr) {
            head = newNode;
        } else {
            auto *temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
            newNode->previous = temp;
        }
    }

    void insertAsc(int value) {

        auto *newNode = new node<int>({value, nullptr, nullptr});

        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;

            while (current->value <= value && current->next != nullptr) current = current->next;

            if (current->value > value) {

                if (current == head) {
                    newNode->next = head;
                    head->previous = newNode;
                    head = newNode;
                } else {
                    newNode->previous = current->previous;
                    newNode->next = current;
                    current->previous->next = newNode;
                    current->previous = newNode;
                }
            } else {
                current->next = newNode;
                newNode->previous = current;
            }
        }
    }

    void insertDesc(int value) {

        auto *newNode = new node<int>({value, nullptr, nullptr});

        if (head == nullptr) {
            head = newNode;
        } else {

            auto *current = head;

            while (current->value >= value && current->next != nullptr) current = current->next;

            if (current->value < value) {

                if (current == head) {
                    newNode->next = head;
                    head->previous = newNode;
                    head = newNode;
                } else {
                    newNode->previous = current->previous;
                    newNode->next = current;
                    current->previous->next = newNode;
                    current->previous = newNode;
                }
            } else {
                current->next = newNode;
                newNode->previous = current;
            }
        }

    }

    void deleteNodeFromBegin() {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            auto *temp = head;
            head->next->previous = nullptr;
            head = head->next;
            temp->next = nullptr;
            delete (temp);
        }
    }

    void deleteNodeFromEnd() {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            auto *current = head;
            while (current->next != nullptr) current = current->next;

            current->previous->next = nullptr;
            current->previous = nullptr;
            delete (current);
        }
    }

    void deleteNode(int value) {

        if (head == nullptr) {
            cout << "No Items To Delete Them" << endl;
        } else {
            auto *current = head;
            while (current->value != value && current->next != nullptr) current = current->next;

            if (current->value == value) {

                if (current == head) { // current->previous == nullptr => [ First Node ]
                    head->next->previous = nullptr;
                    head = head->next;
                    current->next = nullptr;
                    delete (current);
                } else if (current->next == nullptr) { // Last Node
                    current->previous->next = nullptr;
                    current->previous = nullptr;
                    delete (current);
                } else {

                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    current->previous = nullptr;
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