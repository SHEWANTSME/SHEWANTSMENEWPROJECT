////#include <iostream>
////#include<vector>
////#include<unordered_map>
////#include<algorithm>
////using namespace std;
////int main() {
////
////	int n;
////	cin >> n;
////	vector<int>first(n);
////	vector<int>second(n);
////	for (int i = 0; i < n; i++) {
////		cin >> first[i] >> second[i];
////	}
////	for (int i = 0; i < n; i++) {
////		int anss = 1;
////		for (int j = 0; j < n; j++) {
////			if (first[i] < first[j] && second[i] < second[j]) anss++;
////		}
////		cout << anss << " ";
////	}
////	return 0;
////}
//
//#include<iostream>
//
//using namespace std;
//class Second {
//
//};
//class First {
//
//};
//class Fraction {
//private:
//	Fraction() { cout << " emma " << endl; };
//	int m_numerator=3;
//	int m_denominator=5;
//
//public:
//	Fraction(int &a, int &b) {
//		Fraction();
//		print();
//	}
//	void print() {
//		cout << m_numerator << " " << m_denominator << endl;
//	}
//
//};
//
//
//
//int main() {
//	//Fraction frac;
//	//frac.print(); �ʱ�ȭ need -> garbage
//	//Fraction frac{ 0,2 }; // private�̸� ����
//	Fraction { 3,4 };
//
//
//
//	return 0;
//}


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int a, n,res=0,cnt=1;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	res = res + v[n - 1];
	int	i = n - 2;
	int j = n - 3;
	int temp;
	while (j > -1) {
		if (v[i] > v[j]) {
			res = res + v[i];
			cnt++;
			i = i - 2;
			j = j - 2;
			if (cnt == 2) {
				res = res + v[i];
				i = i - 1;
				j = j - 1;
				cnt = 1;
			}
		}
		else if (v[i] < v[j]) {
			res = res + v[j];
			cnt = 1;
			i = i - 2;
			temp = j;
			j = i;
			i = temp;
			i = i - 1;
			j = j - 1;
			a = res;
		}
		else {
			res = max(res, a);

		}
	}
	if (cnt == 2) cout << res << endl;
	if (cnt == 1) {
		cout << res + v[0] << endl;
	}
//	cout << res << endl;
//	cout << res << endl;
	/*	for (int j = n - 3; j > -1; j--) {
			if (cnt > 2) {

			}
			if (v[i] > v[j]) {
				res = res + v[i]; 
				cnt++;
				i--;
			}
			else if (v[i] < v[j]) {
				res = res + v[j];
				cnt = 1;
				i = i - 2;
			}
		}*/
	
	return 0;
}
���� �� �ȵǴ°ž� ����ġ�� ,��,��,,��,��,��