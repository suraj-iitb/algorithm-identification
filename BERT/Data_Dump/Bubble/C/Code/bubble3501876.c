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


int bubble_sort(int a[], int length)
{
    int swap_num = 0;
    for(int i=0; i<length; i++){
        //for(int j=0; j<length-i; j++){
        for(int j=length-1; j>=i+1; j--){
            if(a[j] < a[j-1]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                swap_num++;
            }
        }
    }
    return swap_num;
}

int main(){
    int data_length, arr[110];
    scanf("%d", &data_length);
    for(int i=0; i<data_length; i++){
        scanf("%d", &arr[i]);
    }
    int swap = bubble_sort(arr, data_length);
    print_array(arr, data_length);
    printf("%d\n", swap);
}

