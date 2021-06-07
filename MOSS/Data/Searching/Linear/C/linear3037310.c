#include<stdio.h>
 
int N[10000];
int n;
 
int search(int key) {
	int i=0;
	
	N[n] = key;
	while(N[i] != key) i++;
		if(i == n) return 0;
		else return 1;
	}
	
int main(void) {
	int i,p=0,q;
	int m[500];
		
	scanf("%d",&n);
	for(i=0;i < n; i++) {
		scanf("%d",&N[i]);
	}
		
	scanf("%d", &q);
	for(i=0;i < q; i++) {
		scanf("%d",&m[i]);
	}
		
	 for(i = 0; i < q; i++){
   		 if(search(m[i])) p++;
  	 }
 
  printf("%d\n", p);
 
  return 0;
}





