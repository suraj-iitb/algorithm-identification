#include <stdio.h>
int BubbleSort(int a[],int n)
{
    int flag = 1,count = 0;
    int k = 0;
    
    while(flag)
    {   flag = 0;
        for(int i = n-1;i>k;i--)
        {
            if(a[i]<a[i-1])
            {
                int j = a[i];
                a[i] = a[i-1];
                a[i-1] = j;
                count++;
                flag = 1;
                
                            }
            
        }
        k++;
    }
    return count;
}




int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int count = 0;
    
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    count = BubbleSort(a,n);
    
    
    for(int i = 0;i<n;i++)
    {
        if(0<i&&i<n)
            printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    printf("%d\n",count);
    
    return 0;
    
}


