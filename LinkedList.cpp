#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insert(int newValue, int beforeValue) {
        Node* newNode = new Node(newValue);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        Node* after = head;
        while (temp->value != beforeValue) {
            temp = temp->next;
        }
        after = temp->next;
        temp->next = newNode;
        newNode->next = after;
    }

    void deleteAtBeginning() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* temp = head;
        Node* pre = head;
        while (temp->next != nullptr) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        delete temp;
    }

    void deleteNode(int value) {
        if (head == nullptr)
            return;

        Node* temp = head;
        Node* pre = head;
        while (temp != nullptr && temp->value != value) {
            pre = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        pre->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Insert some nodes at the beginning of the list
    int n;
    cout << "Number of elements you want to insert at the beginning: ";
    cin >> n; //input: n=3
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value that you want to add: "; 
        cin >> a[i]; //input: 3 2 1
        list.insertAtBeginning(a[i]);
    }

    list.printList(); // Output: 1 2 3

    // Insert some nodes at the end of the list
    int m;
    cout << "Number of elements you want to insert at the end: ";
    cin >> m;//Input: 3
    int b[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter the value that you want to add: ";
        cin >> b[i];//input: 4 5 6
        list.insertAtEnd(b[i]);
    }
    list.printList(); // output: 1 2 3 4 5 6

    // Insert node after a specific value
    int beforeValue;
    cout << "\nInsert Node After Value\n";
    cin >> beforeValue; //input: 3

    int newValue;
    cout << "Node value you want to insert: ";
    cin >> newValue; //Input: 7
    list.insert(newValue, beforeValue);

    list.printList();//Output: 1 2 3 7 4 5 6

    cout<<"Delete a Node from beginning"<<endl;
    list.deleteAtBeginning();
    list.printList(); //Output: 2 3 7 4 5 6

    cout<<"Delete a Node at end"<<endl;
    list.deleteAtEnd();
    list.printList(); //Output: 2 3 7 4 5 

    cout<<"Delete a Node input"<<" ";
    int deleteValue;
    cin >> deleteValue; //Input: 7
    cout<<"\nLinkedList after removing that Node\n";
    list.deleteNode(deleteValue);
    list.printList(); //Output: 2 3 4 5 

    return 0;
}
