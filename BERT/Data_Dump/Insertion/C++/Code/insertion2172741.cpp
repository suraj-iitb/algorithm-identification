#include <cstdio>
#include <iostream>

using namespace std;

int n;
int number[100];
int v,j;


int main(){
	cin >> n;
	for(int x=0;x<n;x++){
		cin >> number[x];
	}

	for(int i=0;i<n-1;i++){
		printf("%d ",number[i]);
	}
	printf("%d\n",number[n-1]);

	for(int i=1;i<n;i++){
		v=number[i];
		j=i-1;
		while((j >=0) && (number[j] > v)){
			number[j+1] = number[j];
			j--;
		}
		number[j+1] = v;

		for(int y=0;y<n-1;y++){
			printf("%d ",number[y]);
		}
		printf("%d\n",number[n-1]);

	}
}
