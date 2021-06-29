#include<stdio.h>
#include<stdlib.h>
#define N 1000000
#define INFTY 1000000000

typedef struct{
    int num;
    char mark[10];
} card;

void quicksort(card [],int,int);
int partition(card [],int,int);
void merge(card [],int,int,int);
void mergeSort(card [],int,int);
int stable(card [],card []);

int n;

int main(){
    int i;
    card *a,*b;
    scanf("%d",&n);
    a = malloc(sizeof(card) * n);
    b = malloc(sizeof(card) * n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%s %d",a[i].mark,&a[i].num);
        b[i] = a[i];
    }
    quicksort(a,0,n - 1);
    mergeSort(b,0,n);
    if( stable(a,b) == 0 ) printf("Stable\n");
    else printf("Not stable\n");
    for( i = 0 ; i < n ; i++ ){
        printf("%s %d\n",a[i].mark,a[i].num);
    }
    return 0;
}

void quicksort(card a[],int p,int r){
    int q;
    if( p < r ){
        q = partition(a,p,r);
        quicksort(a,p,q - 1);
        quicksort(a,q + 1,r);
    }
}

int partition(card a[],int p,int r){
    int x = a[r].num,i = p - 1,j;
    card key;
    for( j = p ; j < r ; j++ ){
        if( a[j].num <= x ){
            i++;
            key = a[i];
            a[i] = a[j];
            a[j] = key;
        }
    }
    key = a[i + 1];
    a[i + 1] = a[r];
    a[r] = key;
    return i + 1;
}

void merge(card b[],int left,int mid,int right){
    int n1,n2,i,j,k;
    card *l,*r;
    n1 = mid - left;
    n2 = right - mid;
    l = malloc(sizeof(card) * (n1 + 1));
    r = malloc(sizeof(card) * (n2 + 1));
    for( i = 0 ; i < n1 ; i++ ){
        l[i] = b[left + i];
    }
    l[i].num = INFTY;
    for( i = 0 ; i < n2 ; i++ ){
        r[i] = b[mid + i];
    }
    r[i].num = INFTY;
    i = j = 0;
    for( k = left ; k < right ; k++ ){
        if( l[i].num <= r[j].num ){
            b[k] = l[i];
            i++;
        }
        else{
            b[k] = r[j];
            j++;
        }
    }
}

void mergeSort(card b[],int left,int right){
    int mid;
    if( left + 1 < right ){
        mid = ( left + right ) / 2;
        mergeSort(b,left,mid);
        mergeSort(b,mid,right);
        merge(b,left,mid,right);
    }
}

int stable(card a[],card b[]){
    int i;
    for( i = 0 ; i < n ; i++ ){
        if(a[i].mark[0] != b[i].mark[0]) return 1;
    }
    return 0;
}
