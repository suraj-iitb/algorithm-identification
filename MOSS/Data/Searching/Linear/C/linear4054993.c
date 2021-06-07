#include <stdio.h>
#define N 10000
#define Q 500
#define NOT_FOUND -1

int LinearSearch(int, int [], int );

int main(){
    int n, q; //number of data
    int S[N], T[Q]; //universe of data
    int cnt = 0; //count of same data
    int i;
    
    //input num of data and actual data
    scanf("%d", &n);
    for (i = 0; i<n; i++)
	scanf("%d", &S[i]);
    scanf("%d", &q);
    for (i = 0; i<q; i++)
	scanf("%d", &T[i]);

    //count the same data
    for (i = 0; i<q; i++){
	if (LinearSearch(n, S, T[i]) != NOT_FOUND)
	    cnt++;
    }
    
    //display the result
    printf("%d\n", cnt);

    return 0;
}

int LinearSearch( int n,int S[], int key ){
    int i = 0;

    S[n] = key;//as a sentinel
    while (S[i] != key)
	i++;
    if (i == n)
	return NOT_FOUND;
    return i;
}

