#include <stdio.h>

void print_array(int a[], int length)
{
    for(int i=0; i<length; i++){
        if(i==length-1)
            printf("%d\n", a[i]);
        else
            printf("%d ", a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int insertion_sort(int a[], int length)
{
    int swap_num = 0;
    for(int i=0; i<length; i++){
        int min_i = i;
        int swap_flag = 0;
        for(int j=i; j<length; j++){
            if(a[j] < a[min_i]){
                min_i = j;
                swap_flag = 1;
            }
        }
        swap(&a[i], &a[min_i]);
        if(swap_flag == 1) swap_num++;
    }
    return swap_num;
}

int main(){
    int data_length, arr[110];
    scanf("%d", &data_length);
    for(int i=0; i<data_length; i++){
        scanf("%d", &arr[i]);
    }
    int swap = insertion_sort(arr, data_length);
    print_array(arr, data_length);
    printf("%d\n", swap);
}
