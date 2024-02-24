
#include <stdio.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        // Base case
        return -1;
    }

    int mid = low + (high - low) / 2; // Calculate middle index

    if (numbers[mid] == value) {
        // Found the value at the middle index
        return mid;
    } else if (numbers[mid] < value) {
        // Value is in the right half
        return search(numbers, mid + 1, high, value);
    } else {
        // Value is in the left half
        return search(numbers, low, mid - 1, value);
    }
}

int main() {
    // Read input from input.txt
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int numArrays;
    fscanf(file, "%d", &numArrays); // Read the number of arrays

    for (int i = 0; i < numArrays; i++) {
        int arraySize;
        fscanf(file, "%d", &arraySize); // Read the number of elements in the array

        int numbers[arraySize];
        for (int j = 0; j < arraySize; j++) {
            fscanf(file, "%d", &numbers[j]); // Read the array elements
        }

        int value;
        fscanf(file, "%d", &value); // Read the target value

        // Perform binary search
        int result = search(numbers, 0, arraySize - 1, value);

        if (result != -1) {
            printf("Value %d found at index %d in array %d.\n", value, result, i + 1);
        } else {
            printf("Value %d not found in array %d.\n", value, i + 1);
        }
    }

    fclose(file);
    return 0;
}
