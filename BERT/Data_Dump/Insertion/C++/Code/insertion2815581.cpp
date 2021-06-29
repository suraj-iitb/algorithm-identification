#include<cstdio>
#include<algorithm>
using namespace std;

void print(int a[], int n){
    int first = 1;
    for(int i = 0; i < n; i++){
        if(first) first = 0;
        else printf(" ");
        printf("%d", a[i]);
    }
}

int main(){
    int a[105], n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n - 1; i++){
            print(a, n);
            puts("");
            int x = a[i + 1];
            int b = upper_bound(a, a + i + 1, x) - a, j;
            for(j = i; j >= b; j--){
                a[j + 1] = a[j];
            }
            a[j + 1] = x;
        }
        print(a, n);
        puts("");
    }
    return 0;
}

