#include<stdio.h>

int BSort(int t, int *S, int n){
    int high, mid, low;
    high = n;
    low = 0;
    while(low < high){
        mid = (high + low) / 2;
        if(S[mid] == t) return 1;
        else if(S[mid] < t) low = mid + 1;
        else high = mid;
    }
    return 0;
}
 
int main(){
    int i, j, cnt=0;
    int n, q;
    int S[100000];
    int key;
 
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    
    for(i=0;i<q;i++){
        scanf("%d", &key);
        cnt += BSort(key, S, n);
    }
    
    printf("%d\n", cnt);
 
    return 0;
}
