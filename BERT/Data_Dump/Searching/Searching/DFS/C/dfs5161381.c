#include <stdio.h>
  
int haku(int i, int pet, int o[101][101], int *c, int *l)
{
  int *p;
  
  c[i] = ++pet;
  for (p = o[i]; *p != 0; p++)
    if (!c[*p])
      pet = haku(*p, pet, o, c, l);
  l[i] = ++pet;

  return pet;
}
  
int main(void)
{
  int jku,i,j,w,k;
  int uki=0;
  int z[101]={};
  int l[101]={};
  int o[101][101]={};
  
  scanf("%d", &jku);
  for (i=0;i<jku;i++){
      scanf("%d %d",&w,&k);
      for (j=0;j<k;j++)
	  scanf("%d",&o[w][j]);
    }
  
  for (i=1;i<=jku;i++){
    if (z[i]==0)
      uki=haku(i,uki,o,z,l);
  }
  
  for (i=1;i<=jku;i++){
    printf("%d %d %d\n",i,z[i],l[i]);
  }
  
  return 0;
}

