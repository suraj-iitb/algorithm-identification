#include<stdio.h>
#define N 100000
#define Q 50000
  
int binarysearch(int);
int S[N];
int n;
void sort(void);

main(){
    
  int q,T[N],x,count=0,i,j;
    
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);}
  
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);}
   
  for(i=0;i<q;i++){
    x= binarysearch(T[i]);
    
    if(x!=n){
      count++;
    }
  } 
  printf("%d\n",count);
  return 0;
}



void sort(void){
  
  int flag,i,j,x,minj;
  
  for(i=0;i<=n-1;i++){
    minj=i;
    flag=0;
    
    for(j=i;j<=n-1;j++){
      
      if(S[j]<S[minj]){
	minj=j;
	flag=1;}
    }
    
    if(flag==1){
      x=S[i];
      S[i]=S[minj];
      S[minj]=x; 
    }
  }
}
  
int binarysearch(int key){
  
  int left=0,right=n;
  int mid;
  
  while(left<right){
    mid=(left+right)/2;
    
    if(S[mid]==key)
      return mid;
    
    else if(key<S[mid])
      right=mid;
    else{
      left=mid+1;
    }
  }

  
  return n;
}
