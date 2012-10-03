#include <stdio.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// partition
int partition(int a[], int begin, int end){
    int i, j;
    int pivot;
   
    pivot = a[end - 1];
    // loop invariant: 
    // begin ~ i < pivot
    // i+1 ~ j-1 > pivot
    for(i = begin - 1, j = begin; j < end-1; j ++){
        if(a[j] < pivot){
            i ++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[end-1]);
    return i + 1;
}

void quick_sort(int a[], int begin, int end){
    int i;
    if(begin >= end) return;

    i = partition(a, begin, end);
    quick_sort(a, begin, i);
    quick_sort(a, i + 1, end);
}

int main(){
    int i;
    int arr[] = {3, 1, 7, 100, 5};

    quick_sort(arr, 0, 5);

    for(i = 0; i < 5; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
