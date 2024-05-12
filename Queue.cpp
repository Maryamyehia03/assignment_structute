#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int numElements;

public:
    Queue() : head(nullptr), tail(nullptr), numElements(0) {}

    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(T data) {
        Node* newNode = new Node(data);

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        numElements++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        T data = head->data;
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        numElements--;

        return data;
    }

    T first() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        return head->data;
    }

    bool isEmpty() {
        return numElements == 0;
    }

    int queueSize() {
        return numElements;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        numElements = 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int x = 1;
    Queue<int> q;
    while (x)
    {
        cout << "Choose\n1.Push in queue\n2.Pop\n3.Size\n4.First\n5.Is_Empty\n6.clear\n7.print\n0.To Exist\n";
        cin >> x;
        if (x == 1)
        {
            int element;
            cout << "Enter element\n";
            cin >> element;
            q.enqueue(element);
            continue;
        }
        else if (x == 2) {
            cout << q.dequeue() << "\n";
        }
        else if (x == 3) {
            cout << q.queueSize() << "\n";
        }
        else if (x == 4) {
            cout << q.first() << "\n";
        }
        else if (x == 5) {
            if (q.isEmpty())
            {
                cout << "Empty\n";
            }
            else
                cout << "NOT Empty\n";
        }
        else if (x == 6) {
            q.clear();
        }
        else if (x == 7) {
            q.print();
            cout << "\n";
        }
        else if (x == 0) {
            break;
        }


    }
    return 0;


}
