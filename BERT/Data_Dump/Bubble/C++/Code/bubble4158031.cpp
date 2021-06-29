#include <cstdio>
using namespace std;
int bubble(int a[], int n) {
    int flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for(int i = n-1; i > 0; i--) {
            if(a[i] < a[i-1]) {
                a[i] = a[i] + a[i-1];
                a[i-1] = a[i] - a[i-1];
                a[i] = a[i] - a[i-1];
                count++;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d\n", bubble(a, n));
}
