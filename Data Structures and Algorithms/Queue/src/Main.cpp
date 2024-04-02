#include <iostream>
using namespace std;

// Mendefinisikan struktur untuk node
struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

// Kelas untuk queue
class Queue {
private:
    Node* front; // Pointer untuk node depan
    Node* rear; // Pointer untuk node belakang
public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~Queue() {
        clear();
    }

    // Menambahkan elemen ke queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Menghapus elemen dari queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Mendapatkan elemen depan
    int getFront() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Memeriksa apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Membersihkan queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element is: " << q.getFront() << endl;
    
    q.dequeue();
    cout << "Front element is now: " << q.getFront() << endl;
    
    if(q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    
    return 0;
}