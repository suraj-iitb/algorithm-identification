//2020 4.18 Binary Search

#include <stdio.h>
#define MAX1 100000
#define MAX2 50000
#define NOT_FOUND -1  //1にしていたが、そうするとbinarySearchの戻り値(mid)が1になる場合があり、if(res!=1)のところでカウントをしなくなってしまう。

int binarySearch(int *,int,int);

int main()
{
    int a,b,res=0,cnt=0;
    int i,j;
    int A[MAX1],B[MAX2];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&A[i]);
    }

    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&B[i]);

        res=binarySearch(A,a,B[i]);

        if(res!=-1) cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}

int binarySearch(int *A,int n,int key)
{
    int left = 0;
    int right = n;
    int mid;
    while(left < right)
    {
        mid=(left + right)/2;
        if(A[mid] == key) {return mid;}
        else if(key<A[mid]) {right = mid;}
        else left = mid + 1;
    }
    return NOT_FOUND;    
}

