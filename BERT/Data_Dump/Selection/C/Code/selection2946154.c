#include<stdio.h>


void selectsort(int n,int a[]);


int main(void){


   int N;
   scanf("%d",&N);
   
   int i,flag=1,array[N];
   for(i=0;i<N;i++)  {scanf("%d",&array[i]);}

   selectsort(N,array);
   return 0;
   
   

 }


void selectsort(int n,int a[]){
  int i,j,kae,count=0,minj;


 
    for(i=0;i<n-1;i++){
      minj=i;
      
      for(j=i;j<n;j++){
	if(a[j]<a[minj]){minj=j;}}


      kae=a[i];
	a[i]=a[minj];
	a[minj]=kae;

	if(i!=minj)count++;
	
      }
     
    

  
  
  for(j=0;j<n;j++){

    if(j==n-1) printf("%d",a[j]);
  else if (j!=n){printf("%d ",a[j]);}

  }
  printf("\n%d\n",count);
}

