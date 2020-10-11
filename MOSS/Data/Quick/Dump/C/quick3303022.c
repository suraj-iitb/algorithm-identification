#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define INFTY 2000000000
typedef struct{
  char name;
  int num;
}CARD;
void quick(CARD *,int,int);
int func(CARD *,int,int);
void swap(CARD *,CARD *);
int stable(CARD *,CARD *);
void merge(CARD*,int,int);
void func2(CARD*,int,int,int);

int n;
int main(){
  int i,j,k,left,right;
  CARD a[100000],b[100000];
  char str[2];


 
 
  
  scanf("%d",&n);

  left=0;
  right=n;
  
  for(i=0;i<n*2;i++){
    scanf("%s",str);
    if(i%2!=0){a[i/2].num=b[i/2].num=atoi(str);}
    else a[i/2].name=b[i/2].name=str[0];
  
  }
  merge(b,left,right);
  quick(a,0,n-1);

  if(stable(a,b))printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",a[i].name,a[i].num);
  }
  
  return 0;
}
void quick(CARD a[],int p,int r){
  int q;
  if(p<r){
    q=func(a,p,r);
    quick(a,p,q-1);
    quick(a,q+1,r);
  }
  return;
}
    
int func(CARD a[],int p,int r){
  int x,i,j,base;
  CARD temp;
  x=a[r].num;
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(a[j].num<=x){
      i=i+1;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  base=i+1;
  return base;
}
int stable(CARD a[],CARD b[]){
  int i;
  for(i=0;i<n;i++){
    if(a[i].num==b[i].num && a[i].name!=b[i].name) return FALSE;
  }
  return TRUE;
}
void swap(CARD *c1,CARD *c2){
  CARD temp;
   temp =*c1;
    *c1=*c2;
    *c2=temp;
}
void merge(CARD a[],int left, int right){
  int mid;
  if((left+1)<right){
    mid=(left+right)/2;
    merge(a,left,mid);
    merge(a,mid,right);
   func2(a,left,mid,right);
  }
}
void func2(CARD a[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid-left;
  n2 = right-mid;
  CARD l[n1+1],r[n2+1];
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
    
  }
  for(i=0;i<n1;i++){
    l[i]=a[left+i];
  }
  l[n1].num=r[n2].num=INFTY;
  i=j=0;
  for(k=left;k<right;k++){
   
    if(l[i].num<=r[j].num){
      a[k]=l[i];
      i++;
    
      
    }
    else{
      a[k]=r[j];
      j++;
   
    }
  }
return;
}


  

