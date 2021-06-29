#include<stdio.h>
#define MAX 100000
#define MERNUM 1000000000

struct card
{
    char name;
    int num;
};

struct card L[MAX / 2 + 2],R[MAX / 2 + 2];

void merge(struct card ms[],int l,int m,int r){

    int n1,n2,i,j,k;
    n1 = m - l;
    n2 = r - m;
    for(i = 0;i < n1;i++){
        L[i] = ms[l + i];
    }
    for(i = 0;i < n2;i++){
        R[i] = ms[m + i];
    }
    L[n1].num = R[n2].num = MERNUM;
    i = j = 0;
    for(k = l;k < r;k++){
        if(L[i].num <= R[j].num){
            ms[k] = L[i++];
        } else {
            ms[k] = R[j++];
        }
    }
}

void mergesort(struct card ms[],int l,int r){
    int m;
    if (l + 1 < r){
        m = (l + r) / 2;
        mergesort(ms,l,m);
        mergesort(ms,m,r);
        merge(ms,l,m,r);
    }

}

int partition(struct card qs[],int l,int r){

    int n,p;
    struct card t,x;
    
    x = qs[r];
    p = l - 1;

    for(n = l;n < r;n++){
        if (qs[n].num <= x.num){
            p++;
            t = qs[p];
            qs[p] = qs[n];
            qs[n] = t;
        }
    }

    t = qs[p + 1];
    qs[p + 1] = qs[r];
    qs[r] = t;

    return p + 1;

}

void quickSort(struct card qs[],int l,int r){
    int q;
    if (l < r){
        q = partition(qs,l,r);
        quickSort(qs,l,q-1);
        quickSort(qs,q+1,r);
    }
}

int main(void){

    char name[10];
    int num,size;
    struct card ms[MAX],qs[MAX];
    int stable = 1;

    scanf("%d",&size);

    for(int i  = 0;i < size; i++){
        scanf("%s%d",name,&num);
        ms[i].name = qs[i].name = name[0];
        ms[i].num = qs[i].num = num;
    }

    quickSort(qs,0,size-1);
    mergesort(ms,0,size);

    for (int i = 0;i < size;i++){
        if (ms[i].name != qs[i].name){
            stable = 0;
        }
    }

    if (stable == 1){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    for (int i = 0;i < size;i++){
        printf("%c %d\n",qs[i].name,qs[i].num);
    }
    return 0;
}
