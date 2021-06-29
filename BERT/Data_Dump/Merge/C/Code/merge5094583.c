#include <stdio.h>
#include <stdlib.h>
int x = 0;
void merge(int *, int, int, int);void
 merge_sort(int *, int, int);
int main(){
    int n, i;
    int *a;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i=0; i < n; i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a, 0, n);
    for(i=0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n",a[n - 1], x);
    free(a);
    return 0;
}

void merge(int *a, int left, int mid, int right){
    int n1, n2, i, j, k;
    int *l, *r;
    n1 = mid - left;
    n2 = right - mid;
    l = malloc(sizeof(int)*(n1 + 1));
    r = malloc(sizeof(int)*(n2 + 1));
    for(i = 0; i < n1; i++){
        l[i] = a[left + i]; 
    }
    for(i = 0; i  < n2; i++){
        r[i] = a[mid + i];
    }
    l[n1] = 999999999;
    r[n2] = 999999999;
    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        x++;
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
    free(r);
    free(l);
}

void merge_sort(int *a, int left, int right){
    int mid;
    if(left+1 < right){
    mid = (left + right)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid, right);
    merge(a, left, mid, right);
    }
}
