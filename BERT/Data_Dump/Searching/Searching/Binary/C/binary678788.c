#include <stdio.h>
#define N 100000
#define Q 50000
 
void search(int[],int);

int count=0;
int n,q;

int main(void){
  
  int S[N];
  int T[Q];
  int i;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&T[i]); 
    search(S,T[i]);
  }
  
  printf("%d\n",count);
  
  return 0;
}

void search(int S[],int key){
  
  int flag = 0;
  int mid;
  int left = 0;
  int right = n;


  while(left <= right){
    mid = (left+right)/2;

    if(S[mid] == key){
      flag = 1;
      break;
    }
    
    else if(S[mid] < key)
      left = mid +1;
    
    else if(S[mid] > key)
      right = mid -1;
  }

  if(flag ==1)
    count++;
  
}
