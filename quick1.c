#include <stdio.h>
// #include <conio.h> // Remove this header if not using getch()

void qs(int a[], int lb, int ub) {
    int pivot = lb, temp, l = lb, u = ub;
    
    // Base case: if the lower bound is greater or equal to upper bound, return
    if (lb >= ub) {
        return;
    }

    // Partitioning the array
    while (lb < ub) {
        // Find the element greater than pivot on the left
        while (a[lb] <= a[pivot] && lb < u) {
            lb++;
        }
        // Find the element less than or equal to pivot on the right
        while (a[ub] > a[pivot] && ub > l) {
            ub--;
        }

        // If lb is still less than ub, swap the elements
        if (lb < ub) {
            temp = a[lb];
            a[lb] = a[ub];
            a[ub] = temp;
        }
    }

    // Swap the pivot element with the element at the ub index
    temp = a[pivot];
    a[pivot] = a[ub];
    a[ub] = temp;

    // Recursively sort the two halves of the array
    qs(a, l, ub - 1);
    qs(a, ub + 1, u);
}

void printarray(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int size, a[20], i = 0;

    // Get number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Ensure the size doesn't exceed the array limit
    if (size > 20) {
        printf("Size exceeds the maximum array limit of 20!\n");
        return 1;
    }

    // Get array elements from user
    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    // Print original array
    printf("Original array: ");
    printarray(a, size);

    // Sort the array using quicksort
    qs(a, 0, size - 1);

    // Print sorted array
    printf("Sorted array: ");
    printarray(a, size);

    getchar();  // Replacing getch() with getchar() for portability
    return 0;
}