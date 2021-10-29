#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector <int>v(10000);
int cnt = 0;
void push(int n) {
	v[cnt] = n;
	cnt++;
}
void pop() {
	if (cnt ==0) cout << "-1" << "\n";
	else {
		cout << v[cnt-1] << "\n";
		cnt--;
	}
}
void empty() {
	
	if (cnt == 0) cout << "1" << endl;
	else cout << 0 << endl;
}
void top() {
	if (cnt == 0) cout << "-1" << endl;
	else	cout << v[cnt-1] << endl;
	
}
void size() {
	cout << cnt << endl;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		string s;
		cin >> s;
		if (s == "push") {
			int ss;
			cin >> ss;
			push(ss);
		}
		else if (s == "pop") {
			pop();
		}
		else if (s == "empty") {
			empty();
		}
		else if (s == "top") {
			top();
		}
		else if (s == "size") {
			size();
		}
		n--;
	}






	return 0;
}