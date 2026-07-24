#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Node;

void merge(Node arr[], int left, int mid, int right, int ans[]) {
    int n = right - left + 1;
    Node *temp = (Node *)malloc(n * sizeof(Node));

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(Node arr[], int left, int right, int ans[]) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, ans);
    mergeSort(arr, mid + 1, right, ans);
    merge(arr, left, mid, right, ans);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Node arr[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, 0, n - 1, ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
