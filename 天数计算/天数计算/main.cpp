﻿#include <iostream>
#include<vector>
using namespace std;


class Solution
{
public:
	vector<int> sortedSquares(vector<int>& A)
	{
		int k = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
			if (A[i] * A[i] < A[j] * A[j]) {
				result[k--] = A[j] * A[j];
				j--;
			}
			else {
				result[k--] = A[i] * A[i];
				i++;
			}
		}
		return result;
	}
};


int main()
{
	Solution solution;
	int b[7] = { 1,2,3,4,5,9,8 };
	vector<int> A(b, b + 7);
	auto result = solution.sortedSquares(A);
	cout << result.back() << endl;
	return 0;
}