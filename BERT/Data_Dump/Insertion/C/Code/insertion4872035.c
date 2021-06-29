#include<stdio.h>
int main(){
    int size;
    scanf("%d",&size);
    int A[size];
    int key;
    int j=0;
    for (int i = 0; i < size;i++)
        scanf("%d",&A[i]);
    for (int i = 0; i < size;i++)
    {
        key = A[i];
        j = i - 1;
        while(j>=0 && key < A[j])
        {    
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = key;
        for (int x = 0; x < size-1;x++)
            printf("%d ",A[x]);
        printf("%d\n",A[size-1]);
    }
    
    return 0;
}
