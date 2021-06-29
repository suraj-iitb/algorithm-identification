#include<stdio.h>

typedef struct{

  char alf;
  int num;
  int beforei;
  
}key;

int partition(key *,int,int);

void quicksort(key *,int,int);


int main(){

  int i,n,j,point=0;
  key A[100000];

  scanf("%d%*c",&n);

  for(i=0;i<n;i++){

    scanf("%c%d%*c",&A[i].alf,&A[i].num);
    A[i].beforei=i;

  }

  quicksort(A,0,n-1);


  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
    
      if(A[i].num==A[j].num&&A[i].beforei>A[j].beforei){
	printf("Not stable\n");
	point++;
	break;
      }
      if(point==1)break;
    }
    if(point==1)break;
  }

  if(point==0) printf("Stable\n");
  

  for(i=0;i<n;i++){

    printf("%c %d\n",A[i].alf,A[i].num);

  }

  return 0;

}

int partition(key *A,int p,int r){

  int i,j,x;
  key kari;
  
  x=A[r].num;
  i=p-1;

  for(j=p;j<r;j++){

    if(A[j].num<=x){
      i++;
      kari=A[i];
      A[i]=A[j];
      A[j]=kari;
      
    }
  }

  kari=A[i+1];
  A[i+1]=A[r];
  A[r]=kari;
  
    
  return i+1;
}



void quicksort(key *A,int p,int r){

  int q;

  if(p<r){

    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);

  }



  
}
