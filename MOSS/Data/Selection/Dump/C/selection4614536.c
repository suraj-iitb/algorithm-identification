#include<stdio.h>
#define swap(a,b)({a ^= b; b ^= a; a ^= b;})
int main(){
    int n, i, j, a[101], count, mini;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    count=0;
    for(i = 0; i<n; i++){
        mini = i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[mini]) mini = j;
        }
        if(i != mini){
            count++;
            swap(a[i], a[mini]);
        }
    }
    for(i=0;i<n-1;i++)printf("%d ", a[i]);printf("%d\n", a[i]);
    printf("%d\n", count);

return 0;
}

