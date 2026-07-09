#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


void bubblesort(int *arr , int n){
	for(int i=0;i<n-1;i++){
		int swapped = 0;
		for(int j = 0 ; j < n-i-1;j++){
			if(arr[j] >  arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if(swapped == 0) break;
	}
}


void selectionsort( int *arr, int n){
	for(int i=0;i<n;i++){
		int min = i;
		for(int j = i+1 ; j < n ;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void insertionSort(int *arr , int n){
	for(int i=0; i<n;i++){
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]){
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}


void merge(int *arr , int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* l = (int *) malloc(n1 * sizeof(int));
	int* r = (int *) malloc(n2 * sizeof(int));   

	for(int i=0;i < n1 ;i++){
		l[i] = arr[left +i];
	}
	for(int i = 0;i<n2;i++){
		r[i] = arr[mid+1 + i];
	}

	int i =0;
	int j =0;
	int k = left;

	while(i < n1 && j < n2){
		if(l[i] <= r[j]){
			arr[k] = l[i];
			i++;
		}
		else{
			arr[k] = r[j];
			j++;
		}
		k++;
	}
	while(i <n1){
		arr[k++] = l[i++];   
	}
	while(j < n2){
		arr[k++] = r[j++];
	}
	free(l);
	free(r);
}

void mergeSort(int *arr , int left, int right){
	if(left < right){
		int mid = left + (right-left)/2 ;
		mergeSort(arr,left ,mid);
		mergeSort(arr,mid+1 , right);
		merge(arr,left, mid, right);
	}
}


int partition(int *arr, int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}

void quickSort(int *arr, int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}


void heapify(int *arr, int n, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

void heapSort(int *arr, int n){

	for(int i = n/2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}

	for(int i = n-1; i > 0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}


void generateRandom(int *arr, int n){
	for(int i=0;i<n;i++){
		arr[i] = rand() % 1000000;
	}
}

void generateAscending(int *arr, int n){
	for(int i=0;i<n;i++){
		arr[i] = i;
	}
}

void generateDescending(int *arr, int n){
	for(int i=0;i<n;i++){
		arr[i] = n - i;
	}
}

int main(){
	srand(time(NULL));

	int sizes[8];
	int base = 8000, step = 4000;
	for(int i=0;i<8;i++){
		sizes[i] = base + i*step;
	}

	const char* orderNames[3] = {"Random", "Ascending", "Descending"};

	printf("Order,Size,Bubble,Selection,Merge,Quick\n");

	for(int order = 0; order < 3; order++){
		for(int s = 0; s < 8; s++){
			int n = sizes[s];
			int *base_arr = (int *) malloc(n * sizeof(int));
			int *arr = (int *) malloc(n * sizeof(int));
			clock_t start, end;

			if(order == 0) generateRandom(base_arr, n);
			else if(order == 1) generateAscending(base_arr, n);
			else generateDescending(base_arr, n);

			// ---- Bubble ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			bubblesort(arr, n);
			end = clock();
			double tBubble = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			// ---- Selection ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			selectionsort(arr, n);
			end = clock();
			double tSelection = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			// ---- Insertion ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			insertionSort(arr, n);
			end = clock();
			double tInsertion = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			// ---- Merge ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			mergeSort(arr, 0, n-1);
			end = clock();
			double tMerge = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			// ---- Quick ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			quickSort(arr, 0, n-1);
			end = clock();
			double tQuick = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			// ---- Heap ----
			memcpy(arr, base_arr, n * sizeof(int));
			start = clock();
			heapSort(arr, n);
			end = clock();
			double tHeap = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

			printf("%s,%d,%.3f,%.3f,%.3f,%.3f\n",
				orderNames[order], n, tBubble, tSelection, tMerge, tQuick);

			free(base_arr);
			free(arr);
		}
	}

	return 0;
}
