
#include "stdio.h"


int main()
{
	int n,a[10000],m,t[10000],sum=0,i,k;



	scanf("%d", &n);

	for (i = 0;i < n;i++) {
		scanf(" %d", &a[i]);
	}

	scanf("%d", &m);

	for (i = 0;i < m;i++) {
		scanf(" %d", &t[i]);


		for (k = 0;k < n;k++) {
			if (a[k] == t[i]) {
				sum++;

				break;

			}
				
		}
	}


	printf("%d\n", sum);



    return 0;
}
