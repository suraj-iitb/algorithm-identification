
#include<stdio.h>


#define MAX 100000

int kensaku(const int S[], const int T[], const int Q, const int N)
{

	int i = 0, j = 0, k = 0, z = 0;
	int  V[MAX];
	int mid, top, bot, error = 0;
	bot = 0;
	top = N;
	mid = ((bot + top) / 2);
	
	

	for (i = 0; i < Q; i++) {
		
		for (k = 0; k < z; k++) {
			if (T[i] == V[k]) { error++;  break; }
		}

		if (error == 1) { error = 0; continue; }


			if (T[i] < S[mid]) {
				for (j = mid; j >= 0; j--) {
					if (T[i] == S[j]) {
						V[z] = T[i];
						z++;
						break;
					}
				}
			}

			else if (T[i] > S[mid]) {
				for (j = mid; j <= top; j++) {
					if (T[i] == S[j]) {
						V[z] = T[i];
						z++;
						break;
					}
				}
			}

			else if(T[i] == S[mid]){
				V[z] = T[i];
				z++;
			}
		}
				

	return z;
}



int main(void)
{
	int i;
	int n, q, count = 0;
	int s[MAX], t[MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++) {
		scanf("%d", &t[i]);
	}

	count = kensaku(s, t, q, n);
	printf("%d\n", count);

	return 0;
}
