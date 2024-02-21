/*
Downloading SQLite binary. Go to sqlite.org/download.html, choose sqlite-tools-win32-x86-*******. ...

Copy binary to installation folder. Create a folder inside C:\Program Files named sqlite . ...

Add path for sqlite binary. ...

Verify Installation.

*/

#include <stdio.h>
#include <sqlite3.h>

void queryStudents(sqlite3* db) {
    sqlite3_stmt *stmt;
    const char* sqlSelect = "SELECT Id, Name, Score FROM Students WHERE Score > ?;";

    // Prepare the SQL statement
    if (sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, NULL) == SQLITE_OK) {
        // Bind the score threshold to the prepared statement
        sqlite3_bind_double(stmt, 1, 85.0); // Example: Query students with scores above 85

        // Execute the query and iterate over the results
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *name = sqlite3_column_text(stmt, 1);
            double score = sqlite3_column_double(stmt, 2);

            printf("ID: %d, Name: %s, Score: %.2f\n", id, name, score);
        }

        // Finalize the statement to release resources
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    }
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
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS Students ("
                                 "Id INTEGER PRIMARY KEY, "
                                 "Name TEXT NOT NULL, "
                                 "Score REAL);";

    rc = sqlite3_exec(db, sqlCreateTable, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    // Here you might insert students into the database before querying
    // For example, you could call a function similar to insertStudent() shown in previous examples

    // Query the database for students with scores greater than 85
    queryStudents(db);

    // Close the database connection
    sqlite3_close(db);

    return 0;
}
