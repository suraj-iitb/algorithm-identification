#include<cstdio>
int i,j,k,o,n,c,s[1<<19];
void g(int l,int m,int r){
  int L[m-l+1],R[r-m+1];
  for(i=0;i<m-l;L[m-l]=R[r-m]=1e9)L[i]=s[l+i++];
  for(i=0;i<r-m;k=l)R[i]=s[m+i++];
  for(i=o=0;k<r;++c)s[k++]=L[i]>R[o]?R[o++]:L[i++];
}
void e(int l,int r){
  int m=(l+r)/2;
  if(l+1<r)e(l,m),e(m,r),g(l,m,r);
}
main(){
  for(scanf("%d",&n);i<n;)scanf("%d",s+i++);
  for(e(0,n);j<n;)printf(j-n?"%d ":"%d\n",s[j++]);
  printf("%d\n",c);
}
