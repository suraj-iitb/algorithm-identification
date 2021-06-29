

#include <stdio.h>

int search(int A[],int n,int key){
 int i = 0;
 int a = 0;
 A[n] = key;


  while(A[i] != key){
    i++;
 }
 if(i != n)
   a = 1;
 return a;

}


int main(){
 int i, n, q, S[10000+1], c , key= 0;
 
 scanf("%d",&n);
 for(i = 0;i < n;i++){
   scanf("%d ",&S[i]);
  }
 scanf("%d",&q);
 for(i = 0;i < q;i++){
   scanf("%d ",&key);
   if(search(S, n, key) == 1)
      c++;
 }

 printf("%d\n",c);
 return 0;
}
