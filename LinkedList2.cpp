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

void insert_sorted(Node** head, Node* element) {
    if (*head == nullptr || element->value < (*head)->value) {
        element->next = *head;
        *head = element;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr && current->next->value < element->value) {
        current = current->next;
    }

    element->next = current->next;
    current->next = element;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements in sorted order
    int n;
    cout<<"Enter the number of elements want to put in LL"<<" ";
    cin>>n;//Input: 6
    int a[n];
    for(int i=0 ;i<n ;++i){
        cout<<"Enter the value of Node:"<<" ";
        cin>>a[i]; //Input: 3 6 1 0 2 7
        insert_sorted(&head, new Node(a[i]));
    }
    printList(head); //Input: 0 1 2 3 6 7

    return 0;
}
