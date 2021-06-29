#include <cstdio>
#define DEBUG(d,n) {for (int i = 0; i < n; i++) {\
                        if (i != n-1)   printf("%d ", d[i]);\
                        else            printf("%d", d[i]);\
                    }   printf("\n");}
#define SWAP(d,a,b) {	int t = d[a];\
						d[a] = d[b];\
						d[b] = t;}
const int MAX = 100;

void selectSort(int d[], int len) {
	static int lps = 0;
	// firstly, we sort i-th before
	for (int i = 0; i < len; i++) {
		//DEBUG(d, len);
		
		int pos = 0, min = 1000000000;	// pos indicate selecting minimun value fron i-th to end
		for (int j = i; j < len; j++) {
			if (min > d[j])	{
				min = d[j];
				pos = j;
			}
		}
		// Swap
		SWAP(d,i,pos);
		if (i != pos)	// wtf????? ?£( ?°????°|||)
			lps++;
	}

	DEBUG(d, len);
	printf("%d\n", lps);
}

int main() {
    int n, d[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
     
    selectSort(d, n);

    return 0;
}
