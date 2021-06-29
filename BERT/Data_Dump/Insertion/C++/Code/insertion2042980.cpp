#include <cstdio>
#define DEBUG(d,n) {for (int i = 0; i < n; i++) {\
						if (i != n-1)	printf("%d ", d[i]);\
						else 			printf("%d", d[i]);\
					}	printf("\n");}
static int MAX = 100;

int main() {
	int n, d[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	
	// select a value form 1 to n-1
	for (int i = 1; i < n; i++) {
		DEBUG(d,n);	// display every step
		int key = d[i];	// wait for insert
		int j = i - 1;
		// compare form i to 0 <- find a position to insert
		while (j >= 0 && d[j] > key) {
			d[j+1] = d[j];	// copy i-th to i+1-th
			j--;
		}
		d[j+1] = key;	// insert
	}
	
	DEBUG(d,n);	// display final step <- fixed PE
	return 0;
}
