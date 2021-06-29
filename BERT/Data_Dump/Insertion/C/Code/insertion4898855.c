#include<stdio.h>
#define N 100
void insertionSort(int a[N],int k);
int main(void)
{
    int i,k,j;
    int a[N];
    int z=0;
    
    scanf("%d",&k);
    
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<k;i++)
    {
        insertionSort(a,z);
    	
        for(j=0;j<k;j++)
        {
            printf("%d",a[j]); 
            if(j<k-1)
            {
                printf(" ");  
            }
        }
    	printf("\n");
    	
        z++;
    }
}
void insertionSort(int a[],int k)
{
    int i,t;
    for(i=k;1<=i;i--)
    {
         if(a[i-1]<=a[i])
         {
             break;
         }
         else
         {
             t=a[i];
             a[i]=a[i-1];
             a[i-1]=t;
         }
    }
}
