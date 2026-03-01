# Daily Expense Tracker

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
Menu-driven expense tracker for recording category, note, amount, and summary statistics.

## Concepts Covered
- Arrays and structs
- Input/Output
- Loops and conditionals
- Functions
- Numeric aggregation

## Build
```bash
gcc main.c -o daily_expense_tracker
```

## Run
```bash
# Windows
.\daily_expense_tracker.exe
# Linux/macOS
./daily_expense_tracker
```

## Sample Output
```text
=== Daily Expense Tracker ===
1. Add Expense
2. View All Expenses
3. Summary
4. Exit
Choose an option: 1
Enter category (Food/Transport/Utilities/Other): Food
Enter note: Lunch
Enter amount: 12.50
Expense saved.
Choose an option: 3
Total Spending: 12.50
```