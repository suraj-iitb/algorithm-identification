#include <cstdio>
 
void trace(int a[], int n) {
    for(int i=0; i<n; ++i) {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}
 
void insertionSort(int a[], int n) {
    for(int i=1; i<n; ++i) {
        int j = i-1, v = a[i];
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = v;
        trace(a, n);
    }
}
 
int main()
{
    #ifdef LOCAL
        freopen("E:\\Temp\\input.txt", "r", stdin);
        freopen("E:\\Temp\\output.txt", "w", stdout);
    #endif
 
    int n, a[110];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    
    trace(a, n);
    insertionSort(a, n);
 
    return 0;
}
