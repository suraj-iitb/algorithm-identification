#include <stdio.h>
using namespace std;
typedef long long llong;

int max = 1000000001;
int A[500001];
int L[500001];
int R[500001];
int sum = 0;
void merge_sort(const int& left ,const int& mid,const int& right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = max;
    R[n2] = max;
    int i = 0,j=0;
    for(int k=left;k<right;k++)
    { 
        sum++;
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i = i + 1;

        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}
void merge_sort(const int& left, const int& right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort( mid,right);
        merge_sort(left, mid, right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d",&(A[i]));
    merge_sort(0,n);
    printf("%d", A[0]);
    for(int i=1;i<n;i++)
        printf(" %d",A[i]);
    printf("\n");
    printf("%d\n",sum);
    return 0;
}


