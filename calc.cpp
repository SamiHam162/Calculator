#include <iostream>
#include <limits>

using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return numeric_limits<double>::quiet_NaN(); // Return NaN
    }
    return a / b;
}

int main() {
    double num1, num2;
    char operation;
    bool keepRunning = true;

    cout << "Simple Calculator" << endl;
    cout << "Available operations: +, -, *, /" << endl;

    while (keepRunning) {
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (operation) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Error: Invalid operator." << endl;
                break;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            keepRunning = false;
        }
    }

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
