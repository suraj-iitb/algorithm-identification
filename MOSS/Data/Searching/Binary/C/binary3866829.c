#include<stdio.h>
int binerySearch(int a[], int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(a[mid] == key) 
            return mid;
        else if(a[mid] > key) 
            right = mid;
        else 
            left = mid + 1;
    }
    return 0;
}
int main() {
    int i, n, a[100001], q, key, sum = 0;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    scanf("%d\n", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &key);
        if(binerySearch(a, n, key)) {
            sum++;
        }
    }
    printf("%d\n", sum);

}
