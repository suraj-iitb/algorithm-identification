#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char symbol;
  int num;
} data;

int partition(data *,int,int);
void quicksort(data *,int,int);
void merge(data *,int,int,int);
void mergeSort(data *,int,int);

int main()
{
  int n,i,j;
  data *a,*b,sw;
  scanf("%d",&n);
  a=(data *)malloc(sizeof(data)*n);
  b=(data *)malloc(sizeof(data)*n);
  for( i=0 ; i<n ; i++)
  {  
    scanf(" %c %d",&a[i].symbol,&a[i].num);
    b[i]=a[i];
  }
  mergeSort(b,0,n);
  quicksort(a,0,n-1);
  j=0;
  for( i=0 ; i<n ; i++)
  {
    if( b[i].symbol!=a[i].symbol ) j++;
  }
  if(j==0)printf("Stable\n");
  else printf("Not stable\n");
  for( i=0 ; i<n ; i++)
  {
    printf("%c %d\n",a[i].symbol,a[i].num);
  }  
  return 0;
}


void quicksort(data *a,int p,int r)
{
  int q;
  if (p < r)
  {  
    q = partition(a, p, r);
    quicksort(a, p, q-1);
    quicksort(a, q+1, r);
  }     
}

int partition(data *a,int p,int r)
{
  int i,x,j,s;
  char c;
  
  x=a[r].num;
  i=p-1;
  for( j=p ; j<r ; j++ )
  {
    if( a[j].num<=x )
    {  
      i++;
      s=a[i].num;
      a[i].num=a[j].num;
      a[j].num=s;
      c=a[i].symbol;
      a[i].symbol=a[j].symbol;
      a[j].symbol=c;
    }
  }
  s=a[r].num;
  a[r].num=a[i+1].num;  
  a[i+1].num=s;
  c=a[r].symbol;
  a[r].symbol=a[i+1].symbol;
  a[i+1].symbol=c;
  return i+1;
}




void merge(data *b,int left,int mid,int right)
{
  int i,j,a;
  int n1,n2;
  data *l,*r;
  n1=mid-left;
  n2=right-mid;
  l=(data *)malloc(sizeof(data)*(n1)+2);
  r=(data *)malloc(sizeof(data)*(n2)+2);
  for( i=0 ; i<n1 ; i++ )
    l[i]=b[left+i];
  for( i=0 ; i<n2 ; i++ )
    r[i]=b[mid+i];
  l[n1].num=121575267;
  r[n2].num=121575267;
  i=0;
  j=0;
  for( a=left ; a<right ; a++ )
  {
    if( l[i].num<=r[j].num)
    {
      b[a]=l[i];
      i++;
    }  
    else 
    {
      b[a]=r[j];
      j++;
    }    
  }
  free(l);
  free(r);
}

void mergeSort(data *a,int left,int right)
{
  int mid,i;
  if( (left+1)<right )
  { 
    mid = (left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }  
}

