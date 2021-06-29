//	-*- mode: C++ -*-
//	Selection Sort
//		Write a program of the Selection Sort algorithm which sorts a sequence A in ascending order. The algorithm should be based on the following pseudocode:
//
//		SelectionSort(A)
//		1 for i = 0 to A.length-1
//		2     mini = i
//		3     for j = i to A.length-1
//		4         if A[j] < A[mini]
//		5             mini = j
//		6     swap A[i] and A[mini]
//		Note that, indices for array elements are based on 0-origin.
//
//		Your program should also print the number of swap operations defined in line 6 of the pseudocode in the case where i ≠ mini.
//
//	Input
//		The first line of the input includes an integer N, the number of elements in the sequence.
//
//		In the second line, N elements of the sequence are given separated by space characters.
//
//	Output
//		The output consists of 2 lines.
//
//		In the first line, please print the sorted sequence. Two contiguous elements of the sequence should be separated by a space character.
//
//		In the second line, please print the number of swap operations.
//
//	Constraints
//		1 ≤ N ≤ 100
//
//	Sample Input 1
//		6
//		5 6 4 2 1 3
//	Sample Output 1
//		1 2 3 4 5 6
//		4
//
//	Sample Input 2
//		6
//		5 2 4 6 1 3
//	Sample Output 2
//		1 2 3 4 5 6
//		3

#include <iostream>
#include <vector>

unsigned int SelectionSort(std::vector<int>&	A)
{
	unsigned int swapCount	{0};

	for(unsigned int i = 0; i < A.size(); i++){
		auto	mini	= i;

		for(unsigned int j = i; j < A.size(); j++){
			if(A[j] < A[mini]){
				mini	= j;
			}
		}

		if(i != mini){
			auto	tmp	= A[i];
			A[i]		= A[mini];
			A[mini]		= tmp;
			swapCount++;
		}
	}

	return swapCount;
}

int	main(int	argc,
		 char*	argv[])
{
	unsigned int		N	{0};
	std::vector<int>	A	{};

	std::cin >> N;

	for(unsigned int i = 0; i < N; i++){
		int	element	{0};
		std::cin >> element;
		A.push_back(element);
	}

	unsigned int swapCount	= SelectionSort(A);

	unsigned int count	{0};

	for(auto element : A){
		std::cout << element;
		count++;
		if(count < N){
			std::cout << ' ';
		}
		else{
			std::cout << '\n';
		}
	}

	std::cout << swapCount << '\n';
    return 0;
}

