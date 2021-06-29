#include<stdio.h>
int main(){
int n,a[105],cnt=0,temp=0;
scanf("%d",&n);
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        
    for (int j = 0; j < n-i-1; j++)
    {
        if (a[j] > a[j+1])
        {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            cnt++;
        }
        
    }
    
    }
    

for (int i = 0; i < n; i++)
{
    if (i==n-1)
    {
            printf("%d\n",a[i] );
    }
    else
    {
            printf("%d ",a[i]);
        
    }
    
}



printf("%d\n", cnt);
    return 0;
}
