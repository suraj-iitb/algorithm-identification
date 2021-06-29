#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000000
void merge(int [],int, int, int); 
void mergesort(int [],int,int); 


int c=0; 


int main(){ 
  
  int i; 
  int left; 
  int right; 
  int mid; 
  int n; 
  int *S; 
   
   
  scanf("%d ",&n);
  S=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){ 
     scanf("%d",&S[i]); 
   } 

   left=0; 
   right=n; 
   mergesort(S,left,right); 
        for(i=0;i<n;i++){ 
     printf("%d",S[i]);
     if(i==n-1) break;
     printf(" ");
   } 
   printf("\n"); 
   printf("%d\n",c); 

   return 0; 
 } 
 void merge(int S[],int left,int mid,int right) 
 { 
   int i,j; 
   int n1; 
   int n2; 
   int *L,*R;
   int k; 

   n1=mid-left; 
   n2=right-mid;
   L=malloc(sizeof(int)*n1+1);
   R=malloc(sizeof(int)*n2+1);
   for(i=0;i<n1;i++){ 
     L[i]=S[left+i]; 
   } 
   for(i=0;i<n2;i++){ 
     R[i]=S[mid+i]; 
   } 
   L[n1]=INFTY; 
   R[n2]=INFTY; 
   i=0; 
   j=0; 

   for(k=left;k<right;k++){ 
     if(L[i]<=R[j]){ 
       S[k]=L[i]; 
       i++; 
       c++; 
     } 
     else { 
       S[k]=R[j]; 
       j++; 
       c++; 
      
     } 
   } 
 }
 void mergesort(int S[],int left, int right) 
 { 
   int mid; 
   if(left+1<right){ 
     mid=(left+right)/2; 
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);
  }
}
 
  
    
  
