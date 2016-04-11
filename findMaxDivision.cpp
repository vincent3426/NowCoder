#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxDivision {
public:
	static bool cmp(int x, int y) {
		return (x > y);
	}

	int findMaxDivision(vector<int> A, int n) {
		sort(A.begin(), A.end(), cmp);
		int ret = A[0] - A[1];
		for (int i = 1; i < n - 1; i++) {
			ret = (A[i] - A[i + 1]) > ret ? A[i] - A[i + 1] : ret;
		}
		return ret;
	}
};

int main() {
	MaxDivision *obj = new MaxDivision();
	int a[4] = { 9, 3, 1, 10};
	vector<int> ret(a, a + 4);
	cout << obj->findMaxDivision(ret, 4) << endl;
	return 0;
}
