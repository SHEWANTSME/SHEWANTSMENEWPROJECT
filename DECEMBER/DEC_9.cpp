//#include <iostream>
//#include <vector>
//using namespace std;
//int dp[10001];
//int main() {
//	int n; cin >> n;
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 3;
//	dp[4] = 4;
//	for (int i = 5; i <=10000; i++) {
//		dp[i] = dp[i - 3] + (i/2) + 1;
//	}
//
//	while (n--) {
//		int x; cin >> x;
//		cout << dp[x] << endl;
//	}
//	
//
//	return 0;
//}
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//#define endl "\n"
//using namespace std;
////int dp[1000001];
//#include <iostream>
//using namespace std;
//long long dp[100001][4];
//int main() {
//	int T, temp;
//	cin >> T;
//	dp[1][1] = 1; dp[2][2] = 1;
//	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
//	for (int i = 4; i <= 100000; i++) {
//		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
//		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
//		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
//	}
//	for (int i = 0; i < T; i++) {
//		cin >> temp;
//		cout << (dp[temp][1] + dp[temp][2] + dp[temp][3]) % 1000000009 << endl;
//	}
//}

// vector<int >v;
//void DFS(int num, int k, int cnt) {
//	if (cnt == k) return;
//	if (num == 0) {
//
//	}
//	if (cnt == 0) {
//		for (int i = 0; i < num; i++) {
//			v.push_back(1);
//			cout << i << " ";
//		}cout << endl;
//		cnt++;
//		DFS(num - 1, k, cnt);
//	}
//	if (cnt != 0) {
//		
//	}
//	
//
//
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int num; cin >> num;
//	int k; cin >> k;
//	
//	switch (num) {
//	case 1:
//		dp[num] = 1;
//		break;
//	case 2:
//		dp[num] = 2;
//		break;
//	case 3:
//		dp[num] = 4;
//		break;
//	case 4:
//		dp[num] = 7;
//		break;
//	case 5:
//		dp[num] = 13;
//		break;
//	case 6:
//		dp[num] = 24;
//		break;
//	case 7:
//		dp[num] = 44;
//		break;
//	case 8:
//		dp[num] = 81;
//		break;
//	case 9:
//		dp[num] = 149;
//		break;
//	case 10:
//		dp[num] = 274;
//		break;
//	}
//	vector<int> v;
//	if (k > dp[num]) cout << -1 << endl;
//	else {
//		DFS(num, k,0);
//	}
//
//	/*for (int i = 4; i <= 10; i++) {
//		dp[i] = ((dp[i - 1] + dp[i - 2]) + dp[i - 3]);
//	}*/
//	/*int testcase; cin >> testcase;
//	while (testcase--) {
//		int n; cin >> n;
//		cout << dp[n] << endl;
//	}*/
//	return 0;
//}


#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
int dp[1000001];
int dp2[1001][1001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int>v[1001];
	v[1][1] = 1;
	dp2[1][1] = 1;
	dp2[2][1] = 1;
	dp2[2][2] = 2;
	dp2[3][1] = 1;
	dp2[3][2] = 3;
	dp2[3][3] = 4;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 100; i++) {
		for (int j = 2; j <= i; j++) {
			//v[i][j] = (v[i - 1][j - 1] + v[i - 2][j - 1]) % 1000000009 + v[i - 3][j - 1]) % 1000000009;
			dp2[i][j] += (dp2[i - 1][j - 1] + dp2[i - 2][j - 1]) % 1000000009 + dp[i - 3][j - 1]) % 1000000009;
		}		
	}
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3]) % 1000000009;
	}
	int testcase; cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}