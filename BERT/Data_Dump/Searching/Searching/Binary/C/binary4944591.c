#include<stdio.h>

int binarySearch(int A[], int key, int n)
{
    int left = 0;
    int right = n;
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] == key)
            return mid;
        else if(key < A[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return n;
}

void insertionSort(int A[], int N)
{
    int j,i,v;
    for(i=1; i<N; i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0 && A[j] > v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }

}

int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    int a[n+1];
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    insertionSort(a, n);
    
    int q;
    scanf("%d", &q);
    int b, c=0, j;
    
    for(i=0; i<q; i++)
    {
        scanf("%d", &b);
        
       if((j=binarySearch(a,b,n))!=n) 
        c++;
    }
    printf("%d\n", c);
    return 0;
    
}
