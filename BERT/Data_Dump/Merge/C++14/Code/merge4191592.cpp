//	-*- mode: C++ -*-
// Merge Sort
//	 Write a program of a Merge Sort algorithm implemented by the following pseudocode. You should also report the number of comparisons in the Merge function.
//
// Merge(A, left, mid, right)
//   n1 = mid - left;
//   n2 = right - mid;
//   create array L[0...n1], R[0...n2]
//   for i = 0 to n1-1
//     do L[i] = A[left + i]
//   for i = 0 to n2-1
//     do R[i] = A[mid + i]
//   L[n1] = SENTINEL
//   R[n2] = SENTINEL
//   i = 0;
//   j = 0;
//   for k = left to right-1
//     if L[i] <= R[j]
//       then A[k] = L[i]
//            i = i + 1
//       else A[k] = R[j]
//            j = j + 1
//
// Merge-Sort(A, left, right){
//   if left+1 < right
//     then mid = (left + right)/2;
//          call Merge-Sort(A, left, mid)
//          call Merge-Sort(A, mid, right)
//          call Merge(A, left, mid, right)
// Input
//	 In the first line n is given. In the second line, n integers are given.
//
// Output
//	 In the first line, print the sequence S. Two consequtive elements should be separated by a space character.
//
//	 In the second line, print the number of comparisons.
//
// Constraints
//	 n ≤ 500000
//	 0 ≤ an element in S ≤ 10^9
// Sample Input 1
//	 10
//	 8 5 9 2 6 3 7 1 10 4
// Sample Output 1
//	 1 2 3 4 5 6 7 8 9 10
//	 34

#include <iostream>
#include <vector>
#include <climits>

class CB
{
public:
	CB(){}
	~CB(){}
	void	Sort();

private:
	unsigned int					n	{0};
	std::vector<unsigned long long>	S	{};
	unsigned int					count	{0};

	void	Merge(unsigned int	left,
				  unsigned int	mid,
				  unsigned int	right);

	void	MergeSort(unsigned int	left,
					  unsigned int	right);
};

void	CB::Sort()
{
	std::cin >> n;

	for(unsigned int i = 0; i < n; i++){
		unsigned long long	Si;
		std::cin >> Si;
		S.push_back(Si);
	}

	MergeSort(0, n);

	for(unsigned int i = 0; i < n; i++){
		std::cout << S[i];
		if(i < n - 1){
			std::cout << ' ';
		}
	}

	std::cout << std::endl;

	std::cout << count << std::endl;
}

void	CB::Merge(unsigned int	left,
				  unsigned int	mid,
				  unsigned int	right)
{
	unsigned int	n1	= mid - left;
	unsigned int	n2	= right - mid;

	std::vector<unsigned long long>	L	{};
	std::vector<unsigned long long>	R	{};

	for(unsigned int i = 0; i < n1 ; i++){
		L.push_back(S[left + i]);
	}
	L.push_back(ULLONG_MAX);

	for(unsigned int i = 0; i < n2; i++){
		R.push_back(S[mid + i]);
	}
	R.push_back(ULLONG_MAX);

	unsigned	int	i	{0};
	unsigned	int	j	{0};

	for(unsigned int k = left; k < right ; k++){
		count++;
		if(L[i] <= R[j]){
			S[k]	= L[i];
			i++;
		}
		else{
			S[k]	= R[j];
			j++;
		}
	}
}

void	CB::MergeSort(unsigned int	left,
					  unsigned int	right)
{
	if(left + 1 < right){
		unsigned int	mid	= (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid, right);
		Merge(left, mid, right);
	}
}

int	main(int	argc,
		 char*	argv[])
{
	CB	cb;

	cb.Sort();

	return 0;
}

