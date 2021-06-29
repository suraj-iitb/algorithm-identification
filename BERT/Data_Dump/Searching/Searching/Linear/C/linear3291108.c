#include <stdio.h>

int main(void) {
	
int n,q , i ,j,c=0;

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
for ( j=0; j < n; j++){
  if ( s[j] == t[i]){c++;break;}

}
}
printf("%d\n",c);	
	
	return 0;
}

