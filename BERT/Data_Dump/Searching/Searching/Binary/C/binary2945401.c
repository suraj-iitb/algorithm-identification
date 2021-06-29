#include <stdio.h>
int n;
int Bsearch(int A[],int key){
        int left=0,right=n;
        while(left<right) {
                int mid = (left + right)/2;
                if (A[mid] == key) {
                        return 1;
                }
                if (key > A[mid]) {
                        left = mid+1;
                }
                else if(key < A[mid]) {
                        right = mid;
                }
        }
        return 0;
}
int  main(){
        int A[1000000];
        int i,q,key,sum=0;
        scanf("%d",&n);
        for(i=0; i<n; i++) {
                scanf("%d",&A[i]);
        }
        scanf("%d",&q);
        for(i=0; i<q; i++) {
                scanf("%d",&key);
                if(Bsearch(A,key)) {
                        sum++;
                }
        }
        printf("%d\n",sum);

        return 0;
}

