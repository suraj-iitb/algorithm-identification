#include <stdio.h>
#define N 10000

    int A[N + 1],n,key;
    
int linearSearch(){
    int i = 0;
    A[n] = key;
    while(A[i] != key) i++;
    if(i == n) return 1;
    return 0;
}

int main(void){
    int i;
    int q,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(linearSearch() == 0) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
