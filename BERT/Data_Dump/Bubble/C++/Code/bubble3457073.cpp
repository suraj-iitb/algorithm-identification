#include<stdio.h>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = n - 1; i > 0; i--){
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                flag = true;
                cnt++;
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
}
