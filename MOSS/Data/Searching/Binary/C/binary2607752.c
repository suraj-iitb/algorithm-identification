#include<stdio.h>
   
   int S[1000000],N;
int binarySearch(int v){
int a=0;
int b=N;
int u;
int s[1000000];
while(a<b){
u=(a+b)/2;
if(v==S[u])
return 1;
if(v>S[u])
a=u+1;
else if(v<S[u])
b=u;
}

return 0;

}

int main(){
  
int i,k,q; 
int c =0;
   
    scanf("%d", &N);
     for ( i = 0; i < N; i++ ){ 
scanf("%d", &S[i]);
}
    
 scanf("%d", &q);
     for ( i = 0; i < q; i++ ){ 
scanf("%d", &k);

if(binarySearch(k))
c++;
}

   
  

      
  
   
    printf("%d\n",c);
   
    return 0;
}
