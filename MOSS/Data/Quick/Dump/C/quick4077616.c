#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char moji;
	int su;
}P;
int partition(P *,int ,int);
void quicksort(P *,int,int);
int antei(P *,P *,int);
void sort(P *,int,int);
void merge(P *,int,int,int);

int main(){
	P *a,*b;
	int n,i,c;
	scanf("%d",&n);
	b=(P *)malloc(sizeof(P)*(n+1));
	a=(P *)malloc(sizeof(P)*(n+1));
	for(i=0;i<n;i++){
		scanf(" %c%d",&a[i].moji,&a[i].su);
		b[i].su=a[i].su;
		b[i].moji=a[i].moji;
	}
	sort(b,0,n);
	quicksort(a,0,n-1);
	c=antei(a,b,n);
	if(0==c)printf("Not stable\n");
    else printf("Stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",a[i].moji,a[i].su);
	}
	free(b);
	free(a);
	return 0;
}

void quicksort(P *A,int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
int partition(P *A,int p,int r){
  int x,i,j,box;
  char m;
  x=A[r].su;
  i=p-1;
  for(j=p;j<r;j++){
    if(x>=A[j].su){
      i++;
	  box=A[i].su;
      A[i].su=A[j].su;
      A[j].su=box;
      m=A[i].moji;
      A[i].moji=A[j].moji;
      A[j].moji=m;
    }
  }
  i++;
    box=A[r].su;
    A[r].su=A[i].su;
    A[i].su=box;
	m=A[i].moji;
    A[i].moji=A[j].moji;
    A[j].moji=m;
    return i;
}

int antei(P *a,P *b,int n){
  int i;
  for (i = 0;i<n;i++){
    if(a[i].su!=b[i].su || a[i].moji!=b[i].moji)return 0;
  }
  return 1;
}
void sort(P *a,int L,int R){
  int mid;
  if(L+1<R){
    mid =(L+R)/2;
    sort(a,L,mid);
    sort(a,mid,R);
    merge(a,L,mid,R);
  }
}

void merge(P *a,int L,int mid,int R){
  int n1=mid-L,n2=R-mid,i,j,k;
  P *l,*r;
  l=(P *)malloc(sizeof(P)*(n1+1));
  r=(P *)malloc(sizeof(P)*(n2+1));
  for(i=0;i<n1;i++){
    l[i].su=a[L+i].su;
	l[i].moji=a[L+i].moji;
  }
  for(i=0;i<n2;i++){
    r[i].su=a[mid+i].su;
	r[i].moji=a[mid+i].moji;
  }
  l[n1].su=1000000001;
  r[n2].su=1000000001;
  i=0;
  j=0;
  for(k=L;k<R;k++){
    if(l[i].su>r[j].su){
      a[k].su=r[j].su;
	  a[k].moji=r[j].moji;
      j++;
    }else{
      a[k].su=l[i].su;
	  a[k].moji=l[i].moji;
      i++;
    }
  }
  free(l);
  free(r);
}

