#include <stdio.h>

typedef struct{
  char mark;
  int number;
}Card;
void merge(int ,int ,int );
void mergesort(int ,int );
int partition(int ,int );//return element of head(now)
void quicksort(int ,int );

Card Merge[100000],Quick[100000],Left[50001],Right[50001],temp,final;
int n;
int main(void){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&Merge[i].mark,&Merge[i].number);
    Quick[i].mark=Merge[i].mark;
    Quick[i].number=Merge[i].number;
  }
  mergesort(0,n);
  quicksort(0,n-1);

  i=0;
  while(i<n){
    if(Merge[i].mark!=Quick[i].mark){
      i=0;
      break;
    }
    i++;
  }

  if(i==n)printf("Stable\n");
  else printf("Not stable\n");

  i=0;
  while(i<n){
    printf("%c %d\n",Quick[i].mark,Quick[i].number);
    i++;
  }
  return 0;
}
void mergesort(int left,int right){
  int mid;
  if(right-left>1){
    mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}
void merge(int left,int mid,int right){
  int n1=mid-left,n2=right-mid,i,j,k;
  for(i=0;i<n1;i++)
    Left[i]=Merge[left+i];
  for(i=0;i<n2;i++)
    Right[i]=Merge[mid+i];
  Left[n1].number=1000000001;
  Right[n2].number=1000000001;
  i=0;j=0;k=left;
  while(k<right){
    if(Left[i].number>Right[j].number)
      Merge[k++]=Right[j++];
    else Merge[k++]=Left[i++];
  }
}
void quicksort(int head,int last){
  int element;
  if(last-head>0){
    element=partition(head,last);
    quicksort(head,element-1);
    quicksort(element+1,last);
  }
}
int partition(int head,int last){
  int i,j;
  final=Quick[last];
  for(i=head;i<last;i++){
    if(Quick[i].number<=final.number){
      temp=Quick[head];
      Quick[head++]=Quick[i];
      Quick[i]=temp;
    }
  }
  temp=Quick[head];
  Quick[head]=Quick[last];
  Quick[last]=temp;
  return head;
}
