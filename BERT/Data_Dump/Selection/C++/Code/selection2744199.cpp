#include<cstdio>

int selec_sort(int *a, int n){
    int count=0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minj]) minj = j;
        }
        int tmp = a[minj];
        a[minj] = a[i];
        a[i] = tmp;
        if(minj != i) count++;
    }
    return count;
}

int main(){
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b = selec_sort(a, n);
    for(int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    printf("%d\n", b);
}

