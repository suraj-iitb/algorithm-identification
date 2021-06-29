#include <stdio.h>
#define MAX 100500
#define SENTINEL 1000000500

typedef struct{
    char type;
    int value;
}Card;

int Partition(Card*,int,int);
void QuickSort(Card*,int,int);
void Merge_Sort(Card*,int,int);
void Merge(Card*,int,int,int);

Card L[MAX/2+2],R[MAX/2+2];

int main(){
    int i,value,n;
    Card A[MAX],B[MAX];
    char S[3];
    int flag=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d",S,&value);
        A[i].type = B[i].type = S[0];
        A[i].value = B[i].value = value;
    }

    QuickSort(A,0,n-1);
    Merge_Sort(B,0,n);

    for(i=0;i<n;i++){
        if(A[i].type != B[i].type){
            flag++;
        }
    }
    if(flag!=0) printf("Not stable\n");
    else printf("Stable\n");

    for(i=0;i<n;i++){
        printf("%c %d\n",A[i].type,A[i].value);
    }

    return 0;
}

int Partition(Card* A,int p,int r){
    int x,i,j;
    Card tmp;

    x = A[r].value;
    i = p-1;
    for(j=p;j<r;j++){
        if(A[j].value <= x){
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;

    return i+1;
}

void QuickSort(Card* A,int p,int r){
    int q,i;
    if(p < r){
        q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

void Merge_Sort(Card* B,int left,int right){
    int mid;
    if( left+1 < right){
        mid = (left + right)/2;
        Merge_Sort(B,left,mid);
        Merge_Sort(B,mid,right);
        Merge(B,left,mid,right);
    }
}

void Merge(Card* B,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i,j,k;

    for(i=0;i<n1;i++){
        L[i] = B[left + i];
    }
    for (i=0;i<n2;i++){
        R[i] = B[mid + i];
    }
    R[n2].value = L[n1].value = SENTINEL;
    i = j = 0;
    for(k=left;k<right;k++){
        if(L[i].value <= R[j].value){
            B[k] = L[i++];
        }
        else{
            B[k] = R[j++];
        }
    }
}

