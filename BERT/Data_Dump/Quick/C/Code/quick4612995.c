#include<stdio.h>
#define AMOUNT 100000
#define NUM 1000000000
#define SENTINEL 2000000000

struct Card{
    char suit;
    int value;
};

struct Card L[AMOUNT / 2 + 2], R[AMOUNT / 2 + 2];

void merge(struct Card B[],int n,int left,int mid,int right){
    int i,j,k;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i=0;i<n1;i++){
        L[i] = B[left + i];
    }
    for(i=0;i<n2;i++){
        R[i] = B[mid + i];
    }
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for(k = left;k<right;k++){
        if(L[i].value<=R[j].value){
            B[k] = L[i++];
        }else{
            B[k] = R[j++];
        }
    }
}

void mergeSort(struct Card B[],int n,int left,int right){
    int mid;
    if(left + 1<right){
        mid=(left+right)/2;
        mergeSort(B,n,left,mid);
        mergeSort(B,n,mid,right);
        merge(B,n,left,mid,right);
    }
}

int partition(struct Card A[],int first,int last){//pivotを条件として大小に分けかつ処理後のpivotの位置を返す。
    int underPivotLast = first-1;
    struct Card pivot,temp;
    pivot = A[last];
    for(int i=first;i<last;i++){
        if(A[i].value <= pivot.value){
            underPivotLast++;
            temp = A[underPivotLast];
            A[underPivotLast] = A[i];
            A[i] = temp;
        }
    }
    temp = A[underPivotLast+1];
    A[underPivotLast+1] = A[last];
    A[last] = temp;
    return underPivotLast+1;
}

void quickSort(struct Card A[],int first,int last){
    int pivot;
    if(first < last){
        pivot = partition(A,first,last);
        quickSort(A,first,pivot-1);
        quickSort(A,pivot+1,last);
    }
}

int main(){
    int elementNum, value;
    int stable = 1;
    char suit[10];
    struct Card A[AMOUNT],B[AMOUNT];

    scanf("%d",&elementNum);
    for(int i=0;i<elementNum;i++){
        scanf("%s %d",suit,&value);
        A[i].suit = B[i].suit = suit[0];
        A[i].value = B[i].value = value;
    }
    mergeSort(B,elementNum,0,elementNum);
    quickSort(A,0,elementNum-1);

    for(int i=0;i<elementNum;i++){
        if(A[i].suit!=B[i].suit){
            stable = 0;
            break;
        }
    }
    if(stable==1){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }
    for(int i=0;i<elementNum;i++){
        printf("%c %d\n",A[i].suit,A[i].value);
    }
    return 0;
}
