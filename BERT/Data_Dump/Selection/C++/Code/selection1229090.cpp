#include <iostream>
#include <vector>
using namespace  std;

void fnSelectionSort(vector<int> &argviSort, int &argiSortCnt)
{
  for (int ixSorting = 0; ixSorting < argviSort.size() - 1; ixSorting++)
  {
    int ixMinimum = ixSorting;
    bool bSorting = false;

    for (int j = ixSorting + 1; j < argviSort.size(); j++)
    {
      if (argviSort[j] < argviSort[ixMinimum])
      {
        ixMinimum = j;
        bSorting = true;
      }
    }
    if (bSorting)
    {
      swap(argviSort[ixSorting], argviSort[ixMinimum]);
      argiSortCnt++;
    }
  }
}

void fnOutput(const vector<int> &argviSort, int argiSortCnt)
{
  for (int i = 0; i < argviSort.size(); i++)
  {
    if (i) cout << " ";
    cout << argviSort[i];
  }
  cout << endl;
  cout << argiSortCnt << endl;
}

int main()
{
  int iSortCnt = 0;
  vector<int> viSort;
  int iMaxSize;
  
  cin >> iMaxSize;
  for (int i = 0; i < iMaxSize; i++)
  {
    int iNum;
    cin >> iNum;
    viSort.push_back(iNum);
  }

  fnSelectionSort(viSort, iSortCnt);
  fnOutput(viSort, iSortCnt);

  return 0;
}
