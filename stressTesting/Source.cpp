#include<iostream>
#include<cstdlib>
#include<vector>
/*
### Max Pair wise Product ####

	array -> [9,5,4,3,8,7,2]
	.
	Product of max 2 numbers 
	.
	# 1st max -> 9
	.
	# 2nd max -> 8
	.
	size of arr -> 2 ≤ size ≤ 100000 
	.
	value of each number -> 1 ≤ num ≤ 100000 
*/

// first we will think about Naive solution -> O(n²)


using namespace std;
long long MaxPairwiseProduct(const vector<int>& numbers) {
	long long result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (((long long)numbers[i]) * numbers[j] > result) {
				result = ((long long)(numbers[i])) * numbers[j];
			}
		}
	}
	return result;
}
/*
then we need to optimize 
*/

//O(n)

long long MaxPairwiseProductFast(const vector<int>& numbers) {
	int n = numbers.size();
	int indexOfMaxNumber1 = -1;
	for (int i = 0; i < n; ++i) {
		if ((indexOfMaxNumber1 == -1) || (numbers[i] > numbers[indexOfMaxNumber1])) {
			indexOfMaxNumber1 = i;
		}
	}
	int indexOfMaxNumber2 = -1;
	for (int j = 0; j < n; ++j) {
		if (j != indexOfMaxNumber1 && ((indexOfMaxNumber2 == -1) || (numbers[j] > numbers[indexOfMaxNumber2]))) {
			//j != indexOfMaxNumber1
			indexOfMaxNumber2 = j;
		}
	}
	cout <<"|Max Index 1: " << indexOfMaxNumber1 << " | Max Index 2: " << indexOfMaxNumber2 <<"|" << endl;

	return((long long)(numbers[indexOfMaxNumber1])) * numbers[indexOfMaxNumber2];

}
vector<int> manualTestingVector(vector<int>& a) {
	a.push_back(9);
	a.push_back(3);
	a.push_back(5);
	a.push_back(100000);
	a.push_back(16);
	a.push_back(100000);
	return a;
}

int main() {
	while (true) {

		int n = rand() % 1000 + 2;
		cout <<"Size of Array: " << n << endl;
		vector<int>a;
		for (int i = 0; i < n; ++i) {
			a.push_back(rand() % 100000);
		}
		cout << "Items Of Array: ";
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}

		cout << endl;
		long long res1 = MaxPairwiseProduct(a);
		long long res2 = MaxPairwiseProductFast(a);
		if (res1 != res2) {
			cout << "Wrong answer: " << "Naive : " << res1 << " Optimized  : " << res2 << endl;
			break;
		}
		else {
			cout << "OK !" << endl;
		}
	}
	return 0;
}

/*
Array with extreme values: Testing with extreme values,
such as the smallest and largest possible values,
can help identify edge cases that may not be immediately obvious
*/