#include<stdio.h>

main()
{
  int count,i,line1[100000],line2[50000],num1,num2;
  int left,right,mid;
  scanf("%d",&num1);

  for(i=0;i<num1;i++)
    {
      scanf("%d",&line1[i]);
    }

  scanf("%d",&num2);

  for(i=0;i<num2;i++)
    {
      scanf("%d",&line2[i]);
    }
  
  count = 0; 
  for(i=0;i<num2;i++)
    {
      
      left = 0;
      right = num1;

      while(left<right)
	{

	  mid = (left + right)/2;
	  if(line2[i] == line1[mid]){
	    count++;
	    
	    break;
	  }
	  else if(line2[i]>line1[mid])left = mid + 1;
	  else if(line2[i]<line1[mid])right = mid;
	  
	}
    }
  
  printf("%d\n",count);
  return 0;
}
