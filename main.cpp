#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;
using namespace std::chrono;


class arrayListStack {
    // <--- ADD YOUR CODE HERE --->
private:
    int top;
    int *array;
    int size;
public:
    arrayListStack(int size) {
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

    bool isEmpty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (top == size - 1) {
            return true;
        } else {
            return false;
        }
    }

    int stackTop() {
        if (top == -1) {
            cout << INT_MIN << endl;
            return 0;
        } else {
            return array[top];
        }
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

class Node {
    // <--- ADD YOUR CODE HERE --->
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class linkedListStack {
    // <--- ADD YOUR CODE HERE --->
private:
    Node *head;
    Node *top;
public:
    linkedListStack() {
        head = nullptr;
        top = nullptr;
    }

    void push(int value) {
        if (isEmpty()) {
            Node *newNode = new Node(value);
            head = newNode;
            top = newNode;
        } else {
            Node *newNode = new Node(value);
            top->next = newNode;
            top = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = top->value;
            if (top == head) {
                head = nullptr;
                top = nullptr;
            } else {
                Node *temp = head;
                while (temp->next != top) {
                    temp = temp->next;
                }
                temp->next = nullptr;
                top = temp;
            }
            return x;
        }
    }

    bool isEmpty() {
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
        vector<int> array;
        Node *temp = head;
        while (temp != nullptr) {
            int value = temp->value;
            array.insert(array.begin(), value);
            temp = temp->next;
        }
        for (int value: array) {
            cout << value << " ";
        }
        cout << endl;

    }

};


int main() {
    vector<int> arrayStackVector, linkedListStackVector;
    for (int i = 0; i < 100; ++i) {
        auto start_time1 = high_resolution_clock::now();
        linkedListStack ll_Stack;
        ll_Stack.push(10);
        ll_Stack.push(5);
        ll_Stack.push(11);
        ll_Stack.push(15);
        ll_Stack.push(23);
        ll_Stack.push(6);
        ll_Stack.push(18);
        ll_Stack.push(20);
        ll_Stack.push(17);
        ll_Stack.display();
        ll_Stack.pop();
        ll_Stack.pop();
        ll_Stack.pop();
        ll_Stack.pop();
        ll_Stack.pop();
        ll_Stack.display();
        ll_Stack.push(4);
        ll_Stack.push(30);
        ll_Stack.push(3);
        ll_Stack.push(1);
        ll_Stack.display();
        auto stop_time1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(stop_time1 - start_time1);
        linkedListStackVector.push_back(duration1.count());


        auto start_time = high_resolution_clock::now();

        arrayListStack al_Stack(15);
        al_Stack.push(8);
        al_Stack.push(10);
        al_Stack.push(5);
        al_Stack.push(11);
        al_Stack.push(15);
        al_Stack.push(23);
        al_Stack.push(6);
        al_Stack.push(18);
        al_Stack.push(20);
        al_Stack.push(17);
        al_Stack.display();
        al_Stack.pop();
        al_Stack.pop();
        al_Stack.pop();
        al_Stack.pop();
        al_Stack.pop();
        al_Stack.display();
        al_Stack.push(4);
        al_Stack.push(30);
        al_Stack.push(3);
        al_Stack.push(1);
        al_Stack.display();
        auto stop_time = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop_time - start_time);
        arrayStackVector.push_back(duration.count());
    }

    ofstream outputFile("output.txt");
    int sum = 0;
    for (const int& value : linkedListStackVector) {
        sum += value;
    }
    outputFile << "Linked List Average : " << sum / linkedListStackVector.size() << endl;

    sum = 0;

    for (const int& value : linkedListStackVector) {
        sum += value;
    }
    outputFile << "Array List Average : " << sum / arrayStackVector.size() << endl;
    outputFile.close();

    return 0;
}
