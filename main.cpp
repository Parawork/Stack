#include <iostream>
//#include <chrono>
using namespace std;
using namespace std::chrono;

class Stack{
    private:
        int top;
        int* array;
        int size;
    public:
        Stack(int size) {
            top = -1;
            array = new int[size];
            this->size = size;
        }
        void push(int value) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                array[top] = value;
            }
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                int popValue = array[top];
                top--;
                return popValue;
            }
        }
        bool isEmpty()  {
            if (top == -1) {
                return true;
            } else {
                return false;
            }
        }
        bool isFull() {
            if (top == size-1) {
                return true;
            } else {
                return false;
            }
        }

        int stacktop() {
            if(top == -1) {
                cout << INT_MIN << endl;
                return 0;
            }
            else{
                return array[top];
            }

        }

        void display() {
            for (int i = 0; i <= top; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
};
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
    Node* top;

public:
    LinkedList(int value) {
        head = nullptr;
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            top = newNode;
        } else {
            top->next = newNode;
            top = newNode;
        }
    }

    int pop() {
        if (isEmpty()) return INT_MIN;
        Node* temp = head;
        if (head == top) {
            head = nullptr;
            top = nullptr;
        } else {
            Node* pre = head;
            while(temp->next) {
                pre = temp;
                temp = temp->next;
            }
            top = pre;
            top->next = nullptr;
        }
        delete temp;
        return temp->value;
    }

    bool isEmpty(){
        if (head == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    int stackTop() {
        if (head == nullptr) return INT_MIN;
        return top->value;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }





};

int main() {

    auto startTime = high_resolution_clock::now();

    auto* stack = new Stack(10);


    stack->push(8);
    stack->push(10);
    stack->push(5);
    stack->push(11);
    stack->push(15);
    stack->push(23);
    stack->push(6);
    stack->push(18);
    stack->push(20);
    stack->push(17);
    stack->display();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->display();
    stack->push(4);
    stack->push(30);
    stack->push(3);
    stack->push(1);
    stack->display();

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    std::cout << "ArrayList duration: " << duration.count() << " microseconds" << std::endl;

    startTime = high_resolution_clock::now();
    auto* StackLinkedList = new LinkedList(10);\

    StackLinkedList->push(8);
    StackLinkedList->push(10);
    StackLinkedList->push(5);
    StackLinkedList->push(11);
    StackLinkedList->push(15);
    StackLinkedList->push(23);
    StackLinkedList->push(6);
    StackLinkedList->push(18);
    StackLinkedList->push(20);
    StackLinkedList->push(17);
    StackLinkedList->display();
    StackLinkedList->pop();
    StackLinkedList->pop();
    StackLinkedList->pop();
    StackLinkedList->pop();
    StackLinkedList->pop();
    StackLinkedList->display();
    StackLinkedList->push(4);
    StackLinkedList->push(30);
    StackLinkedList->push(3);
    StackLinkedList->push(1);
    StackLinkedList->display();
    endTime = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTime - startTime);
    std::cout << "LinkedList duration: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
