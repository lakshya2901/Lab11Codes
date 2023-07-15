//Creating a LinkedList for student
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud {
    int roll;
    char name[25];
    int age;
    struct stud* next;
};

// Function to create a new student node
struct stud* createStudent(int roll, char* name, int age) {
    struct stud* newStudent = (struct stud*)malloc(sizeof(struct stud));
    newStudent->roll = roll;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = NULL;
    return newStudent;
}

// Function to traverse and print the student list
void traverseStudents(struct stud* head) {
    struct stud* current = head;
    while (current != NULL) {
        printf("Roll: %d, Name: %s, Age: %d\n", current->roll, current->name, current->age);
        current = current->next;
    }
}

// Function to insert a new student at the beginning of the list
void insertStudent(struct stud** head, struct stud* newStudent) {
    newStudent->next = *head;
    *head = newStudent;
}

// Function to delete a student with a given roll number from the list
void deleteStudent(struct stud** head, int roll) {
    struct stud* current = *head;
    struct stud* prev = NULL;

    // Traverse the list to find the student with the given roll number
    while (current != NULL && current->roll != roll) {
        prev = current;
        current = current->next;
    }

    // If the student is found then remove it from the list
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Function to free the memory occupied by the student list
void freeStudents(struct stud** head) {
    struct stud* current = *head;
    struct stud* nextStudent;

    while (current != NULL) {
        nextStudent = current->next;
        free(current);
        current = nextStudent;
    }

    *head = NULL;
}

int main() {
    // Create sample students
    struct stud* student1 = createStudent(1, "Lakshya", 19);
    struct stud* student2 = createStudent(2, "Abhijit", 20);
    struct stud* student3 = createStudent(3, "Madan", 19);
    struct stud* student4 = createStudent(4, "Suryansh", 21);
    

    // Initialize the head of the student list
    struct stud* head = NULL;

    // Insert students into the list
    insertStudent(&head, student1);
    insertStudent(&head, student2);
    insertStudent(&head, student3);
    insertStudent(&head, student4);

    // Traverse and print the student list
    printf("Students:\n");
    traverseStudents(head);

    // Delete student with roll number 3
    deleteStudent(&head, 3);

    // Traverse and print the updated student list
    printf("After deletion:\n");
    traverseStudents(head);

    // Free the memory occupied by the student list
    freeStudents(&head);

    return 0;
}
