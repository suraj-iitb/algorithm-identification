#include<stdio.h>

int search(int A[], int n, int key){
   int i = 0;
   A[n] = key;
   while (A[i] != key )
     i++;
     return i != n;
}

int main(){
    int n;
    int q;
    int i;
    int A[10000+1];
    int key;
    int sum = 0;
    
    
    scanf("%d",&n);
    for(i = 0; i < n; i++)
      scanf("%d",&A[i]);/*nの個数分読み込みを繰り返す*/
    
    
    scanf("%d",&q);
    for(i = 0; i < q; i++){
      scanf("%d",&key);/*qの個数分読み込みを繰り返す*/
      if(search(A,n,key))
        sum++;
    }    
    printf("%d\n",sum);
    
    return 0;
}    



