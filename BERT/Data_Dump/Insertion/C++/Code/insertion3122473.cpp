#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int *read_array(int n)
{
    int *array;
    int i,m;
    array = new int[n];
    for(i=0;i<n;i++){
        scanf("%d",&m);
        array[i] = m;
    }

    return array;
}

void print_array(int *array, int n)
{
    int i;
    for(i=0;i<n;i++){
        if(i!=n-1){
            printf("%d ",array[i]);
        }else{
            printf("%d",array[i]);
        }
    }
    printf("\n");
    return;
}

int main()
{
    int i,n,v,j;
    int *A;
    scanf("%d",&n);
    A = read_array(n);
    print_array(A,n);
    //printf("\n");
    
    for(i=1;i<n;i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print_array(A,n);
    }

    delete [] A;
    return 0;
}
