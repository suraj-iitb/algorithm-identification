#include <stdio.h>

void trace1(int a[],int n)
{
    for(int k = 0;k<n;k++){
        
        if(k>0)
        {
            printf(" ");
        }
        printf("%d",a[k]);
        
    }
    puts("");
    
}

void insertionSort(int a[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int v = a[i];
        int j = i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace1(a,n);
    }
}

int main(){
    
    int n = 0;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    trace1(a,n);
    
    insertionSort(a, n);
    
    return 0;
}
