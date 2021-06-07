#include<stdio.h>
    
int S[1000000000],N;

int Search(int key){
int left=0;
int right=N;
int mid;
int s[10000000000];
while(left<right){
mid=(left+right)/2;
if(key==S[mid])
return 1;
if(key>S[mid])
left=mid+1;
else if(key<S[mid])
right=mid;
}
 
return 0;
 
}
 
int main(){
   
int i,k,q; 
int count = 0;
    
scanf("%d", &N);
for ( i = 0; i < N; i++ )
scanf("%d", &S[i]);

     
 scanf("%d", &q);
 for ( i = 0; i < q; i++ ){ 
scanf("%d", &k);
if(Search(k)==1)
count++;
}
    printf("%d\n",count);
    return 0;
}
