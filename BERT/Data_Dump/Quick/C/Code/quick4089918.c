#include <stdio.h>
#include <string.h>
#define N_MAX 100001


struct Card{
    char mark;
    int number;
    int tag;
};

void SwapElement(struct Card *c,int i, int j){
    struct Card buff;
    buff = c[i];
    c[i] = c[j];
    c[j] = buff;
}

int Partition(struct Card *c,int p, int r){
    int x = c[r].number;
    int i = p-1;
    int j;
    for(j=p;j<r;j++){
        if(c[j].number <= x){
            i++;
            SwapElement(c,i,j);
        }
    }
    SwapElement(c,i+1,r);
    return i+1;
}

void QuickSort(struct Card *c,int p,int r){
    int q;
    if(p<r){
        q = Partition(c,p,r);
        QuickSort(c,p,q-1);
        QuickSort(c,q+1,r);
    }
}

int isStable(struct Card *c, int len){
    int i;
    for(i=1; i<len; i++){
        if(c[i].number==c[i-1].number){
            if(c[i].tag < c[i-1].tag) return 0;
        }
    }
    return 1;
}


int main(){
    int n,i;
    struct Card c[N_MAX];

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%1s %d",&c[i].mark, &c[i].number);
        c[i].tag = i;
    }

    QuickSort(c,0,n-1);

    if(isStable(c,n)) printf("Stable\n");
    else printf("Not stable\n");

    for(i=0; i<n; i++){
        printf("%c %d\n",c[i].mark,c[i].number);
    }

    return 0;
}
