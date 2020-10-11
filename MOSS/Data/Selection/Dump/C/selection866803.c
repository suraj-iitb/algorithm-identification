#include<stdio.h>

int main()
{
    int n,swap,i,min,j,cont=0;
    int index=0;
    int arr[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)
                    scanf("%d",&arr[i]);
    
    for(i=0;i<n;i++)
    {
                    min = i;
                    index = 0;
                    for(j=i;j<n;j++)
                    {
                                      if(arr[j] < arr[min])
                                      {
                                         min = j;  
                                         index=1;     
                                      }
                    }
                    if(index == 1)
                    cont = cont+1;
                    swap = arr[min];
                    arr[min] = arr[i];
                    arr[i] = swap;
    }
                    
    for(i=0;i<n;i++)
    {
                    if(i<n-1)
                    printf("%d ",arr[i]);
                    else
                    printf("%d\n",arr[i]);
    }
    printf("%d\n",cont);
    return 0;
}
    
    
    
