//Concatenate two given list into one big list.
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
public:
    Node* head;

public:
    LinkedList() {
        this->head = nullptr;
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
};

// Concatenate two lists into one
Node* concatenate(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }

    Node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = head2;
    return head1;
}

// Print the elements of a list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    LinkedList list1;
    LinkedList list2;

    cout << "Create List one:" << endl;
    cout << "Number of elements in list1: ";
    int n;
    cin >> n;//Input: 3
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "The value of node for list1: ";
        cin >> a[i]; // 1 2 3
        list1.insertAtEnd(a[i]);
    }

    cout << "\nCreate List two:" << endl;
    cout << "Number of elements in list2: ";
    int m;
    cin >> m; //Input: 4
    int b[m];
    for (int i = 0; i < m; i++) {
        cout << "The value of node for list2: ";
        cin >> b[i]; //Input: 4 5 6 7
        list2.insertAtEnd(b[i]);
    }

    // Concatenate the lists
    Node* concatenatedHead = concatenate(list1.head, list2.head);

    // Print the concatenated list
    cout << "Concatenated list: ";
    printList(concatenatedHead); //Output: 1 2 3 4 5 6 7

    return 0;
}
