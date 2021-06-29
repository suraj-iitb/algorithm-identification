#include <stdio.h>
void print(int a[], int n){
    for(int i = 0; i < n; i++) {
        if(i == n-1) printf("%d\n", a[i]);
        else printf("%d ", a[i]);
    }
}

void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int v = a[i];
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        print(a, n);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    print(a, n);

    insertSort(a, n);
    return 0;
}
