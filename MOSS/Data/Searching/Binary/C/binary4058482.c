#include <stdio.h>
#define N 100000
#define M 50000
#define NOT_FOUND -1

int BinarySearch( int, int [], int );

int main(){
    int n, q;
    int S[N], T[M];
    int i, cnt = 0;

    //input 
    scanf("%d", &n);
    for (i = 0; i<n; i++)
	scanf("%d", &S[i]);
    scanf("%d", &q);
    for (i = 0; i<q; i++)
	scanf("%d", &T[i]);

    //sort
    for (i = 0; i<q; i++)
	if (BinarySearch(n, S, T[i]) != NOT_FOUND)
	    cnt++;

    //dispaly 
    printf("%d\n", cnt);

    return 0;
}

int BinarySearch( int n, int S[], int key){
    int i, right = 0, left = 0, mid;

    right = n;
    while (left < right){
	mid = (right + left)/2;
	if (key == S[mid])
	    return mid;
	else if (key < S[mid])
	    right = mid;
	else if (key > S[mid])
	    left = mid + 1;
    }
    return NOT_FOUND;
}

