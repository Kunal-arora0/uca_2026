#include <stdio.h>

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapifyDown(int arr[], int index, int size) {
  if (index == size - 1) return;

  int largest = index;

  int lchild = 2 * index + 1;
  int rchild = 2 * index + 2;

  if (lchild < size && arr[lchild] > arr[largest]) {
    largest = lchild;
  }
  if (rchild < size && arr[rchild] > arr[largest]) {
    largest = rchild;
  }

  if (largest != index) {
    swap(arr, index, largest);
    heapifyDown(arr, largest, size);
  }
}

void buildMaxHeap(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapifyDown(arr, i, size);
  }
}

void heapSort(int arr[], int size) {
  while (size > 1) {
    swap(arr, 0, size - 1);
    size--;
    heapifyDown(arr, 0, size);
  }
}

int main() {
  int arr[5] = {5, 3, 1, 6, 2};

  buildMaxHeap(arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n%s", "Sorted Array->  ");

  heapSort(arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
}
