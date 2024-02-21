# Student Data Management System

This project demonstrates the management of student data using C programming language, showcasing the ability to output data in CSV and JSON formats and store it in an SQLite database. It includes separate modules for each format, allowing users to understand how to manipulate and persist data using C.

## Project Structure

- `csv.c`: Writes student data to a CSV file.
- `json.c`: Writes student data to a JSON file.
- `sql_lite.c`: Demonstrates how to insert student data into an SQLite database.
- `sql_lite2.c`: Demonstrates querying student data from an SQLite database based on a score threshold.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) or any C compiler
- SQLite3

### Installation

1. **SQLite3**: Ensure SQLite3 is installed on your system. Follow the installation guide on the [SQLite official download page](https://sqlite.org/download.html).

2. **Compile the Code**: Use the following command to compile each source file. You need to link against the SQLite3 library for the SQLite examples.

```bash
gcc <source_file>.c -o <executable_name> $(pkg-config --cflags --libs sqlite3)
