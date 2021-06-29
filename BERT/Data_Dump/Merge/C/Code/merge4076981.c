#include<stdio.h>
#include<stdlib.h>
#define N 500000

int tmp[N],cnt = 0;

void MergeSort(int A[],int left , int right){
    int mid,i,j,k;
    if(left < right){
        mid = (left + right) / 2;
        MergeSort(A , left , mid);
        MergeSort(A , mid + 1 , right);

        for(i = mid ; i >=left ; i--)tmp[i] = A[i];
        for(j = mid + 1 ; j <= right ;j++)tmp[right - (j - (mid + 1))] = A[j];

        i = left;
        j = right;
        for(k = left ; k <= right ;k++){
            if(tmp[i] < tmp[j])
            A[k] = tmp[i++];
            else A[k] = tmp[j--];
            cnt++;
        }
        }
    }

int main()
{
    int i,n,A[N];

    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        scanf("%d",&A[i]);
        if(A[i] < 0 || A[i] > 1000000000)exit(1);
    }

    MergeSort(A , 0 , n - 1);
    for(i = 0 ; i < n ; i++){
        if(i > 0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);

    return 0;
}

