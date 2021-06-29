#include <stdio.h>

int main(void)
{
    int s[100000];
    int t[100000];
    int i,j,k,l,n,key;
	int mid;
	int x = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&s[i]);
    scanf("%d",&l);
    for (i = 0; i < l; i++)
        scanf("%d",&t[i]);
    
    for (i = 0; i < l; i++) {
		key = t[i];
		int right = n;
		int left = 0;
	    while (left < right) {
		    mid = (left + right) / 2;
		    if (s[mid] == key){
			    x++;
			    left = left+10000;
			}
		    else if (key < s[mid])
		        right = mid;
		    else
		        left = mid +1;
        }
    }
    printf("%d\n", x);
    
    return 0;
}
