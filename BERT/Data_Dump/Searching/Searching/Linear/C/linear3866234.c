#include<stdio.h>
int search(int a[], int n, int key){
    int i = 0;
    a[n] = key;
    while(a[i] != key) 
        i++;
    return i != n;   
}
int main() {
    int i, n, a[10001], q, key, sum = 0;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    scanf("%d\n", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &key);
        if(search(a, n, key)) {
            sum++;
        }
    }
    printf("%d\n", sum);

}
