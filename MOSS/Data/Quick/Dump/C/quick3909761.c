#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char c;
    int n;
}Card;

void merge(Card a[],int left,int mid,int right){
    int n1,n2,i,j,k;
    Card *l,*r;
    n1 = mid-left; n2 = right-mid;
    l = (Card*)malloc(sizeof(Card)*(n1+1));
    r = (Card*)malloc(sizeof(Card)*(n2+1));
    for(i=0;i<n1;i++){
        l[i].n =a[i+left].n;
        l[i].c =a[i+left].c;
    }
    for(i=0;i<n2;i++){
        r[i].n =a[i+mid].n;
        r[i].c =a[i+mid].c;
    }
    l[n1].n=1000000001;r[n2].n=1000000001;
    i=0;j=0;
    for(k=left;k<right;k++){
        if(l[i].n<=r[j].n){
            a[k].n = l[i].n;
            a[k].c = l[i].c;
            i++;
        }else{
        	a[k].n = r[j].n;
            a[k].c = r[j].c;
            j++;
        }
    }
    free(l);
    free(r);
}

void mergesort(Card a[],int left,int right){
    int mid;
    if(left+1<right){
        mid = (left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        merge(a,left,mid,right);
    }
}

void chenge(Card a[],int i,int j){
    int n; char c;
    n = a[i].n; c = a[i].c;
    a[i].n = a[j].n; a[i].c = a[j].c;
    a[j].n = n; a[j].c = c;
}

int pertition(Card a[],int left,int right){
    int i,j,k;
    k=left-1;
    for(i=left;i<right-1;i++){
        if(a[i].n<=a[right-1].n){
            k++;
            chenge(a,i,k);
        }
    }
    chenge(a,k+1,right-1);
    return k+1;
}

void quicksort(Card a[],int left,int right){
    int mid;
    if(left+1<right){
        mid = pertition(a,left,right);
        quicksort(a,left,mid);
        quicksort(a,mid+1,right);
    }
}

int main(void){
    int n,i,flg;
    char aaaa;
    Card *c1;
    Card *c2;
    scanf("%d",&n);
    c1 = (Card*)malloc(sizeof(Card)*n);
    c2 = (Card*)malloc(sizeof(Card)*n);
    for(i=0;i<n;i++){
        c1[i].c = '\0';
    	while(!('A'<=c1[i].c&&c1[i].c<='Z')){
    		scanf("%c",&c1[i].c);
    	}
        scanf("%d",&c1[i].n);
        c2[i].c = c1[i].c; c2[i].n = c1[i].n;
    }
    quicksort(c1,0,n);
    mergesort(c2,0,n);
    flg = 0;
    for(i=0;i<n;i++){
        if(c1[i].c!=c2[i].c){
            flg = 1;
            break;
        }
    }
    if(flg==0){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
    for(i=0;i<n;i++){
        printf("%c %d\n",c1[i].c,c1[i].n);
    }
    
    free(c1);
    free(c2);
    return 0;
}
