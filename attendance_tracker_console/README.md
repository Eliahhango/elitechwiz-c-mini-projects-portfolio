# Attendance Tracker Console

## Assignment Information
- Institution: Dar es Salaam Institute of Technology
- Department: Civil Engineering Department
- Module Name: Programming Fundamentals for Technicians
- Module Code: GST 05117
- Class: OD24CE-2
- Assignment Type: Group
- Assignment No: 3
- Group Number: 11
- Submission Date: March 1, 2026

### Group Members
| No. | Student Name | Reg. Number |
|---|---|---|
| 1 | ABDULAZIZ MAHYORO | 240121429579 |
| 2 | LAWRENCE MMATAMBWE | 220121417491 |
| 3 | ELIAH HANGO | 240121476067 |
| 4 | HUSSEIN OMARY | 240121449049 |
| 5 | ROBERT JAMES | 240121479897 |
| 6 | GIDEON OLANG'U | 240121429421 |
| 7 | MOSES MFUSE | 24012317533 |
| 8 | GLORIA DAUDI | 240121453512 |

## Description
Menu-driven C program to register students, mark daily attendance, and show attendance percentage reports.

## Concepts Covered
- Input/Output (scanf, fgets, printf)
- Conditionals (if/else)
- Loops (while, for)
- Arrays and structs
- Functions and modular design
- Input validation

## Build
```bash
gcc main.c -o attendance_tracker_console
```

## Run
```bash
# Windows
.\attendance_tracker_console.exe
# Linux/macOS
./attendance_tracker_console
```

## Sample Output
```text
=== Attendance Tracker Console ===
1. Add Student
2. Mark Daily Attendance
3. View Attendance Report
4. Exit
Choose an option: 1
Enter student name: John Doe
Student added successfully.
Choose an option: 3
No.  Name                 Present    Total      Percent
1    John Doe             1          1          100.00%
```