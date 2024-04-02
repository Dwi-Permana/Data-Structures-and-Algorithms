//inserting a node when the linked list in empaty
//inserting a node to the tail
//Deleting a tail

#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;
    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        }
        else {
            Node* tmp = head;
            head = node;
            head->next = tmp;
        }
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    void deleteTail() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            cout << "Deleted the only node in the list. List is now empty." << endl;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        current->next = NULL;
        tail = current;
        cout << "Deleted tail node successfully." << endl;
    }

    void printAll() {
        Node* tmp = head;

        while (tmp != NULL) {
            cout << tmp->id << "->";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(int argc, char** argv) {
    LinkedList* list1 = new LinkedList();

    // Inserting nodes to test functionalities
    list1->insertToHead('A');
    list1->insertToTail('B');
    list1->printAll(); // Output: A->B->NULL

    // Deleting tail node
    list1->deleteTail();
    list1->printAll(); // Output: A->NULL

    // Inserting a node to the head of an empty list
    list1->insertToHead('X');
    list1->printAll(); // Output: X->NULL

    // Inserting a node to the tail
    list1->insertToTail('Y');
    list1->printAll(); // Output: X->Y->NULL

    return 0;
}


/*
#include <iostream>
using namespace std;

class Node{
    public:
        char id;
        Node *next;
        Node(){
            next = NULL;
        }
};
class LinkedList{
    public:
        Node *head;
        Node *tail;
        LinkedList(){
            head = tail = NULL;
        }
        void insertToHead(char data){
            Node *node = new Node();
            node->id = data;

            if (head==NULL){
                head = node;
                tail = node;
            }else{
                Node *tmp = head;
                head = node;
                head->next = tmp;
            }
        }
        void insertToTail(char data){
            Node *node = new Node();
            node->id = data;

            if (head==NULL){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
        }
        void printAll(){
            Node *tmp = head;

            while (tmp!=NULL)
            {
                cout << tmp->id << "->";
                tmp = tmp->next;
            }
            
        }
        
};
int main(int argc, char** argv) {   
    LinkedList *list1 = new LinkedList();

    Node *node1 = new Node();
    node1->id = 'A';

    list1->head = node1;
    list1->tail = node1;

    cout << list1 << endl;
    cout << list1->head->id << endl << endl;

    cout << list1->head << endl;
    cout << node1 << endl;
    cout << list1->tail << endl;

    Node *node2 = new Node();
    node2->id = 'B';

    list1->tail->next = node2;
    list1->tail = node2;

    cout << list1->head->id << endl;
    cout << list1->tail->id << endl;

    Node *nodeX = new Node();
    nodeX->id = 'X';
    
     Node *tmp = list1->head;
     list1->head = nodeX;
     list1->head->next = tmp;

     cout << list1->head->id << endl;
     cout << list1->tail->id << endl;

     list1->insertToHead('Y');
     list1->insertToTail('C');

     cout << list1->head->id << endl;
     cout << list1->tail->id << endl;
     
     list1->printAll();

    return 0;
}
*/