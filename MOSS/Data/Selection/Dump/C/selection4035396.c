#include<stdio.h>
#define N 100
void swap(int*,int*);

int main(){
  int data[N],i,j,n,minj,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(data[j]<data[minj]){
	minj=j;
      }
    }
      if(i!=minj){
	swap(&data[i],&data[minj]);
	count++;
	  }
  }
  
 for(i=0;i<n;i++){
   printf("%d",data[i]);
   if(i!=n-1)
     printf(" ");
 }
 printf("\n%d\n",count);

 return 0;
    
}

void swap(int*x,int*y){
  int data;

  data=*x;
  *x=*y;
  *y=data;
}

