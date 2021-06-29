#include<stdio.h>
#include<stdlib.h>
int A[100001],n,count=0,count2=0,count3=0;
char B[100001];
int A2[100001];
char B2[100001];
//char C[100001][100001];
int Partition(int A[], int p, int r);
void Quicksort(int A[], int p ,int r);

int main(){
  int i,j,m;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    getchar();
    scanf("%c %d", &B[i], &A[i]);
  }
  for(i=0;i<n;i++){
     A2[i]=A[i];
     B2[i]=B[i];
   }



  m= Partition(A,0,n-1);
  Quicksort(A,0,n-1);

  

  
  for(i=0;i<n;i++){
    if(A[i] == A[i+1]){
      for(j=0;j<n;j++){
     
	if(A[i] == A2[j] && B[i] == B2[j]){
	  count=j;
	}

	if(A[i+1] == A2[j] && B[i+1] == B2[j]){
	  count2=j;
	}
      }
	//printf("count = %d count2 = %d \n ",count,count2);    
	if(count > count2){
	 count3++ ;
	 break;
	}

	// }
      
      
    }
  }
  
 
  if(count3==0)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i],A[i]);
    //printf("%c %d %c %d\n",B[i],A[i],B2[i],A2[i]);



 }
 
 

  return 0;
}


int Partition(int A[], int p,int r){
  int x,i,j,temp,temp2,t,t2;

  x = A[r];
  i = p-1;

  // printf("x = %d\n",x);

  for(j=p;j<=r-1;j++){
    if(A[j] <= x){
      
      i += 1;
      temp = A[i];
      A[i]=A[j];
      A[j]= temp;

      t = B[i];
      B[i]=B[j];
      B[j]= t;

    }
  }

  temp2 = A[i+1];
  A[i+1] = A[r]; 
  A[r]= temp2;  

  t2 = B[i+1];
  B[i+1] = B[r]; 
  B[r]= t2;  
  
  return i+1;
}

void Quicksort(int A[], int p, int r){
  int q;

  if (p < r){

    q = Partition(A,p,r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
  
}
