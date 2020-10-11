#include <stdio.h>
#define MAX 500000

void Merge(int [],int,int,int);
void Merge_Sort(int [],int,int);


int total;

int main(void){
    int A[MAX];
    int i,n;

    //要素の個数を指定
    scanf("%d",&n);

    //読み込む
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);


    Merge_Sort(A,0,n);

    //ソートされた数列を表示させる
    for(i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("%d\n%d\n",A[i],total);

    return 0;
}


//Merge_Sortから送られてきたデータを結合する。
void Merge(int A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    int i,j,k;

    for(i = 0;i < n1;i++)
        L[i] = A[left + i];

    for(i = 0;i < n2;i++)
        R[i] = A[mid + i];

    L[n1] = 1000000000;
    R[n2] = 1000000000;

    i = 0;
    j = 0;

    for(k = left;k < right;k++){
        if(L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];

        total++;
    }
}


//ここで分割できるだけ分割する
void Merge_Sort(int A[],int left,int right){
    int mid;

    // 2つになるまで分割して行く
    if(left + 1 < right){
        mid = (left + right)/2;
        Merge_Sort(A,left,mid);
        Merge_Sort(A,mid,right);
        Merge(A,left,mid,right);
    }
}
