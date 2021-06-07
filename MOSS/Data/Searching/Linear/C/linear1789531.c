#include <stdio.h>
#include <string.h>
#define n 10000
#define q 500

int linearsearch(int );

int s[n],t[q],num1,num2;

int main(){
  int i;
  int num=0,judge;

  scanf("%d",&num1);//数列の入力
  for(i = 0 ; i < num1 ; i++)
    {
      scanf("%d",&s[i]);
    }


  scanf("%d",&num2);
  for(i = 0 ; i < num2 ; i++)
    {
      scanf("%d",&t[i]);
    }

  /*
    for(i = 0 ; i < num1 ; i++)//test print
    {
    printf("%d",s[i]);
    }

    for(i = 0 ; i < num2 ; i++)//test print
    {
    printf("%d",t[i]);
    }

  */



  for(i = 0 ; i < num2 ; i++)//search
    {
      judge = linearsearch(t[i]);

      if(judge == 1){
	num++;

	  }
    }

  printf("%d\n",num);



  return 0;
}

int linearsearch( int key)
{
  int i;
  for(i = 0 ; i < num1 ; i++)
    {
      if(key == s[i])return 1;
    }
  return 0;
}
