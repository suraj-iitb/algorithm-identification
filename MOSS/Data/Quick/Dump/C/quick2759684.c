#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define rad M_PI/3
#define N 200001
#define Max 10000
typedef struct{
    int num,id;
    char mark;
}card;

void swap(card *a,card *b){
    card tmp =*a;
    *a=*b,*b=tmp;
}
int partition(card *A,int p, int r){
    int x = A[r].num;
    int i = p-1;
    for(int j=p;j<r;j++){
        if(A[j].num<=x){
            i+=1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
 
void Quicksort(card *A,int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

int isStable(card *a,int n){
    int i;
    for(i=0;i<n-1;i++){
        if(a[i].num==a[i+1].num && a[i].id>a[i+1].id) return 0;
    }
    return 1;
}
int main()
{
    int n;
    card A[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c %d",&A[i].mark,&A[i].num);
        A[i].id=i;
    }
    Quicksort(A,0,n-1);

    printf("%s\n",isStable(A,n)?"Stable":"Not stable");
    for(int i=0;i<n;i++)
        printf("%c %d\n",A[i].mark,A[i].num);

  return 0;
}
