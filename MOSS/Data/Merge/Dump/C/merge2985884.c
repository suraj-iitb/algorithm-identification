#include <stdio.h>
#include <stdlib.h>

void printArray(int,int[]);
int merge(int,int[],int,int,int);
int merge_sort(int,int[],int,int);

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    int array[size];
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    
    int returnVal = merge_sort(size, array, 0, size);
    printArray(size, array);
    printf("%d\n", returnVal);
    
    return (EXIT_SUCCESS);
}

int merge(int size, int a[size], int left, int mid, int right){
    int count = 0;
    int i = 0;
    int j = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    int lArray[n1], rArray[n2];
    for(; i < n1; i++)
        lArray[i] = a[left + i];
    for(; j < n2; j++)
        rArray[j] = a[mid + j];
    i = 0;
    j = 0;
    for(int k = left; k < right; k++){
        if(i < n1 && lArray[i] <= rArray[j] || j >= n2)
            a[k] = lArray[i++];
        else
            a[k] = rArray[j++];
        count++;
    }
    return count;
}

int merge_sort(int size, int a[size], int left, int right){
    int count = 0;
    if(left+1 < right){
        int mid = (left + right)/2;
        count += merge_sort(size, a, left, mid);
        count += merge_sort(size, a, mid, right);
        count += merge(size, a, left, mid, right);
        //printArray(size, a);
    }
    return count;
}

void printArray(int size, int a[size]){
    for(int i = 0; i < size; i++){
        if(i != size - 1)
            printf("%d ", a[i]);
        else printf("%d\n", a[i]);
    }
}
