// Copyright 2021 NNTU-CS
int countPairsInRange(int *arr, int left, int right, int value) {
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    count += countPairsInRange(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int left = 0; left < right; left++) {
    count += countPairsInRange(arr, left + 1, right, value - arr[left]);
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int sumElem = value - arr[i];
    int index = binarySearch(arr, i + 1, len - 1, sumElem);
    if (index != -1 && arr[index] == sumElem) {
      count++;
    }
  }
  return count;
}
