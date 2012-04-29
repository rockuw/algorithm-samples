#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// adjust max-heap
void heapify(int a[], int i, int n){
    int left = 2 * i + 1, right = left + 1;
    int largest = i;
    
    if(left < n && a[i] < a[left]){
        largest = left;
    }

    if(right < n && a[largest] < a[right]){
        largest = right;
    }

    if(largest == i) return;
    else {
        swap(&a[i], &a[largest]);
        heapify(a, largest, n);
    }
}

// build max-heap
void build_heap(int a[], int n){
    int i;
    for(i = n / 2 - 1; i >= 0; i --){
        heapify(a, i, n);
    }
}

// heap sort
void heap_sort(int a[], int n){
    int i, exchange;

    build_heap(a, n);
    for(i = n; i > 0; i --){
        swap(&a[0], &a[i-1]);
        heapify(a, 0, i-1);
    }
}

int main(){
    int i;
    int arr[] = {3, 5, 7, 100, 1};

    heap_sort(arr, 5);

    for(i = 0; i < 5; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
