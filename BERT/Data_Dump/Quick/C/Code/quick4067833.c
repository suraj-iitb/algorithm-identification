#include<stdio.h>

#define MAX 100000
#define KAZU 1000000000

struct Card{
  char suit;
  int value;
};


struct Card LEFT[MAX/2+2], RIGHT[MAX/2+2];

void merge(struct Card *, int , int , int);
void mergeSort(struct Card *, int, int);
int partition(struct Card *, int, int);
void quickSort(struct Card *, int ,int);

int n;

int main(){
  int n, i, z,stable=1;
  struct Card a[MAX],b[MAX];
  char S[10];
  scanf("%d",&n);
  
  for (i=0;i<n; i++ ) {
    scanf("%s %d", S, &z);
    a[i].suit=S[0];
    b[i].suit=S[0];
    a[i].value=z;
    b[i].value=z;
    
  }
  
  mergeSort(a,0, n);
  quickSort(b,0, n-1);
  
  for ( i = 0; i < n; i++ ){
    if ( a[i].suit != b[i].suit ){
      stable = 0;
    }
  }
  
  if ( stable == 1 ) printf("Stable\n");
  if ( stable == 0 )printf("Not stable\n");
  for ( i = 0; i < n; i++ ) {
    printf("%c %d\n", b[i].suit, b[i].value);
  }

return 0;
}

void merge(struct Card a[],int left2,int mid,int right2){
  int i,j,k,n1,n2;
  
  n1=mid-left2;
  n2=right2-mid;
  for(i=0;i<n1;i++){
    LEFT[i]=a[left2+i];
  }
  for(i=0;i<n2;i++){
    RIGHT[i]=a[mid+i];
  }
  LEFT[n1].value=KAZU;
  RIGHT[n2].value=KAZU;
  i=0;
  j=0;
  for(k=left2;k<right2;k++){
    if(LEFT[i].value<=RIGHT[j].value){
      a[k]=LEFT[i];
      i=i+1;
	}
    else{
      a[k]=RIGHT[j];
      j=j+1;
    }
  }
}

void mergeSort(struct Card a[],int left2,int right2){
  int mid;
  if(left2+1<right2){
    mid=(left2+right2)/2;
    mergeSort(a,left2,mid);
    mergeSort(a,mid,right2);
    merge(a,left2,mid,right2);
  }
  
}
  
int partition(struct Card a[],int p,int r){
  
  int i,j;
  struct Card c, x;
  x=a[r];
    i=p-1;
    for(j=p;j<r;j++){
      if(a[j].value<=x.value){
	i=i+1;
	c=a[i];
	a[i]=a[j];
	a[j]=c;
      }
    }
    c=a[i+1];
    a[i+1]=a[r];
    a[r]=c;
    
    return i+1;
  }

 void quickSort(struct Card a[], int p, int r){
  int q;
  if (p<r){
    q=partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
 }

