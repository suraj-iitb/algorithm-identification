#include <stdio.h>
#include <time.h>
void insertionSort(int *p,int n);
int main ()
{
    int number,*p,i;
    scanf("%d",&number);
    p = (int *)malloc(number*sizeof(int));
    for(i = 0; i < number ; i++)
    {
        scanf("%d",&p[i]);
    }
    for(i = 0;i < number;i++)
    {
        if(i>0)
        printf(" ");
        printf("%d",p[i]);
    }
    printf("\n");
    insertionSort(p,number);
    free(p);
    return 0;
}
void insertionSort(int *p,int n)
{
    int i,j,v;
    for(i = 1; i < n; i++)
    {
        v = p[i];
        for(j = i - 1; p[j] > v&&j > -1; j--)
        {
            p[j+1] = p[j];
        }
        p[j+1] = v;
        for(j = 0; j < n; j++)
        {
            if(j>0)
            printf(" ");
            printf("%d",*(p+j));
        }
        printf("\n");
    }
}

