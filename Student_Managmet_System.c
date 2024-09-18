/*
 ============================================================================
 Name        : Student_Managmet_System.c
 Author      : Medhat Adel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addStudent(void);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
void deleteStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);

void printMenu(void);
int getUserChoice(void);

typedef struct StudentInfo {
    int id;
    char name[40];
    short age;
    float gpa;
} Student;

typedef struct Node {
    Student data;         // Data of the student
    struct Node *next;    // Pointer to the next node
} Node;

// Head of the linked list
Node *head = NULL;

int main(void) {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice = 0;

    printf("====================== Welcome To Our Student Management System ======================\n");


    while (choice != 8) {
        printMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchStudentByID(id);
                break;
            }
            case 4: {
                int id;
                printf("Enter ID to update information: ");
                scanf("%d", &id);
                updateStudent(id);
                break;
            }
            case 5: {
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            }
            case 6:
                printf("Average GPA for students: %.2f\n", calculateAverageGPA());
                break;
            case 7:
                searchHighestGPA();
                break;
            case 8:
                printf("<THANK YOU>\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu(void) {
    printf("-------------------------------------------------------\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Update Student Information\n");
    printf("5. Delete Student\n");
    printf("6. Calculate Average GPA\n");
    printf("7. Search for Student with Highest GPA\n");
    printf("8. Exit\n");
    printf("-------------------------------------------------------\n");
}

int getUserChoice(void) {
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new student to the linked list
void addStudent(void) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) {
        printf("ERROR.\n");
        return;
    }

    printf("Enter Student Name: ");
    scanf("%s", newNode->data.name);

    printf("Enter Student ID: ");
    scanf("%d", &newNode->data.id);

    printf("Enter Student Age: ");
    scanf("%hd", &newNode->data.age);

    printf("Enter Student GPA: ");
    scanf("%f", &newNode->data.gpa);

    // Check if student ID already exists
    Node *current = head;
    while (current != NULL) {
        if (newNode->data.id == current->data.id) {
            printf("ID is reserved.\n");
            free(newNode); // Free memory if ID is already taken
            return;
        }
        current = current->next;
    }

    // Add new node to the end of the list
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode; // First node in the list
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a student by ID
void searchStudentByID(int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            printf("ID found.\n");
            printf("-Name: %s\n-ID: %d\n-Age: %hd\n-GPA: %.2f\n\n",
                   current->data.name, current->data.id, current->data.age, current->data.gpa);
            return;
        }
        current = current->next;
    }
    printf("ID not found.\n");
}

// Function to display all students in the list
void displayStudents(void) {
    if (head == NULL) {
        printf("No students to display.\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("-Name: %s\n-ID: %d\n-Age: %hd\n-GPA: %.2f\n\n",
               current->data.name, current->data.id, current->data.age, current->data.gpa);
        current = current->next;
    }
}

// Function to update student information by ID
void updateStudent(int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->data.id == id) {

            printf("Enter new Student Name: ");
            scanf("%s", current->data.name);

            printf("Enter new Student ID: ");
            scanf("%d", &current->data.id);

            printf("Enter new Student Age: ");
            scanf("%hd", &current->data.age);

            printf("Enter new Student GPA: ");
            scanf("%f", &current->data.gpa);
            return;
        }
        current = current->next;
    }
    printf("ID not found.\n");
}

// Function to calculate the average GPA of all students
float calculateAverageGPA(void) {
    if (head == NULL) {
        printf("No student records found.\n");
        return 0.0;
    }

    float sum = 0;
    int count = 0;
    Node *current = head;

    while (current != NULL) {
        sum += current->data.gpa;
        count++;
        current = current->next;
    }

    return (count == 0) ? 0.0 : (sum / count);
}

// Function to find and display the student with the highest GPA
void searchHighestGPA(void) {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    Node *current = head;
    float highestGPA = current->data.gpa;

    while (current != NULL) {
        if (current->data.gpa > highestGPA) {
            highestGPA = current->data.gpa;
        }
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        if (current->data.gpa == highestGPA) {
            printf("Student with highest GPA:\n");
            printf("-Name: %s\n-ID: %d\n-Age: %hd\n-GPA: %.2f\n\n",
                   current->data.name, current->data.id, current->data.age, current->data.gpa);
        }
        current = current->next;
    }
}

// Function to delete a student by ID
void deleteStudent(int id) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node *current = head;
    Node *prev = NULL;

    if (current != NULL && current->data.id == id) {
        head = current->next;
        free(current);
        printf("Student with ID <%d> deleted.\n", id);
        return;
    }

    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID <%d> not found.\n", id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student with ID <%d> deleted.\n", id);
}
