#include<stdio.h>
#include<time.h>
#include<math.h>
int aum[101];
int bum[101];

typedef struct
{
  int dgum[101];
}gum;

void bfsdc(gum gu[], int num)
{
  for(int ium = 1; ium <= num; ium++)
    {
      aum[ium] = -1;
    }
  int headum = 0, endum = 0;
  bum[endum++] = 1;
  aum[1] = 0;

  while(headum != endum)
    {
      int tum = bum[headum++];
      for(int ium = 1; ium <= num; ium++)
	{
	  if(aum[ium] == -1 && gu[tum].dgum[ium] == 1)
	    {
	      aum[ium] = aum[tum]+1;
	      bum[endum++] = ium;
	    }
	}
    }

}

int main()
{
  int n1um, cum, bum, dum;
  scanf("%d", &n1um);
  gum gu[n1um+1];
  for(int ium = 0 ; ium < n1um; ium++)
    {
      scanf("%d%d", &cum, &bum);
      for(int jum = 0; jum < bum; jum++)
	{
	  scanf("%d", &dum);
	  gu[cum].dgum[dum] = 1;
	}
    }
  bfsdc(gu, n1um);

  for(int ium = 1 ;ium <= n1um; ium++)
    {
      printf("%d %d\n", ium, aum[ium]);
    }

}

