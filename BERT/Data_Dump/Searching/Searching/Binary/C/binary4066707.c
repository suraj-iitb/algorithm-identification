int main()
{
  int n1,n2,*a,*b,i,n;
  
  scanf("%d",&n1);

  a = (int *)malloc(n1 * sizeof(int));

  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);

  b = (int *)malloc(n2 * sizeof(int));

  for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
  }

  n = Search(a,b,n1,n2);

  printf("%d\n",n);

  free(a);
  free(b);

  return 0;
}

int Search(int *a,int *b,int n1,int n2)
{
  int c=0,i,j,l,r,m;

  for(i=0;i<n2;i++){
    l = 0;
    r = n1;
    m = (l+r)/2;
    while(l<r){
      if(a[m]==b[i]){
	c++;
	break;
      }
      else if(a[m]<b[i]){
	l = m+1;
	m = (l+r)/2;
      }
      else if(a[m]>b[i]){
	r = m;
	m = (l+r)/2;
      }
    }
  }
  
  return c;
}

