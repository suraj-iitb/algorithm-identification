#include<stdio.h>
#include<stdlib.h>

int S[10000],A[500];
int 	linearSearch(int,int);

int main() {
	int n,i,q,k=0,aa,p=0;
	int T[500];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		scanf("%d",&S[i]);
		}
		scanf("%d",&q);
		
		for(i=0;i<q;i++) {
			scanf("%d",&T[i]);
			}
			
			for(i=0;i<q;i++) {
			aa=linearSearch(T[i],n);
			if(aa==1) p++;
			n++;
		}	
		printf("%d\n",p);
		return 0;
}
		
		
	int 	linearSearch(int key, int n) {
int i = 0;
   S[n] = key;
  while (S[i]!=key) { 	
     i++; 
   }
    if (i==n) {
     return 0;
    }
        return 1;
        }
