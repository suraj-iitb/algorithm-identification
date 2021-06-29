#include<stdio.h>
#define MAX 100005
#define INF 1000000000

typedef struct{
  char c;
  int  n;
}card;

void merge(card *a,int left,int mid,int right){
  int n1,n2;
  card l[MAX/2],r[MAX/2];
  int i,j,k;

  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) l[i]=a[left+i];
  for(i=0;i<n2;i++) r[i]=a[mid+i];
  l[n1].n=INF;
  r[n2].n=INF;
  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    if(l[i].n<=r[j].n){
      a[k]=l[i];
      i++;
    }
    else{
      a[k]=r[j];
      j++;
    }
  }
}

void mergeSort(card *a,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

int partition(card *a,int p,int r){
  int x;
  int i,j;
  card temp;
  
  x=a[r].n;
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].n<=x){
      i++;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
 temp=a[i+1];
 a[i+1]=a[r];
 a[r]=temp;
 
  return i+1;
}

void quickSort(card *a,int p,int r){
  int q;
  
  if(p<r){
    q=partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
}

int main(){
  card a[100005],b[100005];
  int x,y,n,left,right,flag=0;
  int i;
  
  scanf("%d",&n);
  
  left=0;
  right=n;
  for(i=0;i<n;i++){
    scanf("%s %d",&a[i].c,&a[i].n);
    b[i]=a[i];
  }
  quickSort(a,0,n-1);
  mergeSort(b,left,right);
  for(i=0;i<n;i++){
    if(a[i].c!=b[i].c){
      flag=1;
      printf("Not stable\n");
      break;
    }
  }
  if(flag==0) printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",a[i].c,a[i].n);
  }
  for(x=0;x<n;x++){
    y++;
  }
  return 0;
}
