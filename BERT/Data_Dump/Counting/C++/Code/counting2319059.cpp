#include<iostream>
using namespace std;

static const int kiMaxSize = 2000000;
static const int kiMaxValue = 10000;

//?¬¬????????°????????????????????????????¬¬????????°?????\????????¢??°
void CountingSort(const int aiArray[], int aiSortedArray[], const int iNumA) {
	int aiValCouArray[kiMaxValue] = { 0 };

	//aiValCouArray???aiArray???????´????????????°??????????????????????¨??????????
	for (int i = 0; i < iNumA; i++) 
		aiValCouArray[aiArray[i]]++;

	//aiValCouArray???aiArray???????´???\??????????????°??????????????????????¨??????????
	for (int i = 1; i < kiMaxValue; i++)
		aiValCouArray[i] += aiValCouArray[i - 1];

	for (int i = iNumA-1; i >= 0; i--) {
		int iValue_count = aiValCouArray[aiArray[i]];
		//????????°???(?????????????????????,????????????????????????)???aiSortedArray[1]?????\??£??????????????????
		aiSortedArray[iValue_count-1] = aiArray[i];
		aiValCouArray[aiArray[i]]--;
	}
}

//??\??????????????°??????O(n+k(??°???????????§????´?))??§?????????????????????????????¢??°
int main() {
	int aiArray[kiMaxSize];
	int iNumA;
	
	//??\???
	cin >> iNumA;
	for (int i = 0; i < iNumA; i++) cin >> aiArray[i];


	int aiSortedArray[kiMaxSize];
	CountingSort(aiArray, aiSortedArray, iNumA);


	//??????
	for (int i = 0; i < iNumA; i++) {
		if (i) cout << " ";
		cout << aiSortedArray[i];
	}
	cout << endl;

	return 0;
}