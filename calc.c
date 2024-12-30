#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char operator;
    int count, i;
    double result = 0, num;
    char choice[10], useSavedResult;
    int hasSavedResult = 0;

    do {
        if (hasSavedResult) {
            printf("Current result: %.2lf\n", result);
            printf("Do you want to use the saved result for the next calculation? (y/n): ");
            scanf(" %c", &useSavedResult);

            if (useSavedResult == 'n' || useSavedResult == 'N') {
                hasSavedResult = 0;
            }
        }

        if (!hasSavedResult) {
            printf("Enter a mathematical operator (+, -, *, /): ");
            scanf(" %c", &operator);

            printf("Enter the number of values: ");
            scanf("%d", &count);

            if (count < 2) {
                printf("Invalid Input. At least two numbers are required for a calculation.\n");
                continue;
            }

            printf("Enter %d values: ", count);
            for (i = 0; i < count; i++) {
                scanf("%lf", &num);

                if (i == 0) {
                    result = num;
                } else {
                    switch (operator) {
                        case '+':
                            result += num;
                            break;
                        case '-':
                            result -= num;
                            break;
                        case '*':
                            result *= num;
                            break;
                        case '/':
                            if (num != 0) {
                                result /= num;
                            } else {
                                printf("Error: Division by zero is not allowed.\n");
                                i = count;
                            }
                            break;
                        default:
                            printf("Error: Invalid operator.\n");
                            i = count;
                    }
                }
            }
        } else {
            printf("Enter an operator (+, -, *, /) to continue with the result: ");
            scanf(" %c", &operator);

            printf("Enter a number: ");
            scanf("%lf", &num);

            switch (operator) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    if (num != 0) {
                        result /= num;
                    } else {
                        printf("Error: Division by zero is not allowed.\n");
                    }
                    break;
                default:
                    printf("Error: Invalid operator.\n");
                    continue;
            }
        }

        printf("Result: %.2lf\n", result);
        hasSavedResult = 1;

        while (getchar() != '\n');

        printf("Do you want to perform another calculation? (Yes or No): ");
        fgets(choice, sizeof(choice), stdin);

        choice[strcspn(choice, "\n")] = 0;

    } while (choice[0] == 'y' || choice[0] == 'Y' || strcmp(choice, "yes") == 0 || strcmp(choice, "Yes") == 0 || strcmp(choice, "YES") == 0);

    printf("Thank you for using the calculator. Goodbye!\n");

    return 0;
}

