#include<stdio.h>

#define N 500000
 
int L[(N/2)+2],R[(N/2)+2];
int a;
 
void merge(int b[],int l,int m,int r){
  int d,i,j,e=m-l,f=r-m;
  
  for(i=0;i<e;i++){
    
  L[i]=b[l+i];
  
  }
  
  for(i=0;i<f;i++){
    
  R[i]=b[m+i];
  
  }
  
  L[e]=1000000000;
  
  R[f]=1000000000;
  
  i=0;
  
  d=0;
  
  for(j=l;j<r;j++){

      a++;
      
      if(L[i]<=R[d]){
	
        b[j]=L[i];
	
	i+=1;
	
      }
      
      else {
	
      b[j]=R[d];
      
      d+=1;
      
      }
    }
}

void mergeSort(int b[],int l,int r){

  int m;
  
  if(l+1<r){
    
    m=(l+r)/2;
    
    mergeSort(b,l,m);
    
    mergeSort(b,m,r);
    
    merge(b,l,m,r);
    
  }
}
 
int main(){
  
  int b[N],c,i;
  
  a=0;
  
  scanf("%d",&c);
  
  for(i=0;i<c;i++){
    
  scanf("%d",&b[i]);
  
  }
  
  mergeSort(b,0,c);
  
  for(i=0;i<c-1;i++){
    
    printf("%d ",b[i]);
    
  }
  
   printf("%d\n",b[c-1]);
   
   printf("%d\n",a);
 
  return 0;
}

