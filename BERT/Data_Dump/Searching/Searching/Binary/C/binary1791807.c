#include<stdio.h>
#define n 1000000
#define q 50000
int s[n],t[q];
int search(int,int);


int main(){

  int i;
  int num = 0;
  int slength,tlength;

  scanf("%d",&slength);//input
  for(i = 0 ; i < slength ; i++)
    {
      scanf("%d",&s[i]);
    }


  scanf("%d",&tlength);
  for(i = 0 ; i < tlength ; i++)
    {
      scanf("%d",&t[i]);
    }

  for(i = 0 ; i < tlength ; i++)
    {
      num += search(t[i],slength);


    }
      printf("%d\n",num);

  return 0;

}

int search(int key,int length)
{
  int left = 0;
  int right = length;
  int mid;

  while(left < right)
    {
      mid = (left + right) / 2;
      if(key == s[mid])return 1;
      if(key > s[mid])left = mid +1;
      else if(key < s[mid])right = mid;
    }
  return 0;
}
