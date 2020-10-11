//2020 1.25 マージソート
#include <stdio.h>
#define MAX 500000
#define INFTY 1000000001

void merge(int *,int ,int ,int );
void mergeSort(int *,int ,int );

int cnt=0;

int main(void)
{
    int n;
    int i;
    int array[MAX];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    mergeSort(array,0,n);

    for(i=0;i<n;i++)
    {
        printf("%d",array[i]);
        if(i != n-1) printf(" ");
    }

    printf("\n"); printf("%d",cnt); printf("\n");

    return 0;
}

void mergeSort(int *array,int left,int right)
{
    int mid;

    if(left+1<right)
    {
        mid = (left+right)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid,right);
        merge(array,left,mid,right);
    }
    return;
}

void merge(int *array,int left,int mid,int right)
{
    int n1,n2;
    int i,j,k;
    static int L[MAX/2+2],R[MAX/2+2];   //LとRの配列を保存しておくためにstatic変数を使う

    n1 = mid-left;
    n2 = right-mid;

    for(i=0;i<n1;i++) L[i] = array[left+i];
    for(i=0;i<n2;i++) R[i] = array[mid+i];
    i=j=0;

    L[n1]=R[n2]=INFTY;          //最大の値を入れる事によって必ず配列に入れた値を比較しマージできる
    for(k=left;k<right;k++)
    {
        cnt++;
        if(L[i]<=R[j])
        {
            array[k]=L[i]; i++;
        }
        else
        {
            array[k]=R[j]; j++;
        }
    }
    return;
}

