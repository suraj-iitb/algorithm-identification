#include<cstdio>

int bubble_sort(int *a, int n){
    int count=0;
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j >= i+1; j--){
            if(a[j] < a[j-1]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b = bubble_sort(a, n);
    for(int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    printf("%d\n", b);
}

