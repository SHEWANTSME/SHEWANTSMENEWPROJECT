#include <iostream>
#include <bitset>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n,numeric[1000],cnt=0;
//	int n;
	cin >> n; //n이 216이라 치자

/*	while (n != 0) {
		n % 10; // n을 10으로 나눈 나머지 
	//	cout << n % 10 << endl;
		numeric[cnt] = n % 10; // 이렇게 하면 numeric[2]=2 [1]=1 [0]=6
		cnt++;

		n = n / 10;
	}*/

	int t;
	int add = 0;
	for (int i = 1; i < 1000; i++) {
		t = i;
		if (t == 999) cout << 0 << endl;
		while (t != 0) {
			numeric[cnt] = t % 10;
			add = numeric[cnt] + add;
			cnt++;

			t = t / 10;
		}
		cnt = 0;
	//	cout << add << endl;
		if ((add + i) == n) {		
		
			cout << i << endl;
			break;
		}
		if ((add + i) != n) {
			add = 0;
		}
		
		//	else cout << 0 << endl;
	//	add = 0;
	}
//	cout << 0 << endl;




//	cout << cnt << endl;
	//int c = n;
    

	return 0;
}