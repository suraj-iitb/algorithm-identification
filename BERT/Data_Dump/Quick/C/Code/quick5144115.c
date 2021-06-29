#include<stdio.h>
#include<string.h>

#define N 100001

void quicksort(int,int);
int partition(int,int);
//void BubbleSort(int);
void merge(int,int,int);
void mergesort(int,int);

char ac[N];
int ai[N];
char bc[N];
int bi[N];//bubble sort
int count = 0;

int main()
{
  int i,j,t,n,flag = 1;
  int tmpi;
  char tmpc;
  

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf(" %c",&ac[i]);
      scanf(" %d",&ai[i]);
      bc[i] = ac[i];
      bi[i] = ai[i];
    }

  //bubble sort
  /* for(i = 0; i < n; i++)
    {
      for(j = n-1; j > i; j--)
	{
	  if(bi[j] < bi[j-1])
	    {
	      tmpi = bi[j];
	      bi[j] = bi[j-1];
	      bi[j-1] = tmpi;

	      tmpc = bc[j];
	      bc[j] = bc[j-1];
	      bc[j-1] = tmpc;
	      /*strcpy(tmp,b[j]);
	      strcpy(b[j],b[j-1]);
	      strcpy(b[j-1],tmp);
	    }
	}
	}*/
  //end
  //BubbleSort(n);
  mergesort(0,n);
  
  quicksort(0,n-1);

  for(i = 0; i < n; i++)
    {
      if(ai[i] == bi[i] && ac[i] == bc[i])flag = 1;
      else
	{
	  flag = 0;
	  break;
	}
    }
  if(flag == 1)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i = 0; i < n; i++)
    {
      printf("%c %d\n",ac[i],ai[i]);
    }
  

  return 0;
}

void quicksort(int p,int r)
{
  int q;
  
  if(p < r)
    {
      q = partition(p,r);
      quicksort(p,q-1);
      quicksort(q+1,r);
    }
}

int partition(int p,int r)
{
  int i,j;
  int cmp;
  char tmpc;
  int tmpi;
  
  cmp = ai[r];
  i = p - 1;
  for(j = p; j < r; j++)
    {
      if(ai[j] <= cmp)
	{
	  i++;
	  tmpi = ai[i];
	  ai[i] = ai[j];
	  ai[j] = tmpi;

	  tmpc = ac[i];
	  ac[i] = ac[j];
	  ac[j] = tmpc;
	  
	  /*  strcpy(tmp,a[i]);
	  strcpy(a[i],a[j]);
	  strcpy(a[j],tmp);*/
	}
    }

  tmpi = ai[i+1];
  ai[i+1] = ai[r];
  ai[r] = tmpi;

  tmpc = ac[i+1];
  ac[i+1] = ac[r];
  ac[r] = tmpc;
  
  /*      strcpy(tmp,a[i+1]);
      strcpy(a[i+1],a[r]);
      strcpy(a[r],tmp);*/

  return i+1;
}
  
/*void BubbleSort(int n)
{
  int i,j;
  int tmpi;
  char tmpc;

   for(i = 0; i < n; i++)                                                                             
    {                                                                                                
      for(j = n-1; j > i; j--)                                                                       
        {                                                                                            
          if(bi[j] < bi[j-1])                                                                        
            {                                                                                        
              tmpi = bi[j];                                                                          
              bi[j] = bi[j-1];                                                                       
              bi[j-1] = tmpi;                                                                        
                                                                                                     
              tmpc = bc[j];                                                                          
              bc[j] = bc[j-1];                                                                       
              bc[j-1] = tmpc;
	    }
	}
    }
    }*/

void merge(int left, int mid, int right)
{
  int i,  j,k;
  int n1 = mid - left;
  int n2 = right - mid;

 int Li[n1+1],Ri[n2+1];
 char Lc[n1+1],Rc[n2+1];
 
 for(i = 0; i < n1; i++)
   {
     Li[i] = bi[left + i];
     Lc[i] = bc[left + i];
   }
 
  for(i = 0; i < n2; i++)
    {
      Ri[i] = bi[mid + i];
      Rc[i] = bc[mid + i];
    }
   Li[n1] = 2000000000;//INFINITY;
  Ri[n2] = 2000000000; //INFINITY;

  i = 0;
  j = 0;
  
  for(k = left; k < right; k++)
    {
      if(Li[i] <= Ri[j])
	{
	  bi[k] = Li[i];
	  bc[k] = Lc[i];
	  i++;
	  count++;
	}
      else
	{
	  bi[k] = Ri[j];
	  bc[k] = Rc[j];
	  j++;
	  count++;
	}
    }

}
      

void mergesort (int left,int right)
{
  int mid;
  if(left + 1 < right)
    {
      mid = (left + right)/2;
      mergesort(left,mid);
      mergesort(mid,right);
      merge(left,mid,right);
    }
}

	

