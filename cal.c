#include <stdio.h>
#include <math.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char op;
    double num1, num2, result;

    while (1) {
        printf("\n=== C Calculator ===\n");
        printf("Enter an operator (+, -, *, /, %%, ^) or 'q' to quit: ");
        
        if (scanf(" %c", &op) != 1) {
            clearInputBuffer();
            continue;
        }

        if (op == 'q' || op == 'Q') {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // Validate operator before asking for numbers
        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
            printf("Error: Invalid operator '%c'. Please try again.\n", op);
            clearInputBuffer();
            continue;
        }

        printf("Enter two numbers separated by space: ");
        if (scanf("%lf %lf", &num1, &num2) != 2) {
            printf("Error: Invalid numeric input.\n");
            clearInputBuffer();
            continue;
        }

        switch (op) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '-':
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '*':
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case '%':
                if ((int)num2 == 0) {
                    printf("Error: Modulo by zero is undefined.\n");
                } else {
                    // Modulo requires integers in C
                    printf("Result: %d %% %d = %d\n", (int)num1, (int)num2, (int)num1 % (int)num2);
                }
                break;

            case '^':
                result = pow(num1, num2);
                printf("Result: %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;
        }
    }

    return 0;
}
