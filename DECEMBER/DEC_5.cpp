#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[200002];
int ans[100001];
bool compare(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
	// ������ �ٲ��� �ʴ� ����̰�,  �����͸� �־�� �ϴϱ� ������ ��
}
int num[4][2] = { {2,2},{2,4},{2,8},{2,6 } };


int main() {
	int n; cin >> n;
	int x, y;
	vector<int>v(n);
	vector<pair<int, int>>p(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i] = { y,x };
	}
	sort(p.begin(), p.end(),compare);
	int count = 1;
	int end = p[0].first;
	for (int i = 1; i < n; i++) {
		if (p[i].second >= end) {
			end = p[i].first;
			count++;
		}
	}



	
	//int a = 0;
	//while (a<n) {
	//	int k = 2;
	//	/*int x = 0;
	//	int y = 0;*/
	//	v.push_back( p[a].first);
	//	v.push_back( p[a].second);
	//	
	//	//for (int i = 0; i < n; i++) {
	//	//	if (p[i].first >= v.back()) {
	//	//		v.push_back( p[i].first); 
	//	//		v.push_back( p[i].second);
	//	//		k += 2;
	//	//	//break; 
	//	//	}
	//	//}
	//	
	//	// k ��/2�� length�ϱ� ���� �����ָ� ��
	//	// 
	//	ans[a] = k / 2;
	//	v.clear();
	//	/*for (int i = 0; i < k; i++) {
	//		arr[i] = 0;
	//	}*/
	//	a++;
	//}
/*
	int max = -10;
	sort(ans, ans + n);
	cout << ans[n - 1] << endl;
	for (int i = 0; i < n; i++) {
		if (ans[i] > max) max = ans[i];
	}
	cout << max << endl;*/



	cout << count << endl;
	return 0;
}