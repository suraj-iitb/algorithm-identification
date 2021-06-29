#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100007;
struct card{
	char c;
	int num;
};
struct card cards[MAXN];
struct card cards2[MAXN];
int partition(struct card a[], int l, int r){
	int tmp = a[r].num;
	int i = l-1;
	for(int j = l; j < r; j++){
		if(a[j].num<=tmp){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}
void quickSort(struct card a[], int l, int r){
	if(l<r){
		int q = partition(a, l ,r);
		quickSort(a, l , q-1);
		quickSort(a, q+1, r);
	}
	
}
bool cmp(struct card c1, struct card c2){ return c1.num < c2.num;}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> cards[i].c;
		cin >> cards[i].num;
		cards2[i].c = cards[i].c; 
		cards2[i].num = cards[i].num; 
	}
	stable_sort(cards2, cards2+n,cmp);
	quickSort(cards, 0, n-1);
	int stable = 1;
	for(int i = 0; i < n; i++){
		if(cards[i].c!=cards2[i].c){
			stable = 0;
		}
	}
	if(stable == 1){
		printf("Stable\n");
	}else{
		printf("Not stable\n");
	}
	for(int i = 0; i < n; i++){
		printf("%c %d\n", cards[i].c, cards[i].num);
	}
	return 0;
}
