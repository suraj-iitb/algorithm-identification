#include <stdio.h>
#include <math.h>
#include <limits.h>

int count;
const int infty = INT_MAX;

void merge(int* a, int left, int mid, int right)
{
    int n1,n2,i,j,k;
    
    n1 = mid - left;
    n2 = right - mid;
    
    int l[n1 + 1],r[n2 + 1];
    
    for(i = 0;i < n1;i++) {
        l[i] = a[left + i];
    }
    for(i = 0;i < n2;i++) {
        r[i] = a[mid + i];
    }
    l[n1] = infty;
    r[n2] = infty;
    i = 0;
    j = 0;
    for(k = left;k < right;k++) {
        if(l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = r[j];
            j++;
        }
        count++;
    }
}

void mergeSort(int* a, int left, int right)
{
    int mid;

    if(left + 1 < right) { //比較対象が２以外の場合に下記を実行
        mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
/*
    for(i = 0;i < right;i++) {
        printf("%ld",a[i]);
        if(i != right - 1) {
            printf(" ");
        }
    }
*/
}

int main(void)
{
    int i,right;
    int a[500000];
    
    scanf("%d",&right);
    for(i = 0 ; i < right ; i++) {
        scanf("%d",&a[i]);
    }
  /*  
    if(right % 2 == 0) {
        left = right / 2;
    }
    else {
        left = (right - 1) / 2;
    }
    */
    mergeSort(a, 0, right);
    
    for(i = 0;i < right;i++) {
        printf("%d",a[i]);
        if(i != right - 1) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
    printf("%d\n",count);
    
    return(0);
    
}
