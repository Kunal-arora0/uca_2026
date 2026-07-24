#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int start, int mid, int end) {
  int size = end - start + 1;
  int inversionCount = 0;
  int temp[size];

  int i = start, j = mid + 1, idx = 0;

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      temp[idx++] = arr[i++];
    } else {
      inversionCount += mid - i + 1;
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

  return inversionCount;
}

int mergeSort(int arr[], int start, int end) {
  int inversionCount = 0;
  if (start >= end) return inversionCount;

  int mid = start + (end - start) / 2;

  inversionCount += mergeSort(arr, start, mid);
  inversionCount += mergeSort(arr, mid + 1, end);
  inversionCount += merge(arr, start, mid, end);
  return inversionCount;
}

int main() {
  int arr[] = {1, 2, 4, 1, 3, 5};
  printf("%d", mergeSort(arr, 0, 5));
}
