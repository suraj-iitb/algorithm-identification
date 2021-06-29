#include <stdio.h>

int A[100];
void dump(char *s, int len)
{   
    int i;
    for(i=0;i<len-1;i++)
    {
        printf("%d ",A[i]);
    }
    printf("%d\n",A[len-1]);
}

int main()
{
    int num,i,j;
    int key;

    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&A[i]);
    }
    dump(A,num);
    
    for(i=1;i<num;i++)
    {
        key = A[i];
        j=i-1;
        while(j>=0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        dump(A,num);
    }
}
