#include<stdio.h>

int S[100000];
int T[50000];

int search(int* S, int n, int* T, int q){
    int i;
    int left, mid, right;
    int ans = 0;
    for(i=0; i<q;i++){
        left = 0;
        right = n-1; 
        while(left <= right){
            mid = (left + right)/2;
            if(T[i] == S[mid]){
                ans++;
                break;
            }
            if(T[i] > S[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return ans;
}


int main(void){
    int n,q;
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &T[i]);
    }
    
    printf("%d\n", search(S,n,T,q));
    return 0;
}
