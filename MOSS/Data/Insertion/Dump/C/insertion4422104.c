#include<stdio.h>
void insertion(int a[], int n)
{
  int i,j,k,x=0;
  for(i=1; i<n; i++){
    int tmp=a[i];
    for(j=i; j>0&&a[j-1]>tmp; j--)
      a[j]=a[j-1];//基準値より大きかったら前にする
    a[j]=tmp;	  //その他は基準値に戻す
    for(k=0; k<n; k++){
      if(k<n-1) printf("%d ",a[k]);
      else printf("%d",a[k]);
    }
    putchar('\n');    
  }
  
}
int main()
{
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);
  for(i=0; i<n; i++){
    if(i<n-1) printf("%d ",a[i]);
    else printf("%d",a[i]);
  }
  putchar('\n');
  insertion(a,n);
  return 0;
}
