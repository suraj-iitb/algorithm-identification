#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,q;
  int *S,*T,B[1000000];
  int i,u;
  int l,m,r;
  int count=0,flag,key;
  
  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++) scanf("%d",&T[i]);


  for(i=0;i<q;i++){
    key=T[i];
    l=0;
    r=n+2;
    m=(r+l)/2;
    flag=0;

    for(u=0;u<count;u++){
      if(B[u]==key){
	flag=1;
	break;
      }
    }
    
    while(r>l){
      if(flag==1) break;
      if(key==S[m]){
	B[count++]=key;
	break;
      }
      else if(key<S[m]){
	r=m;
	m=(r+l)/2;
      }else if(key>S[m]){
	l=m+1;
	m=(r+l)/2;
      }
    }

  }

  printf("%d\n",count);

  free(S);
  free(T);
  return 0;
}

