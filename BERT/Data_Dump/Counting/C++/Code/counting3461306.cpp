#include<stdio.h>

using namespace std;

int a[2000000];
int b[2000000];
int c[10001];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        c[a[i]]++;
    }

    for(int i = 1; i < 10001; i++){
        c[i] += c[i-1];
    }

    for(int i = n - 1; i >= 0; i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }

    for(int i = 0; i < n; i++){
        if(i){
            printf(" %d", b[i]);
        }
        else{
            printf("%d", b[i]);
        }
    }
    printf("\n");
}
