#include <stdio.h>

int left[500000/2+2],right[500000/2+2];
int cnt=0;

void merge(int *,int,int,int,int);
void mergeS(int *,int,int,int);

int main(){
    int M[500000],n,i;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&M[i]);
    }
    
    mergeS(M,n,0,n);
    
    for(i=0;i<n;i++){
        if(i != 0)printf(" ");
        printf("%d",M[i]);
    }
    printf("\n%d\n",cnt);

    return 0;
}

void merge(int *M, int n,int le,int mi,int ri){
    int i,j,k;
    int n1 = mi - le;
    int n2 = ri - mi;
    for(i=0;i<n1;i++) left[i] = M[le + i];
    for(i=0;i<n2;i++) right[i] = M[mi + i];
    left[n1] = right[n2] = 1000000000 ;
    i=0;
    j=0;
    for(k=le;k<ri;k++){
        cnt++;
        if(left[i] <= right[j]){
            M[k] = left[i++];
        }else{
            M[k] = right[j++];
        }
    }
}

void mergeS(int *M,int n,int le,int ri){
    if(le+1 < ri){
        int mid = (le+ri)/2;
        mergeS(M,n,le,mid);
        mergeS(M,n,mid,ri);
        merge(M,n,le,mid,ri);
    }
}

