#include <stdio.h>

int main(int argc , char *argv[]){
    int n,q;
    int i,j;
    int N[100000];
    int Q[500000];
    int count=0;
    int right,left,mid;
    int key;
    
    /* scan N[] */
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&N[i]);
    }
    /* -------- */
    
    /* scan Q[] */
    scanf("%d",&q);
    
    for(i=0;i<q;i++){
        scanf("%d",&Q[i]);
    }
    /* --------- */

   
    for(i=0;i<q;i++) {
        key=Q[i];
        left=0;
        right=n;
    
            while(left < right){
                mid = (right+left)/2;
                if(key == N[mid]){count++;break;}
                if(key > N[mid])left=mid+1;
                else if(key<N[mid])right=mid;
                    }
        
        }
        printf("%d\n",count);
        return 0;
}
