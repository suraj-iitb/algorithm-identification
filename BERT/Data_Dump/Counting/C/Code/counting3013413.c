#include<stdio.h>
#include<stdlib.h>

void Countingsort(int *,int *,int);

int n;

int main(){
  int i,k=0;
  int *pa,*pb;

  scanf("%d",&n);

  pa=(int*)malloc((n+1)*sizeof(int));
  pb=(int*)malloc((n+1)*sizeof(int));

  for(i=1;i<=n;i++){
    scanf("%d",&pa[i]);
    if(k<pa[i]){
      k=pa[i];
    }
  }

    Countingsort(pa,pb,k);

    return 0;
  }

void Countingsort(int *a,int *b,int k){
  int i,j,c[10001];

  for(i=0;i<=k;i++){
    c[i]=0;
  }

    for(j=1;j<=n;j++){
      c[a[j]]++;
    }

    for(i=1;i<=k;i++){
      c[i]=c[i]+c[i-1];
    }

    for(j=n;j>=1;j--){
      b[c[a[j]]]=a[j];
      c[a[j]]--;
    }

    for(i=1;i<=n;i++){
      if(i==n){
	printf("%d\n",b[i]);
      }
	else{
	  printf("%d ",b[i]);
	}
      }

}

