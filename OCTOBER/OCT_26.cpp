//#include <iostream>
//#include <vector>
//using namespace std;
//
//void findcoin(int a, vector<int> &v,int cnt) {
//	int alpha = a / v.back();
//	if (a - (alpha*v.back()) == 0) { cnt = cnt + alpha; }// { cout << alpha << endl; }
//	else {
//		a = a - (alpha*v.back());
//		cnt = cnt + alpha;
//		while (v.back() > a) {
//			v.pop_back();
//		}
//		findcoin(a, v, cnt);
//	}
//
//	cout << cnt << endl;
//	exit(0);
//}
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int>v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	while (v.back() > k) {
//		v.pop_back();
//	}
//	findcoin(k, v, 0);
//	
//}
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int make_num(int i, vector<int>&v) {
	//i 는 숫자 자리수
	int j = 0;
	int t = i;
	int sum = 0;
	while (j <= i) {
		sum = sum+v[j] * std::pow(10, t-1);
		j++; t--;
	}
	return sum;
}

int main() {
	string s;
	int a = 0;
	cin >> s;
	cout << s << endl;
	vector<int>v((int)s.size());
	vector<int>v2((int)s.size());
	v2[0] = (int)s.at(0) - 48;
	int k = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		if ((int)s.at(i) == 43){
			make_num(i, v2);
			v[k] = 43;
			k++;
		}
		else if ((int)s.at(i) == 45) {
			make_num(i, v2);
			v[k] = 45;
			k++;
		}
		else {
			v2[i] = (int)s.at(i) - 48;
		}
	}





	cout << s.at(0) << endl;
	cout << (int)s.at(0)-48 << endl;
	cout << (int)s.size() << endl;
	for (int i = 1; i < (int)s.size(); i++) {
		if ((int)s.at(i) == 43) cout << '+'<< endl;
		if ((int)s.at(i) == 45) cout << '-' << endl;
	}

}