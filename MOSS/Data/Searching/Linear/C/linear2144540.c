#include<stdio.h>

int S[10000];
int T[500];

int search(int* S, int n, int* T, int q){
    int i,j;
    int ans = 0;
    for(i=0; i<q;i++){
        for(j=0;j<n;j++){
            if(S[j]==T[i]){
                ans++;
                break;
            }
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
