#include <stdio.h>

int main() {
    int i, j;
    int size = 6; // Size of the letter Q pattern

    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            if ((i == 1 || i == size) && (j > 1 && j < size))
                printf("*");
            else if ((i > 1 && i < size) && (j == 1 || j == size))
                printf("*");
            else if (i == size / 2 + 1 && j > size / 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

