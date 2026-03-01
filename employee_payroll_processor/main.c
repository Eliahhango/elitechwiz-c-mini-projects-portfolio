/*
DAR ES SALAAM INSTITUTE OF TECHNOLOGY
CIVIL ENGINEERING DEPARTMENT

Module Name: Programming Fundamentals for Technicians
Module Code: GST 05117
Class: OD24CE-2
Assignment Type: Group
Assignment No: 3
Group Number: 11
Submission Date: March 1, 2026

Group Members:
1. ABDULAZIZ MAHYORO - 240121429579
2. LAWRENCE MMATAMBWE - 220121417491
3. ELIAH HANGO - 240121476067
4. HUSSEIN OMARY - 240121449049
5. ROBERT JAMES - 240121479897
6. GIDEON OLANG'U - 240121429421
7. MOSES MFUSE - 24012317533
8. GLORIA DAUDI - 240121453512
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float baseSalary;
    float overtimeHours;
    float overtimeRate;
    float taxRate;
    float netSalary;
} Employee;

/* Utility: clears leftover input from stdin buffer. */
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int findEmployeeIndex(const Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

float calculateNetSalary(Employee *employee) {
    float overtimePay = employee->overtimeHours * employee->overtimeRate;
    float gross = employee->baseSalary + overtimePay;
    float tax = gross * (employee->taxRate / 100.0f);
    employee->netSalary = gross - tax;
    return employee->netSalary;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    Employee employee;

    printf("Enter employee ID: ");
    if (scanf("%d", &employee.id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }
    clearInput();

    if (findEmployeeIndex(employees, *count, employee.id) != -1) {
        printf("Employee ID already exists.\n");
        return;
    }

    printf("Enter employee name: ");
    if (fgets(employee.name, sizeof(employee.name), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    employee.name[strcspn(employee.name, "\n")] = '\0';

    printf("Enter base salary: ");
    if (scanf("%f", &employee.baseSalary) != 1 || employee.baseSalary < 0.0f) {
        printf("Invalid base salary.\n");
        clearInput();
        return;
    }

    printf("Enter overtime hours: ");
    if (scanf("%f", &employee.overtimeHours) != 1 || employee.overtimeHours < 0.0f) {
        printf("Invalid overtime hours.\n");
        clearInput();
        return;
    }

    printf("Enter overtime hourly rate: ");
    if (scanf("%f", &employee.overtimeRate) != 1 || employee.overtimeRate < 0.0f) {
        printf("Invalid overtime rate.\n");
        clearInput();
        return;
    }

    printf("Enter tax rate (percentage): ");
    if (scanf("%f", &employee.taxRate) != 1 || employee.taxRate < 0.0f || employee.taxRate > 100.0f) {
        printf("Invalid tax rate.\n");
        clearInput();
        return;
    }
    clearInput();

    calculateNetSalary(&employee);
    employees[*count] = employee;
    (*count)++;

    printf("Employee payroll record added. Net Salary: %.2f\n", employee.netSalary);
}

void listEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n%-6s %-20s %-10s %-10s %-10s %-10s %-10s\n",
           "ID", "Name", "Base", "OT Hours", "OT Rate", "Tax%", "Net");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].baseSalary,
               employees[i].overtimeHours,
               employees[i].overtimeRate,
               employees[i].taxRate,
               employees[i].netSalary);
    }
}

/* Keeps the console window open so output can be read before exit. */
void pauseBeforeExit(void) {
    system("pause");
}
/* Main function: handles user interaction and program flow. */
int main(void) {
    atexit(pauseBeforeExit);
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Employee Payroll Processor ===\n");
        printf("1. Add Employee Payroll Record\n");
        printf("2. View Payroll Report\n");
        printf("3. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                listEmployees(employees, count);
                break;
            case 3:
                printf("Exiting payroll processor.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}
