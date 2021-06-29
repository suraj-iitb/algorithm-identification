#include <stdio.h>

int Selection(int A[],int N){
  int i,j;
  int temp;
  int sw=0;
  int minj;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj = j;
      }
    }
      temp = A[i];
      A[i]=A[minj];
      A[minj]=temp;
      if(i!=minj){
        sw++;
      
    }
  }
    return sw;
}

int main(){
  int A[100];
  int n;
  int i;
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  cnt = Selection(A,n);
  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%d ",A[i]);
      
    }
 
    else{
      printf("%d",A[i]);
      printf("\n");
      printf("%d",cnt);
      printf("\n");
    }
  }
   
    return 0;
}
/*int A[100];

void swap(int *a, int *b){     //swap the right side and left side
int temp;

temp = *a;
*a = *b;
*b = temp;
}


int main(){
int i=0,j=0; // iterator
int position;
int n;    //input
int cnt=0;


scanf("%d",&n);
for(i=0;i<n;i++){
  scanf("%d",&A[i]);
}

for(i=0;i< n;i++){
  position = i;                     
  for(j=i+1;j<n;j++){
    if(A[position]>A[j])
      swap(&A[i],&A[position]);
    cnt++;
  }
  
}

    
for(i=0;i<n-1;i++){
  printf("%d ",A[n]);
  
}
printf("%d",A[n]);    //prevent presentation error
printf("\n");
printf("%d",cnt);
printf("\n");
return 0;
}*/


