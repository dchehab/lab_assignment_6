/*#include <stdio.h>

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

    int i, numInputs;
    char* str;
    float average



    // Read input from input.txt
    FILE *file = fopen("input.txt", "r");

    int n;
    fscanf(file, "%d", &n); // Read the number of elements in the array

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        fscanf(file, "%d", &numbers[i]); // Read the array elements
    }

    int value;
    fscanf(file, "%d", &value); // Read the target value

    fclose(file);

    // Perform binary search
    int result = search(numbers, 0, n - 1, value);

    if (result != -1) {
        printf("Value %d found at index %d.\n", value, result);
    } else {
        printf("Value %d not found in the array.\n", value);
        return -1;

    }

    return 0;
}*/

#include <stdio.h>

int search(int numbers[], int low, int high, int value)
{
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
