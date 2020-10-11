#include<stdio.h>

#define SENTINEL 1000000000
#define MAX 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int L[MAX/2+1];
int R[MAX/2+1];
int count=0;

int main()
{
    int i,n;
    int S[MAX];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }
    mergeSort(S,0,n);

    for(i=0;i<n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",S[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}

void mergeSort(int*S,int left,int right)
{
    if(left+1<right)
    {
        int mid;
        mid = (left + right)/2;
        mergeSort(S,left,mid);
        mergeSort(S,mid,right);
        merge(S,left,mid,right);
    }
}

void merge(int*S,int left,int mid,int right)
{
    int i,j,k;
    int n1=mid-left;
    int n2=right-mid;
    for(i=0;i<n1;i++)
    {
        L[i]=S[left+i];
    }
    for(i=0;i<n2;i++)
    {
        R[i]=S[mid+i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    i=0;
    j=0;

    for(k=left; k<right; k++)
    {
        count++;
        if(L[i]<=R[j])
        {
            S[k] = L[i];
            i=i+1;
        }
        else {
            S[k] = R[j];
            j=j+1;
        }
    }
}
