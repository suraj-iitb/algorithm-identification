#include <stdio.h>
#include <time.h>
void BubbleSort(int *p,int n);
int main ()
{
    int number,*p,i;
    scanf("%d",&number);
    p = (int *)malloc(number*sizeof(int));
    for(i = 0; i < number ; i++)
    {
        scanf("%d",&p[i]);
    }
    BubbleSort(p,number);
    free(p);
    return 0;
}
void BubbleSort(int *p,int n)
{
    int i,j,temp,count=0;
    for(i = 0;i < n - 1;i++)
    {
        for(j = n-1;j > i;j--)
        {
            if(p[j]<p[j-1])
            {
                temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
                count++;
            }
        }
    }
    for(i = 0;i < n;i++)
    {
        if(i > 0)printf(" ");
        printf("%d",*(p+i));
    }
    printf("\n%d\n",count);
}

