// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        a++;
    }
  }
  return a;
}

int countPairs2(int *arr, int len, int value) {
  iny a = 0;
  int left = 0; 
  int right = len - 1;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (arr[mid] <= value)
      left = mid;
    else
      right = mid;
  }
  len = right - 1;
  for (int i = len; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == value)
        a++;
      if (arr[i] + arr[j] > value)
        break;
    }
  }
  return a;
}

int countPairs3(int *arr, int len, int value) {
  int a = 0;
  int left = 0;
  int right = len - 1;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (arr[mid] <= value)
      left = mid;
    else
      right = mid;
  }
  len = right - 1;
  for (int i = 0; i <len; i++) {
    left = i+1, right = len - 1;
    int b = 0;
    while (left < right) {
      int middle = (left + right) / 2;
      if (arr[middle] < (value - arr[i]))
        left = middle + 1;
      else
        right = middle;
    }
    while (arr[left] == (value - arr[i])) {
      b++;
      left++;
    }
    a += b;
}
  return a;
}
