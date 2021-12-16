//#include<iostream>
//#include <vector>
//#include <algorithm>
//#define endl "\n"
//using namespace std;
//int L, C;
//char arr[16];
//int visited[16];
//vector<int>v;
//void DFS(int left, int right, int idx1, int idx2) {
//	
//}
//int main() {
//	// my own 힘으로 풀어보쟈. 절대 어려운거 아님.
//	cin >> L >> C;
//	for (int i = 0; i < C; i++) {
//		cin >> arr[i];
//	}
//	sort(arr, arr + C);
//	if (L == C) {
//		for (int i = 0; i < C; i++) {
//			cout << arr[i];
//		}
//		exit(0);
//	}
//	else {
//		DFS(0,0,)
//	}
//	DFS(0, 0, 0, 0);
//	return 0;
//}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool check = false;
int main() {
	string s;
	getline(cin, s);
	int idx = s.find(" ");
	string ss = s.substr(idx+1);
	s.resize(idx);

	int len = (s.size() > ss.size()) ? s.size() : ss.size();
	string result (len, '0');

	for (int i = 0; i < len; i++) {
		int k = check;
		check = false;
		if (i < s.size()) k = k + s[s.size() - i - 1] - '0';
		// 맨뒤에거부터 0~18까지 되니까 (합이)
		//k라는 변수에 넣고
		if (i < ss.size()) k = k + ss[ss.size() - i - 1] - '0';
		if (k > 9) { // 10이상이면
			check = true; // 체크 1
			k -= 10; // 뒷자리만 k에 넣음
		}
		result[len - i - 1] = k + '0';// 뒷자리를 string으로 바꿔주는 작업
	}
	if (check) result.insert(result.begin(), '1');

	cout << result << endl;

	return 0;
}