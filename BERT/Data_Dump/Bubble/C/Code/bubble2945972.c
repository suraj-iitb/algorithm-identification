#include<stdio.h>


void bubble(int n,int a[]);


int main(void){


   int N;
   scanf("%d",&N);
   
   int i,flag=1,array[N];
   for(i=0;i<N;i++)  {scanf("%d",&array[i]);}

   bubble(N,array);
   return 0;
   
   

 }


void bubble(int n,int a[]){
  int flag=1,j,kae,count=0;


  while (flag==1){
    flag=0;
    for(j=n-1;j>0;j--){
      
      if(a[j]<a[j-1]){
	kae=a[j-1];
	a[j-1]=a[j];
	a[j]=kae;
	count++;
	flag=1;
      }
    }

  }
  
  for(j=0;j<n;j++){

    if(j==n-1) printf("%d",a[j]);
  else if (j!=n){printf("%d ",a[j]);}

  }
  printf("\n%d\n",count);
}

