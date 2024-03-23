// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int cbinsearch(int *arr, int size, int value) {
    int left = 0, counter = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
        } else if (arr[mid] > value) {
            right = mid - 1;
        } else {
            counter++;
            int iPer = mid - 1;
            mid++;
            while (arr[mid] == value) {
                counter++;
                mid++;
            }
            while (arr[iPer] == value) {
                counter++;
                iPer--;
            }
            break;
        }
    }
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int counter, i = 0;
    while (arr[i] <= (value / 2) - 1) {
        int bPer = value - arr[i];
        counter += cbinsearch(arr, len, bPer);
        i++;
    }
    int mid = cbinsearch(arr, len, value / 2);
    counter += mid * (mid - 1) / 2;
    return counter;
}
