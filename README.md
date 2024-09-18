# Student-Management-System-Project

![Screenshot 2024-09-18 155452](https://github.com/user-attachments/assets/c9533de5-d0f7-4848-99ad-d396e43fac98)

# Features:

1. Add Student: Allows users to input new student information (name, ID, age, and GPA) and adds it to the linked list.

2. Display Students: Displays all students currently stored in the list, showing their details such as name, ID, age, and GPA.

3. Search Student by ID: Enables searching for a student by their ID. If found, it displays the student’s details.

4. Update Student Information: Finds a student by their ID and allows the user to update the student's details.

5. Delete Student: Deletes a student from the linked list by their ID.

6. Calculate Average GPA: Computes and returns the average GPA of all students in the system.

7. Search for Student with Highest GPA: Finds and displays the student with the highest GPA.


# Data Structures:

StudentInfo struct: Represents individual student details (ID, name, age, GPA).

Node struct: Forms the basis of the linked list. Each node contains a Student record and a pointer to the next node.


# Workflow:

The main loop presents a menu to the user, allowing them to choose from various options (add, search, update, delete students, calculate GPA, etc.). The program runs until the user selects the option to exit. Each function performs a specific task, handling operations related to student records.

The code uses dynamic memory allocation to create and manage nodes, ensuring efficient storage of student data. It also includes necessary error handling (e.g., preventing duplicate IDs and handling empty lists).

This project demonstrates fundamental data structures and algorithms in C, making it a simple yet effective educational tool for understanding linked lists and basic system design.
