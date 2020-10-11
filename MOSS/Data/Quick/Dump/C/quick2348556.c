#include<stdio.h>
#define M 100000
#define INFTY 2000000000

struct Cards {
  char mark;
  int num;
};

void merge(struct Cards*,int ,int , int );
void mergeSort(struct Cards*,int , int );
int partition(struct Cards*,int ,int );
void quickSort(struct Cards*,int ,int );

struct Cards Left[M/2+2],Right[M/2+2];
int n;

int main(){
  int i,v;
  struct Cards X[M],Y[M];
  char C[10];
  int stable = 1;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%s %d",C,&v);
      X[i].mark = Y[i].mark = C[0];
      X[i].num = Y[i].num = v;
    }

  mergeSort(X,0,n);
  quickSort(Y,0,n-1);

  for(i=0;i<n;i++)
    {
      if(X[i].mark!=Y[i].mark)stable = 0;
    }

  if(stable==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n", Y[i].mark, Y[i].num);
  }
  return 0;
}
 

void merge(struct Cards S[],int l,int m , int r)
{
  int i,j,n1,n2,k;
   n1 = m - l;
   n2 = r - m;
   for(i=0;i < n1;i++)
     {
       Left[i]=S[l+i];
     }
 
   for(i=0;i < n2;i++)
     {
       Right[i]=S[m+i];
     }
   Left[n1].num=INFTY;
   Right[n2].num=INFTY;
   i=0;
   j=0;
   for(k=l;k < r;k++)
     {

       if(Left[i].num<=Right[j].num)
	 {
	   S[k] = Left[i];
	   i++;
	 }
       else 
	 {
	 S[k] = Right[j];
	 j++;
	 }
     }
}

void mergeSort(struct Cards S[],int l, int r)
{
  int mid=0;
  if(l+1 < r)
    {
      mid = (l+r)/2;
      mergeSort(S,l,mid);
      mergeSort(S,mid,r);
      merge(S,l,mid,r);
    }
}

int partition(struct Cards S[],int p,int r)
{
  int i,j;
  struct Cards x,tmp;
  x = S[r];
  i = p-1;
  for(j=p;j<r;j++)
    {
      if(S[j].num<=x.num)
	{
	  i = i+1;
	  tmp=S[i];
	  S[i]=S[j];
	  S[j]=tmp;
	}
    }
  tmp=S[i+1];S[i+1]=S[r];S[r]=tmp;
  return i+1;
}

void quickSort(struct Cards S[],int p,int r)
{
  int m;
  if(p<r)
    {
      m = partition(S,p,r);
      quickSort(S,p,m-1);
      quickSort(S,m+1,r);
    }
}


  
