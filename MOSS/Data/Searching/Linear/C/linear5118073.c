#include<stdio.h>
#define N 10001
int search(int a[], int n, int key);
int main(void)
{
    int i,n;
    int a[N];
    int q,k;
    int s;
	s=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
	
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&k);
        
        if(search(a,n,k))
        {
            s++;
        }
    }
    printf("%d\n",s);
    
    return 0;
        
}
int search(int a[], int n, int k)
{
    int i;
    i=0;
    a[n]=k;
    while(a[i]!=k)
    {
        i++;
    }
    return i !=n;
}
