//Always insert elements at one end, and delete elements from the other end 
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

// Insert an element at the end of the queue
void insert_q(Node** head, Node* element) {
    if (*head == nullptr) {
        *head = element;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = element;
    }
}

// Delete the first element from the queue and return it
Node* delete_q(Node** head) {
    if (*head == nullptr) {
        cout << "Queue is empty." << endl;
        return nullptr;
    }

    Node* temp = *head;
    *head = (*head)->next;
    temp->next = nullptr;
    return temp;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the queue
    insert_q(&head, new Node(1)); //Input: 1
    cout<<"Inserted Element:"<<"1"<<endl;

    insert_q(&head, new Node(2)); //Input: 2
    cout<<"Inserted Element:"<<"2"<<endl;

    insert_q(&head, new Node(3)); //Input: 3
    cout<<"Inserted Element:"<<"3"<<endl;

    cout<<"\n"<<endl;

    // Delete elements from the queue and print them
    Node* deletedNode1 = delete_q(&head);
    if (deletedNode1 != nullptr) {
        cout << "Deleted element: " << deletedNode1->value << endl;
        delete deletedNode1;
    }

    Node* deletedNode2 = delete_q(&head);
    if (deletedNode2 != nullptr) {
        cout << "Deleted element: " << deletedNode2->value << endl;
        delete deletedNode2;
    }

    Node* deletedNode3 = delete_q(&head);
    if (deletedNode3 != nullptr) {
        cout << "Deleted element: " << deletedNode3->value << endl;
        delete deletedNode3;
    }

    // Try to delete an element from an empty queue
    Node* deletedNode4 = delete_q(&head);
    if (deletedNode4 != nullptr) {
        cout << "Deleted element: " << deletedNode4->value << endl;
        delete deletedNode4;
    }

    return 0;
}
