#include<stdio.h>
#include<stdlib.h>

#define n_MAX 100000
#define C_MAX 1000000000

typedef struct CARD{
  char mark;
  int num;
}Card;



void mgsort(Card*,int,int,int);
void merge(Card *,int,int,int,int);
int partition(Card *, int, int,int);
void quicksort(Card *, int, int,int);

void judge(Card*,Card*,int);

Card Le[n_MAX/2+2];
Card Ri[n_MAX/2+2];

int main(){
  int n;
  int i;
  Card *c1,*c2;

  scanf("%d",&n);
  //if(n<1 || n_MAX<n) exit(1);

  

  c1=(Card *)malloc((n+1)*sizeof(Card));
  c2=(Card *)malloc((n+1)*sizeof(Card));

  for(i=0; i<n; i++){
    getchar();
    scanf("%c ",&c1[i].mark);
    scanf("%d",&c1[i].num);
    c2[i].mark=c1[i].mark;
    c2[i].num=c1[i].num;
    //printf("%c %d\n",c2[i].mark,c2[i].num);
  }

  mgsort(c1,n,0,n);
  quicksort(c2,n,0,n-1);

  judge(c1,c2,n);

  for(i=0; i<n; i++){
    //printf("%c %d\n",c1[i].mark,c1[i].num);
    printf("%c %d\n",c2[i].mark,c2[i].num);
  }

  return 0;
}

int partition(Card *c,int n,int p,int r){
  int i,j;
  Card x,t;
  x=c[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(c[j].num<=x.num){
      i++;
      t=c[i];
      c[i]=c[j];
      c[j]=t;
    }
  }

  t=c[i+1];
  c[i+1]=c[r];
  c[r]=t;
  
  return i+1;
}

void quicksort(Card *c,int n, int p,int r){
  int a;
  if(p<r){
    a=partition(c,n,p,r);
    quicksort(c,n,p,a-1);
    quicksort(c,n,a+1,r);
  }
}

void mgsort(Card *c,int n,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mgsort(c,n,left,mid);
    mgsort(c,n,mid,right);
    merge(c,n,left,mid,right);
  }
}

void merge(Card*c,int n,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;

  for(i=0;i<n1;i++)
    Le[i]=c[left+i];
  for(i=0;i<n2;i++)
    Ri[i]=c[mid+i];

  Le[n1].num=Ri[n2].num=1000000;

  i=j=0;
  for(k=left;k<right;k++){
    if(Le[i].num<=Ri[j].num){
      c[k]=Le[i];
      i++;
    }
    else{
      c[k]=Ri[j];
      j++;
    }
  }
  
}

void judge(Card *c1,Card*c2,int n){
  int i;
  int  dif=0;
  
  for(i=0;i<n; i++){
    if(c1[i].mark!=c2[i].mark || c1[i].num!=c2[i].num){
      dif=1;
      break;
    }
  }
  if(dif==0)
    printf("Stable\n");
  else
    printf("Not stable\n");
}

