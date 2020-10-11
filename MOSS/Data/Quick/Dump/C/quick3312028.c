#include<stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int num;
    char type;
} CARD;

void Qsort(CARD *,int,int);
int partition(CARD *,int,int);

int main(){
    int n,i,sta=0;
    CARD *A;
    scanf("%d",&n);

    A = (CARD *) malloc (sizeof(CARD)*n);

    for(i=0;i<n;i++) {
        scanf(" %c",&A[i].type);
        scanf("%d",&A[i].a);
        A[i].num=i;
    }

    Qsort(A,0,n-1);

    for(i=0;i<n-1;i++) if(A[i].a==A[i+1].a && A[i].num > A[i+1].num) sta=-1;
    if(sta==-1) printf("Not stable\n");
    else printf("Stable\n");

    for(i=0;i<n;i++) printf("%c %d\n",A[i].type,A[i].a);

    return 0;    
}

void Qsort(CARD *A,int p,int r){
    int q,i;

    if(p<r){
        //for(i=0;i<=r;i++) printf("%c%d ",A[i].type,A[i].a); printf("\n");
        q=partition(A,p,r);
        Qsort(A,p,q-1);
        Qsort(A,q+1,r);
        //for(i=0;i<=r;i++) printf("%c%d ",A[i].type,A[i].a); printf("\n");
    }

}
int partition(CARD *A,int p,int r){
    int i,j;
    CARD sw;
   i=p-1;

    for(j=p;j<r;j++){
        if(A[j].a <= A[r].a) {
            i++;
            sw=A[i];
            A[i]=A[j];
            A[j]=sw;
        }
    }

    sw=A[i+1];
    A[i+1]=A[r];
    A[r]=sw;

    return i+1;
}

