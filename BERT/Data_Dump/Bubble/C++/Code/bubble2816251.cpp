#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n, a[105];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int time = 0, flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                time ++;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    printf("%d\n", time);
    return 0;
}

