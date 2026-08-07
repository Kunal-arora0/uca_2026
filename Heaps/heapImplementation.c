#include <stdio.h>
int size = 0;

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void heapifyUp(int arr[], int index) {
  if (index == 0) return;
  int parent = (index - 1) / 2;

  if (arr[parent] > arr[index]) {
    swap(arr, parent, index);
    heapifyUp(arr, parent);
  }
}

void heapifyDown(int arr[], int index) {
  if (index >= size) {
    return;
  }
  int smallest = index;

  int leftchild = 2 * index + 1;
  int rightchild = 2 * index + 2;

  if (leftchild < size && arr[leftchild] < arr[smallest]) {
    smallest = leftchild;
  }
  if (rightchild < size && arr[rightchild] < arr[smallest]) {
    smallest = rightchild;
  }

  if (smallest != index) {
    swap(arr, index, smallest);
    heapifyDown(arr, smallest);
  }
}

int deleteMin(int arr[]) {
  if (size == 0) return -1;

  int min = arr[0];
  swap(arr, 0, size - 1);
  size--;
  heapifyDown(arr, 0);

  return min;
}
void insertElement(int arr[], int element) {
  if (size >= 10) {
    printf("Array is full!");
    return;
  }

  arr[size] = element;
  heapifyUp(arr, size);
  size++;
}

int main() {
  int arr[10];
  insertElement(arr, 7);
  insertElement(arr, 5);
  insertElement(arr, 9);
  insertElement(arr, 1);
  insertElement(arr, 10);

  printf("%d", deleteMin(arr));
  printf("%d", deleteMin(arr));
  printf("%d", deleteMin(arr));
}
