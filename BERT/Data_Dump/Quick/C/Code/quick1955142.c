#include<stdio.h>
#include<string.h>
#define INFTY 200000000
#define MAX 200000

struct card{

  char character;
  int value;

};

void Merge(struct card[], int, int, int,int);
void MergeSort(struct card[],int, int, int);
void QuickSort(struct card[],int,int,int);
int Partition(struct card[],int,int,int);


struct card leftcard[MAX / 2 + 10];
struct card rightcard[MAX / 2 + 10];

int main(){

  char a,b;
  int i,j,flag;
  int sumcard;
  struct card mergesortdata[MAX];
  struct card quicksortdata[MAX];

  flag = 0; 
  scanf("%d",&sumcard);

  for(i = 0; i < sumcard; i++){

    scanf(" %c %d",&mergesortdata[i].character,&mergesortdata[i].value);

    //    printf("%c",mergesortdata[i].character);
    quicksortdata[i].character = mergesortdata[i].character;

    //    printf("%c",quicksortdata[i].character);
    quicksortdata[i].value = mergesortdata[i].value;

  }

  MergeSort(mergesortdata,sumcard,0,sumcard);

  QuickSort(quicksortdata,sumcard,0,sumcard-1);

  for(i = 0; i < sumcard; i++){

    if((char) mergesortdata[i].character !=  (char)quicksortdata[i].character){

//      printf("%c",mergesortdata[i].character);
   //   printf("%c",quicksortdata[i].character);
      flag = 1;

    }

  }

  if(flag == 1){

    printf("Not stable\n");

  }

  else{

    printf("Stable\n");

  }

  
  for(i = 0; i < sumcard; i++){

    // printf("%c",quicksortdata[i].character);
    printf("%c %d\n",quicksortdata[i].character,quicksortdata[i].value);

    }

 

  
  return 0;

}

void MergeSort(struct card inputdata[], int sumcard, int left, int right){

  int mid;

  if(left + 1 < right){

    mid = (right + left) /2;

    MergeSort(inputdata,sumcard,left,mid);

    MergeSort(inputdata,sumcard,mid,right);

    Merge(inputdata,sumcard,left,mid,right);

  }

}
	 
void Merge(struct card inputdata[],int sumdata, int left,int mid, int right){

  int i,j,k;
  int leftsumdata;
  int rightsumdata;

  j = 0;
  k = 0;

  leftsumdata = mid - left;

  rightsumdata = right -mid;

  for(i = 0; i < leftsumdata; i++){

    leftcard[i] = inputdata[left + i];

  }

  for(i = 0; i < rightsumdata; i++){

    rightcard[i] = inputdata[mid + i];

  }

  leftcard[leftsumdata].value = INFTY;

  rightcard[rightsumdata].value = INFTY;


  i = 0;
  j = 0;

  for(k = left; k < right; k++){

    if(leftcard[j].value > rightcard[i].value){

      inputdata[k] = rightcard[i];

      i = i + 1;
    }

    else{

      inputdata[k] = leftcard[j];

      j = j + 1;

    }

  }

}

void QuickSort(struct card inputdata[], int sumcard, int partition ,int right){

  int q;

  if(partition < right){

    q = Partition(inputdata,sumcard,partition,right);

    QuickSort(inputdata,sumcard,partition,q -1);
    QuickSort(inputdata,sumcard,q+1,right);

  }

}

int  Partition(struct card inputdata[],int sumcard,int partition,int right){

  int standard = inputdata[right].value;
  int i = partition -1;
  int j;
  int change;
  struct card A,B;

  for(j = partition; j < right; j++){

    if(inputdata[j].value <= standard){

      i = i + 1;

      B = inputdata[i];

      inputdata[i] = inputdata[j];

      inputdata[j] = B;

    }

  }

  B = inputdata[i + 1];

  inputdata[i + 1] = inputdata[right];

  inputdata[right] = B;

  return i + 1;
}
