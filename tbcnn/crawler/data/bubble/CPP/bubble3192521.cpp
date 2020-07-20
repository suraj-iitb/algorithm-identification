#include <iostream>
int main()
{
	using namespace std;
	int num;
	cin >> num;
	
	int sort[num];
	for (int i=0; i < num; i++) cin >> sort[i];
	
	int oper = 0;
	int v = 0;
	for (int i = 0; i < num - 1; i++){
		for (int j = num-1; j > 0; j--){
			if (sort[j] < sort[j-1]){
				v = sort[j];
				sort[j] = sort[j-1];
				sort[j-1] = v;
				oper++;
			};
		};
	};
	cout << sort[0];
	for (int i = 1; i < num; i++) cout << " " << sort[i];
	cout << endl << oper << endl; 
	return 0;
 } 
