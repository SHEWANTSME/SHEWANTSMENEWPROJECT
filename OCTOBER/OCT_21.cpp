#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	int ar[10000];
	for (int i = 0; i < num; i++) {
		cin >> ar[i];
	}
	int max = -1000;
	int cnt = 0;
	while (ar[num-1] >ar[num-2] && num>1) {
	//	max = cnt;
		cnt++;
		num--;

		cout << cnt << endl;
	}

}