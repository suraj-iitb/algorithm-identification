#include<stdio.h>
#define N 100000

typedef struct{
    char pic;
    int num;
} Card;

#define INFTY 1000000001
void mergeSort(int,int);
void merge(int,int,int);
int partition(int,int);
void quickSort(int,int);
int n;
Card Q[N],M[N],L[N/2+2],R[N/2+2];

int main(){
    int i,data,judge = 1;
    char str[2];

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s%d",str,&data);
        Q[i].pic = str[0];
        Q[i].num = data;
        M[i].pic = str[0];
        M[i].num = data;
    }

    quickSort(0,n-1);
    mergeSort(0,n);

    for(i=0;i<n;i++){
        if(Q[i].pic != M[i].pic){
            judge = 0;
        }
    }

    if(judge == 1){
        printf("Stable\n");
    }
    else{
        printf("Not stable\n");
    }

    for(i=0;i<n;i++){
        printf("%c %d\n",Q[i].pic,Q[i].num);
    }

    return 0;
}

int partition(int p,int r){
    int i,j;
    Card tmp,x;

    x = Q[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(Q[j].num <= x.num){
            i = i+1;
            tmp = Q[i];
            Q[i] = Q[j];
            Q[j] = tmp;
        }
    }
        tmp = Q[i+1];
        Q[i+1] = Q[r];
        Q[r] = tmp;
    return i+1;
}

void quickSort(int p,int r){
    int q;

    if(p<r){
        q = partition(p,r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}

void merge(int left,int mid,int right){
    int n1,n2,i,j,k;
    n1 = mid - left;
    n2 = right - mid;
    for(i=0;i<n1;i++){
        L[i] = M[left + i];
    }
    for(i=0;i<n2;i++){
        R[i] = M[mid+i];
    }
    L[n1].num = INFTY;
    R[n2].num = INFTY;
    i = 0;
    j = 0;
    for(k = left;k<right;k++){
        if(L[i].num <= R[j].num){
            M[k] = L[i];
            i = i + 1;
        }
        else{
            M[k] = R[j];
            j = j + 1;
        }
    }
}
void mergeSort(int left,int right){
    int mid;
    if(left+1 < right){
        mid = (left + right)/2;
        mergeSort(left,mid);
        mergeSort(mid,right);
        merge(left,mid,right);
    }
}
