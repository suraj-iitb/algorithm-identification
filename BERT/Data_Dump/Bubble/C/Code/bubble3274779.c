int main(){
  int n,i,j,a[100],swap=0,x;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
	swap++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",swap);
  return 0;
}

