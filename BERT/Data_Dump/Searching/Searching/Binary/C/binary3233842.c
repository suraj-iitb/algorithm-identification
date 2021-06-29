#include <stdio.h>

int n, S[100001], q, T[50001];
int count = 0;

void nibutan(int l, int r, int tt){
	if(r - l <= 1) {
		if(S[l] == tt || S[r] == tt) count ++;
		return;
	}
	int nibu = (r + l)/2;
	if(S[nibu] < tt) {
		nibutan(nibu, r, tt);
		return;
	}
	if(S[nibu] > tt){
		nibutan(l, nibu, tt);
		return;
	}
	if(S[nibu] == tt)count ++;
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i ++){
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for(int i = 0; i < q;i ++) scanf("%d", &T[i]);
	for(int tt = 0;tt < q;tt ++) nibutan(0, n, T[tt]);
	printf("%d\n", count);
	return 0;
}

