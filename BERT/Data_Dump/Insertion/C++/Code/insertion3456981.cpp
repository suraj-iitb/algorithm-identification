#include<stdio.h>
#include<algorithm>

void print(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
}

int main(){
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    print(a, n);

    for(int i = 1; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        print(a, n);
    }
}
