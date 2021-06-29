#include <stdio.h>
#define N 100000

int A[N];
char C[N];
char C1[N];
int A1[N];

int Partition(int p,int r){
    int x,i,j;
    int tmp,tmpc;
    
    x=A[r];
    i = p-1;
    
    for(j=p;j<r;j++){
        if (A[j] <= x){
            i=i+1;
            tmp=A[j];
            tmpc=C[j];
            A[j]=A[i];
            C[j]=C[i];
            A[i]=tmp;
            C[i]=tmpc;
        }
    }
    
    tmp=A[i+1];
    tmpc=C[i+1];
    A[i+1]=A[r];
    C[i+1]=C[r];
    A[r]=tmp;
    C[r]=tmpc;
    
    
    return i+1;
}

void Quicksort(p,r){
    int q;
    if(p<r){
        q=Partition(p,r);
        Quicksort(p,q-1);
        Quicksort(q+1,r);
    }
}

/* Merge */
void Merge(int l,int m,int r){
    int n1,n2;
    int i,j,k;
    int L[N],R[N];
    char LC[N],RC[N];
    
    n1=m-l;
    n2=r-m;
    
    for(i=0;i<n1;i++){
        L[i]=A1[l+i];
        LC[i]=C1[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=A1[m+j];
        RC[j]=C1[m+j];
    }
    
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    
    i=0;
    j=0;
    
    for(k=l;k<r;k++){
        if(L[i]<=R[j]){
            A1[k]=L[i];
            C1[k]=LC[i];
            i++;
        }else{
            A1[k]=R[j];
            C1[k]=RC[j];
            j++;
        }
    }
    
}
/* Merge Sort */
void Merge_Sort(int left,int right){
    int mid;
    if(left+1<right){
        mid = (left + right)/2;
        Merge_Sort(left,mid);
        Merge_Sort(mid,right);
        Merge(left,mid,right);
    }
}// End Merge-Sort



int main(int argc, char *argv[]){
    

    int n,i,x,j,k=0;
    char null;
    int tmp;
    char tmpc;
    
    scanf("%d%c",&n,&null);
    if(1>n || n>100000)return 0;
    
    for(i=0;i<n;i++){
        scanf("%c%d%c",&C[i],&A[i],&null);
        C1[i]=C[i];
        A1[i]=A[i];
    }
    
    
    Quicksort(0,n-1);
    
    
    Merge_Sort(0,n);
    
    
/*    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            
            if(A1[j]<A1[j-1]){
                tmp=A1[j];
                tmpc=C1[j];
                A1[j]=A1[j-1];
                C1[j]=C1[j-1];
                A1[j-1]=tmp;
                C1[j-1]=tmpc;
            }
        }
    }
    
  */
    for(i=0;i<n;i++){
        if(C1[i]!=C[i]){
        k=1;
    }
    }
    

    
    
    if(k==1)printf("Not stable\n");
    else printf("Stable\n");
    
    
    for(i=0;i<n-1;i++){
        printf("%c %d\n",C[i],A[i]);
    }

    printf("%c %d\n",C[n-1],A[n-1]);
    
    
    
    
    return 0;
}
