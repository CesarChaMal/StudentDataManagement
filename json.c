#include <stdio.h>

// Define a simple structure for demonstration purposes
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function to write an array of Student structures to a JSON file
void writeStudentsToJSON(const char* filename, Student* students, int numStudents) {
    FILE* file = fopen(filename, "w"); // Open the file for writing
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Start of the JSON array
    fprintf(file, "[\n");

    // Loop through the array and write each student's data as a JSON object
    for (int i = 0; i < numStudents; ++i) {
        fprintf(file, "  {\n");
        fprintf(file, "    \"id\": %d,\n", students[i].id);
        fprintf(file, "    \"name\": \"%s\",\n", students[i].name);
        fprintf(file, "    \"score\": %.2f\n", students[i].score);
        if (i < numStudents - 1) {
            fprintf(file, "  },\n"); // Comma after all but the last student object
        } else {
            fprintf(file, "  }\n"); // No comma after the last student object
        }
    }

    // End of the JSON array
    fprintf(file, "]\n");

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

    writeStudentsToJSON("students.json", students, numStudents);

    return 0;
}
