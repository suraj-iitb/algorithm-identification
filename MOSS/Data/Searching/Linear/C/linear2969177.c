#include <stdio.h>
#define N 100000
int LinerSearch(int A[], int n, int key){
        int i=0;
        A[n]=key;
        while(A[i]!=key) {
                i++;
        }
        return i != n;
}

int main(){
        int i,n,A[N+1],q,key,Sum=0;
        scanf("%d",&n);
        for(i=0; i<n; i++) {
                scanf("%d",&A[i]);
        }
        scanf("%d",&q);
        for(i=0; i<q; i++) {
                scanf("%d",&key);
                if(LinerSearch(A,n,key)) {
                        Sum++;
                }
        }
        printf("%d\n",Sum);
        return 0;
}

