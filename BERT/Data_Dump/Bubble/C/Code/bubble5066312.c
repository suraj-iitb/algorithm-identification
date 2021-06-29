#include <stdio.h>

void swap(int*,int*);
int main(){

  int A[100];  //sequence A
  //int i; // Iterator
  int N; //element(input integer)
  int j=0;   //Iterator
  int cnt=0;  //counter
  int flag=0;
  int i=0;
  int k=0;
  
  scanf("%d",&N);//input the number of the elements

  for(j=0;j<=N-1;j++){        //input integers
    scanf("%d",&A[j]);    
  }                    
  for(k=0;k<N-1;k++){            //i<N --->N回まわる
    for(j=N-1;j>i;j--){       //数が確定したとき、１つ右にずれる。 --> i
      if(A[j] < A[j-1]) {        //if wrong order
	swap(&A[j],&A[j-1]);
	cnt++;                    //count swap 
      }
   
    }
    i++;
  }
  for(j=0;j<=N-2;j++){
    printf("%d ",A[j]);
  
  }
  printf("%d",A[N-1]);
  printf("\n");
  printf("%d\n",cnt);
  return 0;
  

}


void swap(int *a1, int *a2){  //textbook p109  *swap can change order between A[j]and A[j-1]
  int temp;

  temp = *a1;
  *a1 = *a2;
  *a2 = temp;
    
  
}

  










