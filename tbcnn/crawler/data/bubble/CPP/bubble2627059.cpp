#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// ShowData
void showData(vector<int>::iterator start,vector<int>::iterator end)
{
	vector<int>::iterator iter;
	for( iter = start; iter != end; iter++ )
	{
		cout << *iter;
		if( iter != (end-1) )
		{
			cout << " ";
		}
	}
	cout << endl;
	return;
}

// BubbleSort
int bubbleSort(vector<int>::iterator start,vector<int>::iterator end)
{
	int swapCnt = 0;
	vector<int>::iterator count, swap_a, swap_b;
	
	for(count = start; count != end; count++)
	{
		for(swap_a = end-1; swap_a != count; swap_a--)
		{
			swap_b = swap_a;
			advance( swap_b , -1 );
			if( *swap_b > *swap_a )
			{
				iter_swap( swap_a, swap_b );
				swapCnt++;
			}
		}
	}
	return swapCnt;
}

int main(void){
	int numData;
	cin >> numData;
	
	// Input
	vector<int> vectorInt;
	vectorInt.reserve(100);
	int input;
	while( cin >> input )
	{
		vectorInt.push_back( input );
	}
	
	// swap
	int swapCnt = bubbleSort( vectorInt.begin(), vectorInt.end() );
	showData( vectorInt.begin(), vectorInt.end() );
	cout << swapCnt << endl;
	
	return 0;
}
