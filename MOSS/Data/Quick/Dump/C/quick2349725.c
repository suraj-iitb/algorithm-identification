#include <stdio.h>
#define N 100001
int n;
int A[N];
int num[N];
char B[N];
int Partition(int, int);
void Quick_Sort(int, int);
int main(){
    int i;
    int p;
    int tmp=1;
    int r;
    scanf("%d\n", &n);
    for( i=0; i<n; i++ ){
        scanf("%c %d\n", &B[i],&A[i]);
        num[i]=i+1;
    }
    p=0;
    r=n-1;
    Quick_Sort(p, r);
    for( i=1; i<n; i++ ){
        if( A[i] == A[i-1] && num[i] < num[i-1] ){
            tmp = 0;
            break;
        }
    }
    if( tmp == 1 )printf("Stable\n");
    else if( tmp == 0 ) printf("Not stable\n");
    for( i=0; i<n; i++ ) printf("%c %d\n",B[i], A[i]);
    return 0;
}
int Partition(int p, int r){
    int i;
    int j;
    int tmp1;
    int tmp3;
    char tmp2;
    int x;
    x=A[r];
    i=p-1;
    for( j=p; j<=r-1; j++ ){
        if( A[j] <= x ){
            i++;
            tmp1=A[j];
            A[j]=A[i];
            A[i]=tmp1;
 
            tmp2=B[j];
            B[j]=B[i];
            B[i]=tmp2;
 
            tmp3 = num[j];
            num[j]=num[i];
            num[i]=tmp3;
        }
    }
    tmp1=A[r];
    A[r]=A[i+1];
    A[i+1]=tmp1;
 
    tmp2=B[r];
    B[r]=B[i+1];
    B[i+1]=tmp2;
 
    tmp3=num[r];
    num[r]=num[i+1];
    num[i+1]=tmp3;
    return i+1;
}
void Quick_Sort(int p, int r){
    int q;
    if( p < r ){
        q = Partition(p,r);
        Quick_Sort(p, q-1);
        Quick_Sort(q+1, r);
    }
}
