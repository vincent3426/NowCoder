#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * 按圈打印，一定从对角线开始
 */

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		if (mat.empty() || n <= 0 || m <= 0)
			return ret;
		int index = 0;
		while (index * 2 < n && index * 2 < m) {
			vector<int> ret_tmp = printMethod(index, mat, n, m);
			for (unsigned int i = 0; i < ret_tmp.size(); i++) {
				ret.push_back(ret_tmp[i]);
			}
			index++;
		}
		return ret;
	}
	vector<int> printMethod(int index, vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int endx = m - index - 1; // end column
		int endy = n - index - 1; // end row
		// left->right
		for (int i = index; i <= endx; i++) {
			ret.push_back(mat[index][i]);
		}
		// up->down
		if (index < endy) {
			for (int i = index + 1; i <= endy; i++) {
				ret.push_back(mat[i][endx]);
			}
		}
		// right->left
		if (index < endy && index < endx) {
			for (int i = endx - 1; i >= index; i--) {
				ret.push_back(mat[endy][i]);
			}
		}
		// down->up
		if (index < endy - 1 && index < endx) {
			for (int i = endy - 1; i >= index + 1; i--) {
				ret.push_back(mat[i][index]);
			}
		}
		return ret;
	}
};

int main() {
	Printer *obj = new Printer();
	int cnt = 1;
	vector<vector<int> > mat(3, vector<int>(4, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = cnt;
			cnt++;
		}
	}
	vector<int> b = obj->clockwisePrint(mat, 3, 4);
	for (unsigned int i = 0; i < b.size(); i++) {
		cout << b[i] << endl;
	}
	return 0;
}
