#include<stdio.h>
#define N 500000
#define INFTY 1000000001
void merge(int,int,int);
void mergesort(int,int);
int a[N],cnt;
int main(){
    int i,n;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    mergesort(0,n);
    for( i = 0 ; i < n ; i++ ){
        if( i != 0 ) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
}

void merge(int left,int mid,int right){
    int i,j,k,n1 = mid - left,n2 = right - mid;
    int l[n1 + 1],r[n2 + 1];
    for( i = 0 ; i < n1 ; i++ ) l[i] = a[left + i];
    for( i = 0 ; i < n2 ; i++ ) r[i] = a[mid + i];
    l[n1] = INFTY;
    r[n2] = INFTY;
    i = j = 0;
    for( k = left ; k < right ; k++ ){
        cnt++;
        if( l[i] <= r[j] ){
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(int left,int right){
    int mid;
    if( left + 1 < right ){
        mid = (left + right) / 2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,mid,right);
    }
}
