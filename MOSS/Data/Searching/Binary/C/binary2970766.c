#include<stdio.h>

int main()
{
  int n,q,S[1000000],T[50000],i,j,number_of_coresspond = 0,left,mid,right;

  scanf("%d",&n);
  for(i = 0 ; i <n ; i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0 ; i <q ; i++)scanf("%d",&T[i]);

  left = 0;
  right =n;
  mid = (left+right)/2;
 
  for(i = 0 ; i < q ; i++)
    {

      left = 0;
      right =n;
      mid = (left+right)/2;
      //printf("i = %d\n",i);
      
      while(left<right)
	{
	  //printf("left = %d  mid = %d  right = %d\n",left,mid,right);
	  if(S[mid] == T[i])
	    {
	      number_of_coresspond++;
	      break;
	    }
	  else if(S[mid] > T[i])
	    {
	      right = mid;
	      mid = (left + right)/2;
	    }
	  else if(S[mid] <T[i])
	    {
	      left = mid+1;
	      mid = (left + right)/2;
	    }
	  //printf("left = %d  mid = %d  right = %d\n",left,mid,right);

	}
      //printf("\n");
    }

  printf("%d\n",number_of_coresspond);
  
    

    

}

