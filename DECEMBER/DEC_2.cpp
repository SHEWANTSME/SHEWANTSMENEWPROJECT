#include<iostream>
#include <bitset>
#include <string>
#define endl "\n"
using namespace std;
int C[100000];
int main() {
	union ShareData {
		unsigned char a;
		unsigned short b;
		unsigned int c;
	};
	ShareData var;
	var.c = 0x12345678;
	cout << hex; // 얘가 있어야 10진수로 나옴
	cout << var.a << endl;
	cout << var.b << endl;
	cout << var.c << endl;

	int arr[5] = { 9,3,2,5,1 };
	cout << arr[0] << " " << arr[1] << endl;
	cout << arr << endl; // arr = &arr[0]
	cout << &arr[0] << endl;
	cout << *arr << endl; // dereferencing -> *arr = *(&arr[0])이니까 arr[0]

	return 0;
}

 A&B for (int i = 0; i < len; i++){ c[i] = a[i] == 1 && b[i] == 1 ? 1 : 0; } 
 A|B for (int i = 0; i < len; i++) { c[i] = a[i] == 1 || b[i] == 1 ? 1 : 0; } 
 A^B for (int i = 0; i < len; i++) { c[i] = a[i] != b[i] ? 1 : 0; } 
 ~A for (int i = 0; i < len; i++) { c[i] = a[i] == 1 ? 0 : 1; }
 ~B for (int i = 0; i < len; i++) { c[i] = b[i] == 1 ? 0 : 1; }
#include <iostream>
#include<algorithm>
using namespace std;
int stair[302];
int dp[302];
int maxx;
int maxxx;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0], stair[1]) + stair[2];
	int tele = std::max({ dp[0],dp[1],dp[2],dp[3] });
	return 0;
}