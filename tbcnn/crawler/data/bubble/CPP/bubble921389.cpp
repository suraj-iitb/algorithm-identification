#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	int array[N];
	for(int i = 0; i <N; i++) cin >> array[i];
	int cnt = 0;
	for(int i = 0; i <= N-1; i++){
		for(int j = N-1;  j >= i+1; j--){
			if(array[j] < array[j-1]) {
				swap(array[j], array[j-1]);
				cnt++;
			}
		}
	}

	for(int i = 0; i < N-1; i++){
		printf("%d ", array[i]);
	}
	printf("%d\n", array[N-1]);
	printf("%d\n", cnt);

}
