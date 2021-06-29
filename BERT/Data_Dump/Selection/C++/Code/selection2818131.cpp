#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int a[105], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    int time = 0;
    for(int i = 0; i < n; i ++){
        int minj = i, minnum = a[i];
        for(int j = i + 1; j < n; j++){
            if(a[j] < minnum){
                minj = j;
                minnum = a[j];
            }
        }
        if(minj != i){
            time ++;
            swap(a[i], a[minj]);
        }
    }
    for(int i = 0; i < n - 1; i ++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    printf("%d\n", time);
    return 0;
}

