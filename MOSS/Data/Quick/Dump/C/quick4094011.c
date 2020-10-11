#include <stdio.h>
#define HUGE 1000000001 
typedef struct{
  int value;
  char suit;
}Record;

void  mergesort(Record *,int,int);
void merge(Record * , int ,int,int);
void Quick(Record *, int, int);
int Partition(Record *, int ,int );

int main(){
  /*dataA usu quick sort and dataB use merge sort*/
  Record dataA[100000],dataB[100000]; 
  int num,i,p,flag=1;
  char array[10];

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%s %d",array,&dataA[i].value);
    dataA[i].suit=array[0];
    dataB[i].value=dataA[i].value;
    dataB[i].suit=dataA[i].suit;
  }
 
  Quick(dataA,0,num-1);
  mergesort(dataB,0,num);

  for(i=0;i<num; i++){
    if(dataA[i].suit!=dataB[i].suit) flag=0;
  }
  if(flag==0)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<num;i++)  printf("%c %d\n",dataA[i].suit,dataA[i].value);
  return 0;
}

void mergesort(Record *data,int left, int right){
  int mid;
  if(left<right-1){
    mid=(left+right)/2;
    mergesort(data,left,mid);
    mergesort(data,mid,right);
    merge(data,left,mid,right);
  }
}

void merge(Record  *data,int left,int mid, int right){
  int i,j,k,num1,num2;
  Record array1[50001],array2[50001];
  num1=mid-left;
  num2=right-mid;
  for(i=0;i<num1;i++) {
    array1[i].value=data[left+i].value;
    array1[i].suit=data[left+i].suit;/*left array*/
  }
  for(i=0;i<num2;i++){
    array2[i].value=data[mid+i].value;
    array2[i].suit=data[mid+i].suit;/*right array*/
  }
  array1[num1].value=HUGE; /*insert huge value in array as a keeper*/
  array2[num2].value=HUGE;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    
    if(array1[i].value<=array2[j].value){
      data[k].value=array1[i].value;
      data[k].suit=array1[i].suit;
      i++;
    }
    else{
      data[k].value=array2[j].value;
      data[k].suit=array2[j].suit;
      j++;
    }
  }
}

void Quick(Record *data,int p, int last){
  int q;
  if(p<last){
    q=Partition(data,p,last);
    Quick(data,p,q-1);
    Quick(data,q+1,last);
  }
}

int Partition(Record *data, int p, int last){
  int changenum,i,j;
  char changechar;

  i=p-1;
  for(j=p;j<last;j++){
    if(data[j].value<=data[last].value){
      i++;
      changenum=data[j].value;
      data[j].value=data[i].value;
      data[i].value=changenum;

      changechar=data[j].suit;
      data[j].suit=data[i].suit;
      data[i].suit=changechar;
    }
  }
  changenum=data[last].value;
  data[last].value=data[i+1].value;
  data[i+1].value=changenum;

  changechar=data[last].suit;
  data[last].suit=data[i+1].suit;
  data[i+1].suit=changechar;
  return i+1;
}

