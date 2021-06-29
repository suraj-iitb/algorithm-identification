#include <stdio.h>
void trace(int A[],int N){
    int i;
    for (i = 0; i < N; ++i) {
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}
void InsertionSort(int Aa[],int Nn){
    int j,i,v;
    for (i = 1; i < Nn; ++i){
        v=Aa[i];
        j=i-1;
        while (j>=0&&Aa[j]>v) Aa[j+1]=Aa[j],j--;
        Aa[j+1]=v;
        trace(Aa,Nn);
    }
}
int main() {
    int n,i,j,a[110];
    scanf("%d",&n);
    for (i = 0; i < n; ++i)scanf("%d",&a[i]);
    trace(a,n);
    InsertionSort(a,n);
    return 0;
}

