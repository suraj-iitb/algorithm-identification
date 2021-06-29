#include <iostream>
#include <cstdio>
using namespace std;

const int Max = 500005;
const int M = 1000000005;
int S[Max], Count = 0;
int a[Max/2], b[Max/2];
void Merge(int S[], int left, int right, int mid)
{
    int n1 = mid-left, n2 = right-mid;
    for(int i=0; i<n1; i++)
    {
        a[i] = S[i+left];
        //Count++;
    }
    for(int i=0; i<n2; i++)
    {
        b[i] = S[i+mid];
        //Count++;
    }
    a[n1] = M, b[n2] = M;//确保最后一个数较大，利于以下排序
    int k=left, ka=0, kb=0;
    //Count++;
    while(k<right)
    {
        if(a[ka]>b[kb])
        {
            S[k++] = b[kb++];
        }
        else
        {
            S[k++] = a[ka++];
        }
        Count++;
    }
}

void MergeSort(int S[], int left, int right)
{
    if(left+1<right)
    {
        int mid = (left+right)/2;
        MergeSort(S, left, mid);
        MergeSort(S, mid, right);
        Merge(S, left, right, mid);
    }
}

int main()
{
    int n;
    Count = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &S[i]);
    MergeSort(S, 0, n);
    for(int i=0; i<n-1; i++)
        printf("%d ", S[i]);
    printf("%d\n", S[n-1]);
    printf("%d\n", Count);
    return 0;
}

