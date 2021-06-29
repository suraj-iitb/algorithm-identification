#include <iostream>
int main()
{
	using namespace std;
	int num;
	cin >> num;
	int sort[num];
	for (int i = 0; i < num; i++) cin >> sort[i];
	int v = 1;
	cout << sort[0];
	for (int i = 1; i < num;i++) cout << " " << sort [i] ;
	cout <<endl; 
	for (int i = 1; i <= num-1;i++)
	{	int j = i-1; 
		v = sort[i];
	
		while (j >= 0 && sort[j]> v)
		{	sort[j+1] = sort[j];
			j--;
		}
		sort[j+1] = v;
		cout << sort[0];
		for (int i = 1; i < num;i++) cout  << " " << sort [i];
		cout << endl;}
	return 0; 
			
 } 
