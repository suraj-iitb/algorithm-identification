#include<stdio.h>
int main(){
  int t,f,a,n,i,in[100],c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&in[i]);
  }
  for(t=n;t>0;t--){
  for(a=n-1;a>0;a--){
    if(in[a]<in[a-1]){
     f=in[a];
    in[a]=in[a-1];
    in[a-1]=f;
    c++;
	}
  }
  }
  for(i=0;i<n;i++){
    if(i<n-1)printf("%d ",in[i]);
    else printf("%d\n%d\n",in[i],c);
    }
  return 0;
}


