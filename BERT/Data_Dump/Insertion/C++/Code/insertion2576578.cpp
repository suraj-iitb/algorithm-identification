#include <cstdio>
using namespace std;

void trace(int a[], int n){
    int i;
    
    for (i = 0; i < n; i++){
        printf("%d", a[i]);
        if (i < n-1) printf(" ");
    }
    printf("\n");
}

void insertionSort(int a[], int n){
    int i, v, j;
    
    for (i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            a[j] = v;
            j--;
        }
        trace(a, n);
    }
}

int main(void){
    int n, a[100], i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    trace(a, n);
    insertionSort(a, n);
    return 0;
}
