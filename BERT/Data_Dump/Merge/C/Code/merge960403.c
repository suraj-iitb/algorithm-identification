#include <stdio.h>
#define MAX 1000000000;
int A[500000];
int Lef[500000],Rig[500000];
int count=0;

void Merge(int left,int mid,int right){
  int a,b,i,j,k;	
  a=mid-left;	
 b=right-mid;
   
  for(i=0;i<a;i++)
    {
      Lef[i]=A[left+i];
    }
  for(i=0;i<b;i++)
    {
      Rig[i]=A[mid+i];
    }
  Lef[a]=MAX;
  Rig[b]=MAX;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      count++;
      if(Lef[i]<=Rig[j])
    {
      A[k]=Lef[i];
      i++;
    }
      else
    {
    	  A[k]=Rig[j];
      j++;
    }	
   }	
}	
 	
void Mergesort(int left,int right){
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      Mergesort(left,mid);
      Mergesort(mid,right);
      Merge(left,mid,right);
    }
		}
	
main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
 
  Mergesort(0,n);
 
  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i<n-1)
    {
      printf(" ");
    }
    }
  printf("\n");
  printf("%d\n",count);
return 0;
}
