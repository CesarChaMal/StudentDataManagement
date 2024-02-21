/*
Downloading SQLite binary. Go to sqlite.org/download.html, choose sqlite-tools-win32-x86-*******. ...

Copy binary to installation folder. Create a folder inside C:\Program Files named sqlite . ...

Add path for sqlite binary. ...

Verify Installation.

*/

#include <stdio.h>
#include <sqlite3.h> // Include the SQLite library header

// Define a simple structure for demonstration purposes
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function to insert a student into the SQLite database
int insertStudent(sqlite3* db, Student student) {
    char* errMsg = NULL;
    char sql[256];
    
    // Prepare the SQL statement to insert a student
    snprintf(sql, sizeof(sql), "INSERT INTO Students (Id, Name, Score) VALUES (%d, '%s', %f);",
             student.id, student.name, student.score);

    // Execute the SQL statement
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    return rc;
}

int main() {
    sqlite3* db;
    char* errMsg = NULL;
    int rc;

    // Open connection to a new or existing SQLite database
    rc = sqlite3_open("students.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    // Create the Students table
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS Students
