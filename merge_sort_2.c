#include <stdio.h>

// merge two segments of width into b[]
void merge(int a[], int n, int left, int width, int b[]){
    int i, j, k;
    int right;

    right = left + width;
    for(i = 0, j = 0, k = left; i < width && j < width; k ++){
        if(left + i >= n) break;
        if(right + j >= n) break;
       
        if(a[left + i] < a[right + j]){
            b[k] = a[left+i];
            i ++;
        } else {
            b[k] = a[right + j];
            j ++;
        }
    }

    while(i < width && left + i < n) b[k++] = a[left + (i++)];
    while(j < width && right + j < n) b[k++] = a[right + (j++)];
}

// bottom-up merge sort
int merge_sort(int a[], int n, int b[]){
    int *original, *merged;
    int i, width;

    for(width = 1; width < n; width *= 2){
        // alternating a[] and b[]
        if((width / 2) % 2 == 0){
            original = a;
            merged = b;
        } else {
            original = b;
            merged = a;
        }
        
        // merge the n/(2*width) pairs
        for(i = 0; i < n; i += 2 * width){
            merge(original, n, i, width, merged);
        } 
    }
    return (original == a);
}

int main(){
    int i, result;
    int a[] = {5, 3, 1, 4, 2, 10, 7, 9}, b[8];
    int *merged;

    result = merge_sort(a, 8, b);

    if(result){
        merged = b;
    } else {
        merged = a;
    }

    for(i = 0; i < 8; i ++){
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
