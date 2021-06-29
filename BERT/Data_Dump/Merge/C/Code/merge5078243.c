#include<stdio.h>
#include<stdlib.h>
#define N 5000000
#define INFTY 1000000000

void merge(int [], int,int,int);
void mergeSort(int [],int,int);

int a[N],cnt = 0;

int main(){
    int i,n;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n);
    for( i = 0 ; i < n ; i++ ){
        printf("%d",a[i]);
        if( i < n - 1 ) printf(" ");
    }
    printf("\n%d\n",cnt);
    return 0;
}

void merge(int a[N],int left,int mid,int right){
    int n1,n2,i,j,k;
    int *l,*r;
    n1 = mid - left;
    n2 = right - mid;
    l = malloc(sizeof(int) * (n1 + 1));
    r = malloc(sizeof(int) * (n2 + 1));
    for( i = 0 ; i < n1 ; i++ ){
        l[i] = a[left + i];
    }
    l[i] = INFTY;
    for( i = 0 ; i < n2 ; i++ ){
        r[i] = a[mid + i];
    }
    r[i] = INFTY;
    i = j = 0;
    for( k = left ; k < right ; k++ ){
        if( l[i] <= r[j] ){
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
        cnt++;
    }
}

void mergeSort(int a[N],int left,int right){
    int mid;
    if( left + 1 < right ){
        mid = ( left + right ) / 2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}
