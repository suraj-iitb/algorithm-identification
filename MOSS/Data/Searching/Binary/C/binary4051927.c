#include <stdio.h>

int main()
{
  int i, ndata1, ndata2, nfound = 0, data1[100000], data2[50000];
  int mid, left, right;
  
  scanf("%d",&ndata1);
  for(i = 0; i < ndata1; i++) {
    scanf("%d",&data1[i]);
  }
  scanf("%d",&ndata2);
  for(i = 0; i < ndata2; i++) {
    scanf("%d",&data2[i]);
  }

  for(i = 0; i < ndata2; i++) {
    left = 0;
    right = ndata1;

    while(left < right) {
      mid = (left + right)/2;
      if(data1[mid] == data2[i]) {
	nfound++;
	break;
      }
      else if(data2[i] < data1[mid]) right = mid;
      else left = mid + 1;
    }
  }

  printf("%d\n",nfound);
  
  return 0;
}

