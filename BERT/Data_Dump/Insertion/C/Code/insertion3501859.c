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

void insertion_sort(int a[], int length)
{
    print_array(a, length);
    for(int i=1; i<length; i++){
        //int j = i+1;
        int temp = a[i];
        int k;
        for(k=i-1; k>=0; k--){
            if(temp<a[k]){
                a[k+1] = a[k];
            }
            else{
                //a[k+1] = temp;
                break;
            }
        }
        a[k+1] = temp;
        print_array(a, length);
    }
}

int main()
{
    int data_length, arr[110];
    scanf("%d", &data_length);
    for(int i=0; i<data_length; i++){
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, data_length);
}

