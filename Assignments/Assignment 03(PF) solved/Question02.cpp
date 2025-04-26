#include <iostream>
#include <fstream>

using namespace std;

const int Size = 100;
bool is_digit(char ch);
int performOperation(int num1, int num2, char operation);
int calculate_length(char* equation_Ptr);
int solve_expression(char* equation_ptr, int length);

int main() {
    ifstream inputFile("Expression.txt");
    char equation[Size];

    while (inputFile.getline(equation, Size)) {
        int length = calculate_length(equation);
        int result;

        if (length > 0) {
            result = solve_expression(equation, length);
            cout << equation << " = " << result << endl;
        }
    }

    inputFile.close();
    return 0;
}


// Function to check if a character is a digit
bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

// Function to perform arithmetic operations
int performOperation(int num1, int num2, char operation) {
    switch (operation) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}

// Function to calculate the length of Equation
int calculate_length(char* equation_Ptr) {
    int length = 0;
    while (equation_Ptr[length] != '\0') {
        length++;
    }
    return length;
}

// Function to solve an equation
int solve_expression(char* equation_ptr, int length) {
    int numbers[Size];  // Array to store numbers
    char operators[Size];  // Array to store operators
    int numTop = -1, opTop = -1;  // Indices for numbers and operators arrays

    for (int i = 0; i < length; i++) {
        if (equation_ptr[i] == ' ') {
            continue;  // Skip spaces
        }

        if (is_digit(equation_ptr[i])) {
            int num = 0;
            while (i < length && is_digit(equation_ptr[i])) {
                num = num * 10 + (equation_ptr[i] - '0');
                i++;
            }
            numbers[++numTop] = num;  // Store the number
            i--;  // Decrement i to process the next character
        }
        else if (equation_ptr[i] == '(') {
            operators[++opTop] = equation_ptr[i];  // Store the '(' operator
        }
        else if (equation_ptr[i] == ')') {
            while (opTop >= 0 && operators[opTop] != '(') {
                int num2 = numbers[numTop--];  // Cut the second operand
                int num1 = numbers[numTop--];  // Cut the first operand
                char op = operators[opTop--];  // Cut the operator
                numbers[++numTop] = performOperation(num1, num2, op);  // Perform the operation and store the result
            }
            opTop--;  // Decrement opTop to ignore the '(' operator
        }
        else {
            while (opTop >= 0 && operators[opTop] != '(' &&
                ((equation_ptr[i] == '+' || equation_ptr[i] == '-') ||
                    (equation_ptr[i] == ' ' || equation_ptr[i] == '/') &&
                    (operators[opTop] == ' ' || operators[opTop] == '/'))) {
                int num2 = numbers[numTop--];  // Cut the second operand
                int num1 = numbers[numTop--];  // Cut the first operand
                char op = operators[opTop--];  // Cut the operator
                numbers[++numTop] = performOperation(num1, num2, op);  // Perform the operation and store the result
            }
            operators[++opTop] = equation_ptr[i];  // Store the current operator
        }
    }

    // Process any remaining operators
    while (opTop >= 0) {
        int num2 = numbers[numTop--];  // Cut the second operand
        int num1 = numbers[numTop--];  // Cut the first operand
        char op = operators[opTop--];  // Cut the operator
        numbers[++numTop] = performOperation(num1, num2, op);  // Perform the operation and store the result
    }

    return numbers[numTop];  // Return the final result
}

