#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    int cnt = 0;

    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(a[minj] > a[j]){
                minj = j;
            }
        }
        if(a[i] != a[minj]){
            swap(a[i], a[minj]);
            cnt++;
        }
    }

    for(int i = 0; i < n-1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
}

