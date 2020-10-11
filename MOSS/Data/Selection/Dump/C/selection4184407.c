#include <stdio.h>
#include <time.h>
void SelectionSort(int *p,int n);
int main ()
{
    int number,*p,i;
    scanf("%d",&number);
    p = (int *)malloc(number*sizeof(int));
    for(i = 0; i < number ; i++)
    {
        scanf("%d",&p[i]);
    }
    SelectionSort(p,number);
    free(p);
    return 0;
}
void SelectionSort(int *p,int n)
{
    int i,j,k,count = 0,temp;
    for(i = 0;i < n - 1;i++)
    {
        k = i;
        for(j = i+1;j < n;j++)
        {
            if(p[j]<p[k])
                k = j;
        }
        if(k!=i)
        {
            count++;
            temp = p[k];
            p[k] = p[i];
            p[i] = temp;
        }
    }
    for(i = 0;i < n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",p[i]);
    }
    printf("\n%d\n",count);
}

