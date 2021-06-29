#include <stdio.h>

void Quicksort(char *,int *,int,int);
void Bublesort(char *,int *,int);
int Check(char *,char *,int *,int *,int);
int Partition(char *,int *,int,int);
void swap(char *,int *,int,int);
void margesort(char *,int *,int,int);
void marge(char *,int *,int,int,int);


int num[100000],num2[100000];
char mark[100000],mark2[100000];
int numL[50001],numR[500001];
char markL[50001],markR[50001];



int main(){
  int i,j,n;
  char kaigyo;  //改行打消用

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%c",&kaigyo); //改行のscanfをなかったことにするための犠牲
    scanf("%c%d",&mark[i],&num[i]);
  }

    for(i=0;i<n;i++){
    mark2[i]=mark[i];
    num2[i]=num[i];
  }
  
   Quicksort(mark,num,0,n-1);
  
   margesort(mark2,num2,0,n);
  
   if(Check(mark,mark2,num,num2,n) == 1) printf("Stable\n");
  else printf("Not stable\n");
   
  for(i=0;i<n;i++) printf("%c %d\n",mark[i],num[i]);

  return 0;
}

void Quicksort(char *m,int *n,int p,int r){
  int q;
  if(p < r){
    q = Partition(m,n,p,r);
    Quicksort(m,n,p,q-1);
    Quicksort(m,n,q+1,r);
  }

}

int Partition(char *m,int *n,int p,int r){
  int i,j,x,box;
  
  x=n[r];
  j=p-1;
  
  for(i=p;i<r;i++){
    if( n[i] <= x){
      j++;
      swap(m,n,j,i);
    }
  }
  swap(m,n,j+1,r);
  
  return j+1;
}

void swap(char *m,int *n,int p,int q){
  int box;
  char box2;
  
  box2 = m[p];
  m[p]=m[q];
  m[q]=box2;
  
  box = n[p];
  n[p]=n[q];
  n[q]=box;
}


int Check(char *m,char *m2,int *n,int *n2,int a){
  int flg=1,i;

  for(i=0;i<a;i++){
    if(m[i] != m2[i] || n[i] != n2[i]){
      flg = 0;
      break;
    }
  }
  return flg;
}


void margesort(char *m2,int *n2,int left,int right){
  int mid;
  if(left+1 < right){ 
    mid = (left + right)/2;
    margesort(m2,n2,left,mid);
    margesort(m2,n2,mid,right);
    marge(m2,n2,left,mid,right);
  }
}

void marge(char *m2,int *n2,int left,int mid,int right){
  int nl,nr;
  int i,j=0,k;

  nl = mid - left;
  nr = right - mid;

  for(i=0;i<nl;i++){
    markL[i] = m2[left+i];
    numL[i] = n2[left+i];
  }
  numL[nl]=1000000001;
  for(i=0;i<nr;i++){
    markR[i] = m2[mid+i];
    numR[i] = n2[mid+i];
  }
  numR[nr]=1000000001;

  i=0;
  for(k=left;k<right;k++){
  if(numL[i] <= numR[j]){  
    m2[k] = markL[i];
    n2[k] = numL[i];
    i++;
  }
  else{
    m2[k] = markR[j];
    n2[k] = numR[j];
    j++;
  }
  }
}
