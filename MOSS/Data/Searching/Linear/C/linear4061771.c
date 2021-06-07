#include <stdio.h>
#define N 10000
#define Q 500

int main(){
	int n,q,i,j,k,cnt=0,f=0,t=0;
	int S[N],T[Q],A[N];

	scanf("%d",&n);

	for(i=0; i<n; i++){
		scanf("%d",&S[i]);
	}

	scanf("%d",&q);

	for(i=0; i<q; i++){
		scanf("%d",&T[i]);
	}

	for(i=0; i<q; i++){
		A[i] = -1;
	}

	for(j=0; j<q; j++){
		for(i=0; i<n; i++){
			f=0;
			for(k=0; k<t; k++){
				if(A[k]==S[i]) f++;
			}
			if(S[i]==T[j] && f==0){
      	cnt++;
				A[t++] = S[i];
    	}
		}
	}

	printf("%d\n",cnt);

	return 0;
}

