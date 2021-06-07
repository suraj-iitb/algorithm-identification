#include<stdio.h>

 int linerSearch(int n,int S[],int key){
	int i=0;
	S[n]=key;
	while(S[i] != key)
		i++;
	return i != n;
         }

 int main(){
         int n,S[10000],q,key,i,count=0;
         scanf("%d",&n);
         for(i=0;i<n;i++){scanf("%d",&S[i]);}

         scanf("%d",&q);
         for(i=0;i<q;i++){
                   scanf("%d",&key);
                   if(linerSearch(n,S,key))count++;
                   }


         printf("%d\n",count);
         return 0;
         }
