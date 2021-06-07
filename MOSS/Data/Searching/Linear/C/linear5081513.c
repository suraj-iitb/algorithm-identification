#include <stdio.h>

int search(int);

int n, na[10000], q, qa[499];

int main() {
	int cnt = 0;
	int i;

	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d", &na[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &qa[i]);
	}
	

	for (i = 0; i < n; i++) {
		if((search(na[i]))==1)cnt++;
	}

	printf("%d\n",cnt);

	return 0;

}

int search(int x){
	int i;
	for (i = 0; i < q; i++) {
		if (x == qa[i]) {
		    qa[i] = -1;
			return 1;
		}
	}
	return 0;
}
