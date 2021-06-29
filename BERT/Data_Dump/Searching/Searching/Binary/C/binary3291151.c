#include <stdio.h>

int main() {
	
  int n,q , i ,j,c=0 , lef,rig,mid ,k;

  scanf("%d",&n);
	
  int s[n];

  for ( i=0; i < n; i++){
    scanf("%d",&s[i]);

  }
  scanf("%d",&q);
	
  int t[q];

  for ( i=0; i < q; i++){
    scanf("%d",&t[i]);

  }

  for ( i=0; i < q; i++){
    k= t[i];
    lef = 0;
    rig = n;
    while ( lef < rig){
      mid = (lef + rig)/ 2;

      if ( s[mid] == k){c++;break;}
      else if ( s[mid] < k){ lef = mid +1;continue;}
      else if ( s[mid] > k){ rig = mid;continue;}
    }
  }
  printf("%d\n",c);	
	
  return 0;
}

