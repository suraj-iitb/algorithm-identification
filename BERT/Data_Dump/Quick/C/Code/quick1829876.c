#include<stdio.h>
int card[1000000],num[1000000];
char mark[1000000];

int quicksort(int,int);
int partition(int,int);

int main(void)
{
    int m,k,flg=0;

    scanf("%d",&m);
    for(k=0;k<m;k++) num[k]=k;
    for(k=0;k<m;k++){
        scanf(" %c",&mark[k]);
        scanf("%d",&card[k]);
    }
    quicksort(0,m-1);
    for(k=1;k<m;k++){
        if(card[k]==card[k-1]){
            if(num[k]<num[k-1]){
                flg=1;
            }
        }
    }
    if(flg==1) printf("Not stable\n");
    else       printf("Stable\n");
    for(k=0;k<m;k++){
        printf("%c %d\n",mark[k],card[k]);
    }
    return 0;
}

int partition(int j,int n){
    int i,x,tmpi;
    char tmpc;
    x=card[n];
    for(i=j;i<n;i++){
        if(card[i]<=x){
            tmpi=card[i];
            card[i]=card[j];
            card[j]=tmpi;
            tmpc=mark[i];
            mark[i]=mark[j];
            mark[j]=tmpc;
            tmpi=num[i];
            num[i]=num[j];
            num[j]=tmpi;
            j++;
        }
    }
    tmpi=card[n];
    card[n]=card[j];
    card[j]=tmpi;
    tmpc=mark[n];
    mark[n]=mark[j];
    mark[j]=tmpc;
    tmpi=num[n];
    num[n]=num[j];
    num[j]=tmpi;
    return j;
}

int quicksort(int p,int r){
    int q;
    if(p<r){
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
    return 0;
}
