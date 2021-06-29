#include<stdio.h>

int linearSSearch(int A[],int n,int key){
int i;

for( i = 0; i < n; i++){
	if (A[i] == key)
	return 1;
}
return 0;
}





int main(){

  int i,n,d,f,total=0;
  scanf("%d",&n);
  int A[10000+50];
  int B[1000];
  for (i=0;i<n;i++){
  
  scanf("%d",&A[i]);
  }
  scanf("%d",&d);
  for(i=0;i<d;i++){
  scanf("%d",&B[i]);
  }
  for(i=0;i<d;i++){
  
  if (linearSSearch(A,n,B[i])) total++;
 }
  printf("%d\n",total);
  
 return 0;
}



