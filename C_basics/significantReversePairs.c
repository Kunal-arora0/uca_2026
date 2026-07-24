#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int start, int mid, int end) {
  int size = end - start + 1;

  int temp[size];
  int paircount = 0;

  int i = start, j = mid + 1, idx = 0;

  for (int i = start; i <= mid; i++) {
    while (j <= end && arr[i] > (2 * arr[j])) {
      j++;
    }
    paircount += j - (mid + 1);
  }

  i = start;
  j = mid + 1;

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      temp[idx++] = arr[i++];
    } else {
      temp[idx++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[idx++] = arr[i++];
  }

  while (j <= end) {
    temp[idx++] = arr[j++];
  }

  for (int i = 0; i < size; i++) {
    arr[i + start] = temp[i];
  }

  return paircount;
}

int mergeSort(int arr[], int start, int end) {
  if (start >= end) {
    return 0;
  }

  int mid = start + (end - start) / 2;
  int leftcount = mergeSort(arr, start, mid);
  int rightcount = mergeSort(arr, mid + 1, end);
  int currentcount = merge(arr, start, mid, end);
  return leftcount + rightcount + currentcount;
}
int main() {
  int arr[] = {2, 4, 3, 5, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("%d", mergeSort(arr, 0, n - 1));
}
