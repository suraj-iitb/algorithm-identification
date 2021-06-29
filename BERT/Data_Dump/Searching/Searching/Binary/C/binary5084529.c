#include <stdio.h>
#include <stdlib.h>
int search(int, int *, int);
int main(){
    int n, m, i, s = 0;
    int *a, *b;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for(i=0; i < n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d", &m);
    b = malloc(sizeof(int) * m);
    for(i=0; i < m; i++){
        scanf("%d",&b[i]);
    }
    for(i = 0; i < m; i++){
        s += search(n, a, b[i]);
    }
    printf("%d\n", s);

    return 0;
}

int search(int n, int *A, int key){
    int left, right, mid;
    left = 0;
    right = n;
    while( left < right){
        mid = (left + right) / 2;
        if(A[mid] == key){
            //printf("--%d--\n", mid);
            return 1;
        }
        else if( key < A[mid]) 
            right = mid;
        else
            left = mid + 1;
    }
    return 0;
}
