/*
ソートが安定(stable)かどうか確かめる
手続きを入れるより、

ｎがそこまで大きくないので
安定であると周知のソートアルゴリズムを使って
ソートしたのと比較して一致するか見る。
*/

/*
「pivotを中間に、大きいものと小さいものを交換していく」
という感じではなく、
「pivotより小さいものを探して、前の方に詰めていく（添え字iのとこ）」
という感じである。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//カード記録用の構造体
//typedef struct CARD_TEMP { //c++は構造体のテンプレートいらない
struct CARD {
	char suit; 
	int num;
	bool operator == (const CARD& right) const { //演算子のオーバーロード
        return suit==right.suit && num==right.num;
    }
};

//<algorithm>のstable_sort()をCARD型配列で使うための、比較用関数
bool CARD_asc( const CARD& left, const CARD& right ) {
    return left.num < right.num;
}


int Partition(vector<CARD> &A, int p, int r){
	int i,j;
	int pivot;

	pivot = A[r].num;
	i=p-1;
	for(j=p; j<r; j++){
		if(A[j].num<=pivot) {
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void Quicksort(vector<CARD> &A, int p, int r){
	int q;

	if(p<r){
		q=Partition(A, p, r);
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);	
	}
}


int main() {
	int i,j;
    int n;
    int p,q,r,pivot;
    vector<CARD> A,B;
    
    cin >> n;
    for(i=0;i<n;i++){
		CARD buf;
		cin >> buf.suit;
		cin >> buf.num;
        A.push_back(buf);
    }

	B=A; //コピー
    stable_sort(B.begin(), B.end(), CARD_asc);

	p=0;
	r=n-1;
	Quicksort(A, p, r);
    
    //出力
	if(A==B) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
    for(i=0;i<n;i++){
		cout << A[i].suit << " " << A[i].num << endl;
    }

	return 0;
}
