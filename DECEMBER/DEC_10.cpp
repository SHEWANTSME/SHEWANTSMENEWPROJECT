////#include <iostream>
////#include <vector>
////#define endl "\n"
////using namespace std;
////
////int dp[100001];
//////dp[a][0] = 짝, dp[a][1] = 홀
/////*
////1. 길이가 짝수이며 반쪽의 합이 나머지 합과 같음
////2. 길이가 홀수이며 중심에 1
////3. 길이가 홀수 중심에 2
////4. 중심3
////
////*/
////int main() {
////	ios_base::sync_with_stdio(false);
////	cin.tie(NULL);
////	cout.tie(NULL);
////	/*dp[1][1] = 1;
////	dp[2][1]= 1;
////	dp[2][2] = 1;
////	dp[3][1]= 1;
////	dp[3][2] = 2;
////	dp[3][3] = 1;*/
////	dp[1] = 1;
////	dp[2] = 2;
////	dp[3] = 2;
////	dp[4] = 3;
////	dp[5] = 3;
////	dp[6] = 6;
////	for (int i = 7; i <= 100000; i++)
////		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
////	
////	/*for (int i = 4; i <= 1000; i++) {
////		dp[i][i] = 1;
////		for (int j = 2; j < i; j++) {
////			dp[i][j] = ((dp[i - 1][j-1] + dp[i - 2][j-1]) % 1000000009 + dp[i - 3][j-1]) % 1000000009;
////			if(j%2==0) 
////		}
////	}*/
////	int testcase; cin >> testcase;
////	while (testcase--) {
////		int n, m; cin >> n ;
////		cout << dp[n] << endl;
////		//cout << dp[n][m] << endl;
////		//cout << dp[n][1] << " "<< dp[n][0] << endl;
////	}
////	return 0;
////}
//
//#include <iostream>
//#define endl "\n"
//using namespace std;
//int dp[12];
//
//void DFS(int n, int k) {
//	if (n < 4 && dp[n] == k) {
//		cout << n <<endl;
//		return;
//	}
//	for (int i = 1; i < 4; i++) {
//		k -= dp[n - i];
//		if (k <= 0) {
//			cout << i << "+";
//			DFS(n - i, k + dp[n - i]);
//			return;
//		}
//	}
//	return;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	for (int i = 4; i < 12; i++)	dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//	int n, k;
//	cin >> n >> k;
//	if (k > dp[n]) cout << -1 << endl;
//	DFS(n, k);
//	return 0;
//}
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001][10001];
int num, cnt = 0;
int main() {
	cin >> num;
	int startnum, endnum;
	for (int i = 0; i < num; i++) {
		scanf_s("%1d", &startnum);
		dp[i + 1][0] = startnum;
	}
	for (int i = 0; i < num; i++) {
		scanf_s("%1d", &endnum);
		dp[i + 1][1] = endnum;
	}
	
	


	return 0;
}