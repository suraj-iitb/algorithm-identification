#include <stdio.h>
#define MAX 100

int chenge;

int check(int [],int);
void SelectionSort(int [],int);
void swap(int [],int,int);

int main(void){
  
  int i,n;
  int A[MAX];
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  /*??????????????????????????????????????????????????則??????
    ?????????????????????????????????????????則????????属???
    ???????????????????????????*/
  if(check(A,n) == 1)
  SelectionSort(A,n);

  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);


  printf("%d\n",chenge);

  return 0;
}

//????????即???????????\??????????????????????賊???????
void SelectionSort(int A[],int n){

  int i,j;
  int mini;
  int flag;

  chenge = 0;

  for(i=0;i<n;i++){
    mini = i;
    flag=0;
    for(j=i+1;j<n;j++){
      if(A[j] < A[mini]){
        mini = j;
	flag=1;
      }   
    }
    swap(A,i,mini);

    if(flag==1)
    chenge++;   
  }
}

//??卒????????\?????????
void swap(int A[],int i,int mini){

  int tmp;

  tmp = A[i];
  A[i] = A[mini];
  A[mini] = tmp; 
}


//???????????????????????????????????????????????則??????
int check(int A[],int n){
  
  int i,j;
  int count=0;
  int check;
  
  for(i=0;i<n;i++){
    check = A[i];
    for(j=i+1;j<n;j++){
      if(check > A[j])
	count++;
    }
  }
  if(count == 0)
    return 0;

  else
    return 1;
}
