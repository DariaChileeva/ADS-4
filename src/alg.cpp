// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int *arr, int size, int value) {
    int left = 0, count = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            count++;
            int iPer = mid - 1;
            while (iPer >= 0 && arr[iPer] == value) {
                count++;
                iPer--;
            }
            iPer = mid + 1;
            while (iPer < size && arr[iPer] == value) {
                count++;
                iPer++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int bPer = 0;
    for (int i = 0; i < len; i++) {
        bPer = cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return bPer;
}
