#include<stdio.h>
int main(void)
{
    int n;
    
    scanf("%d",&n);
    
    int S[n+1],i;
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }
    
    int q;
    
    scanf("%d",&q);
    
    
    
    
    int j=0,count=0,key;
    
   
    
    for(i=0;i<q;i++)
    {
        scanf("%d",&key);
       S[n]=key;
       while(S[j]!=S[n])
       {
           j++;
       }
       if(j!=n)
       {
           count++;
       }
       j=0;
    }
    
    printf("%d\n",count);
    
    
    
    return 0;
}
