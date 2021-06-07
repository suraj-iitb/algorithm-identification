#include<stdio.h>

main()
{
  int count=0,i,k,line1[10000],line2[500],num1,num2;

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
  
  for(i=0;i<num2;i++)
    {
      k = 0;
      line1[num1] = line2[i];
  while(line1[k] != line2[i])
    {
      k++;
    } 
  if(k != num1)count++;
    }
  printf("%d\n",count);

return 0;

}
