#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
int numbers[100005];
char cards[100005];
int numbersM[100005];
char cardsM[100005];
void merge(int *array, char *cards, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int left[n1 + 1];
	int right[n2 + 1];
	char leftcard[n1];
	char rightcard[n2];

	for(int i = 0; i < n1; ++i){
		left[i] = array[p + i];
		leftcard[i] = cards[p + i];
	}
	left[n1] = INT_MAX;
	for(int i = 0; i < n2; ++i){
		right[i] = array[q + 1 + i];
		rightcard[i] = cards[q + 1 + i];
	}
	right[n2] = INT_MAX;
	int i=0, j=0;
	for(int k = p; k <= r; ++k){
		if(left[i] <= right[j]){
			array[k] = left[i];
			cards[k] = leftcard[i];
			++i;
		}else{
			array[k] = right[j];
			cards[k] = rightcard[j];
			++j;
		}
	}
}
void mergeSort(int *array, char *cards, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		mergeSort(array, cards, p, q);
		mergeSort(array, cards, q+1, r);
		merge(array, cards, p, q, r);
	}
}
void swap(int p, int r){
	int tmpnum = numbers[p];
	char tmpcard = cards[p];

	numbers[p] = numbers[r];
	cards[p] = cards[r];

	numbers[r] = tmpnum;
	cards[r] = tmpcard;
}
int partition(int p, int r){
	int x = numbers[r];
	int i = p - 1;
	for(int j = p; j < r; ++j){
		if(numbers[j] <= x){
			++i;
			swap(i, j);			
		}
	}
	swap(i+1, r);
	return i + 1;
}

void quickSort(int p, int r){
	if(p < r){
		int q = partition(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);
	}
}
void printCard(int n){
	for(int i = 0; i < n; ++i){
		printf("%c %d\n", cards[i], numbers[i]);
	}
}
void printCardM(int n){
	for(int i = 0; i < n; ++i){
		printf("%c %d\n", cardsM[i], numbersM[i]);
	}
}
void check(int n){
	for(int i = 0; i < n; ++i){
		if((cards[i] == cardsM[i]) && (numbers[i] == numbersM[i])){
			
		}else{
			printf("Not stable\n");
			return;
		}
	}
	printf("Stable\n");
}
int main(){
	int n;
	char line[100];
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &n);
	char *str_ptr;
	for(int i = 0; i < n; ++i){
		fgets(line, sizeof(line), stdin);
		cards[i] = line[0];
		cardsM[i] = line[0];
		str_ptr = strtok(line, " ");
		str_ptr = strtok(NULL, " ");
		numbers[i] = atoi(str_ptr);
		numbersM[i] = atoi(str_ptr);
	}
	
	quickSort(0, n - 1);
	mergeSort(numbersM, cardsM, 0, n - 1);
	check(n);
	printCard(n);
	
	return 0;
}
