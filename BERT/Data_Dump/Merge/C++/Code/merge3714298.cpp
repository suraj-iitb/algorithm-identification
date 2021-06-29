#include<cstdio>
#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2+2],R[MAX/2+2];
int cnt = 0;
void merge(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; i++)
        L[i] = A[left+i];
    for(int i=0; i<n2; i++)
        R[i] = A[mid+i];
    L[n1]=R[n2]=SENTINEL;
    int i=0;
    int j=0;
    for(int a = left; a<right; a++)
    {
        cnt++;
        if(L[i] <= R[j]){
            A[a] = L[i++];
        }
        else
            A[a] = R[j++];
    }
}
void MergeSort(int A[], int n, int left, int right)
{
    if(left+1<right){
        int mid = (left+right)/2;
        MergeSort(A,n,left,mid);
        MergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}
int main()
{
    int A[MAX];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    MergeSort(A,n,0,n);
    for(int i=0; i<n; i++)
    {
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
}

