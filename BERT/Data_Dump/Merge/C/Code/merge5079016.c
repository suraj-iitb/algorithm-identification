#include<stdio.h>
#define INF 2000000000
#define MAX 500000


int cnt;
int L[MAX/2+2];
int R[MAX/2+2];

void merge(int A[],int n,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;

    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];  //A[]を真ん中で二つに分けてL[]とR[]に格納する
    }

    L[n1] = R[n2] = INF;

    int i = 0;
    int j = 0;

    for(int k=left;k<right;k++){ //でかい方を代入してiかjを+1する
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
    
}

void mergeSort(int A[],int n,int left,int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    int n;
    int A[MAX];
    int i;
    cnt = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,n,0,n);

    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);

    return 0;
}
