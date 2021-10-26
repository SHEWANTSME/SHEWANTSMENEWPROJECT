////
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main() {
//	int num;
//	cin >> num;
//	vector<int>v1(num);
//	vector<int>v2(num);
//	vector<int>v3(num);
//	vector<int>v4(num);
//
//	for (int i = 0; i < num; i++) {
//		cin >> v1[i] >> v2[i];
//	}
//	for (int i = 0; i < num; i++) {
//		v3[i] = v2[i] - v1[i];
//		v4[i] = v3[i];
//	}
//	int sum = 0;
//	std::sort(v3.begin(), v3.end(),greater<int>());// 역순정렬
//	while (sum <= num) {
//		for (auto &element : v3) {
//			sum = sum + element;
//			if (sum > num) v3.erase(v3.begin());
//		}
//
//	}
//	
//
//
//
//
//}//1931 어려우어ㅓ아ㅓㅏ러아ㅜㅏㅇ


#include <iostream>
#include<vector>
using namespace std;

int main() {
	int num, k;
	cin >> num >> k;
	vector<int> vec(num);
	int alpha = 0;
	for (int i = 0; i < num; i++) {
		cin >> vec[i];
	}
	cout << vec.capacity() << endl;



		while (vec.back()>k) {
		vec.pop_back();
		//alpha++;

	}
		while (vec.capacity() > 0) {
		 alpha = k / vec.back();
		 k = k - (alpha * vec.back());
		 if (k == 0) {
			 cout << alpha << endl;
			 break;
		 }
		else {
			 vec.pop_back();
			 cout << alpha << endl;
		}
		//break;
	}
	//cout << (int)vec.capacity() << endl;
	//cout << vec.size() << endl;
	


	return 0;
}