
 
#include <cstdio>
 
int selectionSort(int a[], int n) {
    int minv, counter = 0;
    for(int i=0; i<n-1; ++i) {
        minv = i;
        for(int j=i+1; j<n; ++j) 
            if(a[j] < a[minv]) minv = j;
        if(i != minv) {
            int t = a[minv]; a[minv] = a[i];
            a[i] = t; ++counter;
        }
    }
    return counter;
}
 
int main()
{
    #ifdef LOCAL
        freopen("E:\\Temp\\input.txt", "r", stdin);
        freopen("E:\\Temp\\output.txt", "w", stdout);
    #endif
 
    int n, counter, a[110];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
 
    counter = selectionSort(a, n);
    for(int i=0; i<n; ++i) {
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", counter);
 
    return 0;
}
