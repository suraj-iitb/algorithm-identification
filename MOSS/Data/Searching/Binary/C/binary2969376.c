#include <stdio.h>

#define N 100000

int binarySearch(int[],int[],int,int);

int main(){
    
    int i,n,q;
    
    scanf("%d",&n);
    
   if(n<=N){
        
        int s[N];
        
        for(i=0 ; i<n ; i++){
            scanf("%d",&s[i]);
        }

        scanf("%d",&q);
        
       if(q<=N){
            
            int t[N];
            
            for(i=0 ; i<q ; i++){
                scanf("%d",&t[i]);
            }
            
            printf("%d\n",binarySearch(s,t,n,q));

        }
    }
    return 0;
}


int  binarySearch(int s[N],int t[N],int n,int q){
    int count=0,key,i,mid,left=0,right = n;
    for(i=0;i<q;i++){
        key = t[i];
        left = 0;
        right = n;
        while(left<right){
            mid = (left+right)/2;
            if(s[mid] == key){
                count++;
                break;
            }
            else if(key<s[mid]) right = mid;
            else left = mid + 1;
        }
    }
    return count;
}

