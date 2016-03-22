class Printer {
public:
    // O(m*n)*6*三角函数运算，时间复杂度过高
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
        int i, j, cnt = 0;
        double theta = 0;
        vector<int> ret;
        while (cnt < n*m){
            if((i >= 0) && (i < n) && (j >= 0) && (j < m) && (mat[i][j] != -1)){
                ret.push_back(mat[i][j]);
                mat[i][j] = -1;
                i += round(sin(theta));
                j += round(cos(theta));
                cnt++;
            }else{
                i -= round(sin(theta));
                j -= round(cos(theta)); // plus once more
                theta += 3.1415926/2;
                i += round(sin(theta));
                j += round(cos(theta));
            }
        }
        return ret;
    }
};

int main() {
	Printer obj;
	int cnt = 1;
	vector<vector<int> > mat(3, vector<int>(4, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = cnt;
			cnt++;
		}
	}
	vector<int> b = obj.clockwisePrint(mat, 3, 4);
	for (unsigned int i = 0; i < b.size(); i++) {
		cout << b[i] << endl;
	}
	return 0;
}
