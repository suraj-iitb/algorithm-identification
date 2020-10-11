#include<stdio.h>
#define MAX 100000
#define SENTINELtw 2000000000

struct Card{
    char suit;
    int value;
};

struct Card L[MAX/2+2],R[MAX/2+2];

void mergetw(struct Card Atw[],int n,int left,int mid,int right){
    int i,j,k;
    int n1=mid-left;
    int n2=right-mid;
    for(i=0;i<n1;i++)L[i]=Atw[left+i];
    for(i=0;i<n2;i++)R[i]=Atw[mid+i];
    L[n1].value = R[n2].value = SENTINELtw;
    i=j=0;
    for(k=left;k<right;k++){
        if(L[i].value <= R[j].value){
            Atw[k]=L[i++];
        }else{
            Atw[k]=R[j++];
        }
    }
}

void mergeSorttw(struct Card A[],int n,int left,int right){
    int mid;
    if(left + 1 < right){
        mid=(left+right)/2;
        mergeSorttw(A,n,left,mid);
        mergeSorttw(A,n,mid,right);
        mergetw(A,n,left,mid,right);
    }
}

int partition(struct Card Atw[], int n,int p,int r){
    int i,j;
    struct Card t,x;
    x=Atw[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(Atw[j].value <= x.value){
            i++;
            t=Atw[i];Atw[i]=Atw[j];Atw[j]=t;
        }
    }
    t=Atw[i+1];Atw[i+1]=Atw[r];Atw[r]=t;
    return i+1;
}

void quickSort(struct Card Atw[],int n,int p,int r){
    int q;
    if(p<r){
        q=partition(Atw,n,p,r);
        quickSort(Atw,n,p,q-1);
        quickSort(Atw,n,q+1,r);
    }
}

int main(){
    int n,i,v;
    struct Card Atw[MAX],Btw[MAX];
    char S[10];
    int stable=1;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s %d",S,&v);
        Atw[i].suit=Btw[i].suit=S[0];
        Atw[i].value=Btw[i].value=v;
    }

    mergeSorttw(Atw,n,0,n);
    quickSort(Btw,n,0,n-1);

    for(i=0;i<n;i++){

        if(Atw[i].suit != Btw[i].suit)stable=0;
    }

    if(stable==1)printf("Stable\n");
    else printf("Not stable\n");
    for (i=0;i<n;i++){
        printf("%c %d\n",Btw[i].suit,Btw[i].value);
    }

    return 0;
}
