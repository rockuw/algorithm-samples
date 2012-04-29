#include <stdio.h>
#include <stdlib.h>

// merge left[] and right[] into b[]
void merge(int left[], int l_len, int right[], int r_len, int b[], int n){
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < l_len && j < r_len && k < n; k ++){
        if(left[i] < right[j]){
            b[k] = left[i];
            i ++;
        } else {
            b[k] = right[j];
            j ++;
        }
    }
    while(i < l_len) b[k++] = left[i++];
    while(j < r_len) b[k++] = right[j++];
}

// merge sort
// a[] is the original array, b[] is the merged array
void merge_sort(int a[], int n, int b[]){
    if(n <= 1) {
        b[0] = a[0];
        return;
    }

    int mid = n / 2;
    //int *left = (int *)malloc(sizeof(int) * mid);
    //int *right = (int *)malloc(sizeof(int) * (n-mid));
    int left[mid], right[n-mid];

    merge_sort(a, mid, left);
    merge_sort(a+mid, n-mid, right);
    merge(left, mid, right, n - mid, b, n);

   // free(left);
   // free(right);
}

int main(){
    int i;
    int arr[] = {5, 3, 1, 4, 2};
    int b[5];

    merge_sort(arr, 5, b);

    for(i = 0; i < 5; i ++){
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}
