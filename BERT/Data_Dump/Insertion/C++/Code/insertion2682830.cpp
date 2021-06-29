#include <stdio.h>
void print_array(int a[], int n){
int i = 0;
    for(i = 0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
}
//inserion sort 
void insertion_sort(int a[], int n){
    for(int i = 1; i<n; i++){
        int key = a[i];
        /* insert A[i] into the sorted sequence A[0,...,j-1] */
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
            
        }
        a[j+1] = key;
        print_array(a,n);
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[n+1];
    for(int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    print_array(a,n);
    insertion_sort(a,n);
    
    return 0;
}

