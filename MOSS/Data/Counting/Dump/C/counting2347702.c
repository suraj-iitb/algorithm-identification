#include <stdio.h>
#include <stdlib.h>

int main(){
  short *a,*b;
  int i,j,n;
  int c[10001];
  scanf("%d",&n);

  a=malloc(sizeof(short)*n+1);
  b=malloc(sizeof(short)*n+1);
  for(i=0;i<=10000;i++){
    c[i]=0;
  }
  for(i=0;i<n;i++){
    scanf("%hu",&a[i+1]);
    c[a[i+1]]++;
  }

for(i=1;i<=10000;i++){
  c[i]=c[i]+c[i-1];

}

for(j=1;j<=n;j++){
  b[c[a[j]]]=a[j];
  c[a[j]]--;
}


for(i=1;i<=n;i++){
  if(i==n){
    printf("%d",b[i]);
  }
  else {
    printf("%d ",b[i]);
  }


}
printf("\n");

return 0;

}
