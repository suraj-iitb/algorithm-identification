#include <stdio.h>

#define N 100000

int linerSearch(int[],int[],int,int);

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
            
            printf("%d\n",linerSearch(s,t,n,q));

        }
    }
    return 0;
}


int  linerSearch(int s[N],int t[N],int n,int q){
    int i,j=0,count=0,key;
    for(i=0 ; i<q ; i++){
        j = 0;
        key = t[i];
        while(s[j] != key){
           j++;
           if(j==n)break;
        }
        if(j!=n)count++;
    }
    return count;
}

