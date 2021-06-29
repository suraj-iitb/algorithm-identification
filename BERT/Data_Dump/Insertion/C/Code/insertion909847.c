#define N 100
main()
{ 
  int a,b[N],i,key,j,l;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<a;i++)
    {
      key=b[i];
      j=i-1;
      while(j>=0&&b[j]>key){
	b[j+1]=b[j];
	j--;
      }
      b[j+1]=key;
      for(l=0;l<a-1;l++)
	{
	  printf("%d ",b[l]);
	}
      printf("%d",b[l]);
      printf("\n");
    }
  return 0;
}
