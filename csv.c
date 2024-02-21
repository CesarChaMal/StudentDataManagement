#include <stdio.h>

// Define a simple structure for demonstration purposes
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function to write an array of Student structures to a CSV file
void writeStudentsToCSV(const char* filename, Student* students, int numStudents) {
    FILE* file = fopen(filename, "w"); // Open the file for writing
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Write the header row
    fprintf(file, "ID,Name,Score\n");

    // Loop through the array and write each student's data as a CSV row
    for (int i = 0; i < numStudents; ++i) {
        fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].score);
    }

    fclose(file); // Close the file
}

int main() {
    // Example usage
    Student students[] = {
        {1, "Alice", 88.5},
        {2, "Bob", 92.3},
        {3, "Charlie", 79.4},
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    writeStudentsToCSV("students.csv", students, numStudents);

    return 0;
}

