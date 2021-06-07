#include <stdio.h>

int main()
{
  int i, j, ndata1, ndata2, nfound = 0, data1[10001], data2[500];

  scanf("%d",&ndata1);
  for(i = 0; i < ndata1; i++) {
    scanf("%d",&data1[i]);
  }
  scanf("%d",&ndata2);
  for(i = 0; i < ndata2; i++) {
    scanf("%d",&data2[i]);
  }

  for(i = 0; i < ndata2; i++) {
    j = 0;
    data1[ndata1] = data2[i];
    while(data1[j] != data2[i]) {
      j++;
    }
    if(j != ndata1) nfound++;
  }

  printf("%d\n",nfound);
  
  return 0;
}

