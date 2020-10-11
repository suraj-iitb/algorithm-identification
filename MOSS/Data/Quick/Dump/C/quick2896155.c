#include<stdio.h>
#define MAX 100010

struct CARD {
	int num;
	char sym;
};

struct CARD card[MAX];
struct CARD buf[MAX];

int Partition(struct CARD card[], int sp, int ep) {
	struct CARD x = card[ep];
	int i = sp - 1;
	struct CARD buff;
	for (int j = sp; j < ep; j++) {
		if (card[j].num <= x.num) {
			i++;
			buff = card[i];
			card[i] = card[j];
			card[j] = buff;
		}
	}
	card[ep] = card[i + 1];
	card[i + 1] = x;
	return i + 1;
}

void QuickSort(struct CARD card[], int sp, int ep) {
	int q;
	if (sp < ep) {
		q = Partition(card, sp, ep);
		QuickSort(card, sp, q - 1);
		QuickSort(card, q + 1, ep);
	}
}

void ShellSort(struct CARD card[], int size) {
	int i;
	int zone;
	struct CARD buff;
	int step = 1;
	while (step <= size) {
		step = 3 * step + 1;
	}
	step = step / 3;
	while (step >0) {
		for (zone = step; zone < size; zone++) {
			buff = card[zone];
			for (i = zone - step; (i >= 0) && (card[i].num > buff.num); i = i - step) {
				card[i + step] = card[i];
			}
			card[i + step] = buff;
		}
		step = step / 3;
	}
}

int main() {
	int N;
	char bufS;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c %d%c", &card[i].sym, &card[i].num,&bufS);
		buf[i].num = card[i].num;
		buf[i].sym = card[i].sym;
	}
	QuickSort(card, 0, N - 1);
	ShellSort(buf, N);
	for (int i = 0; i < N; i++) {
		if (card[i].sym == buf[i].sym) {
			if (i == N - 1) {
				printf("Stable\n");
				break;
			}
			else continue;
		}
		else {
			printf("Not stable\n");
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%c %d\n", card[i].sym, card[i].num);
	}
	return 0;
}

