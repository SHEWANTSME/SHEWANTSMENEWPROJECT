#include"pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
void do_sth(int x) {
	x = 123;
	cout << x << endl;
}
//int add(int x, int y);
int main() {
	int x(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t((x > 0) ? 1 : 2); // x가 0보다 크면 1 아니면 2 --> (조건) ?true : false 
//	printf("%d", t);
	cout<<add(3, 5)<<endl;
	ios_base::sync_with_stdio(false);
//	scanf_s("%d \n", &x);
	//printf_s("%d \n", x);
//	cout << x << endl;
	//do_sth(x);
	//cout << x << endl;
	return 0;

} 