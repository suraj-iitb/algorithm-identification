#include<stdio.h>

#define MAX_S 100000
#define MAX_T 50000

void insertionSort(int *b,int k){
  int i,j,v;
  
  for(i = 1; i < k; i++){
    v = b[i];
    j = i - 1;
    while(j >= 0 && b[j] > v){
      b[j + 1] = b[j];
      j--;
    }
    b[j + 1] = v;
  }

}

int binarySearch(){
  int n,q,count,i,j,mid,r,l,a,b,c;
  int s[MAX_S],t[MAX_T];

  count = 0;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&s[i]);
  insertionSort(s,n);
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    scanf("%d",&t[i]);

  

   
  for(i = 0; i < q; i++){
    a = 0;
    b = n / 2;
    c = n - 1;
    l = s[a];
    mid = s[b];
    r = s[c];

    while(1){
      if(mid >= t[i]){ 
	c = b;
	b = (a + c)/2;
      }
      else {
	a = b + 1;
	b = (a + c)/2;
      }
      
      l = s[a];
      mid = s[b];
      r = s[c];
    
 
      
      if(mid == t[i]){

	count++;
	break;
      }
      if(l == r)
	break;
      else if(l > r)
	break;
    }
  }
  
  return count;
}

int main(){

  printf("%d\n",binarySearch());
  
  return 0;
}

