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
