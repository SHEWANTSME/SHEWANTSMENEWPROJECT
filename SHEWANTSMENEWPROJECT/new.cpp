#include"pch.h"
#include <iostream>
using namespace std;

int main() {

	int a,i, sum = 0;
	cin >> a;
	cout << "1";
	for (i = 2; i < a; i++) {
		if (a%i == 0) {
			sum = sum + i;
			
			cout <<  " + "<<i; }
		}
	cout <<" = " << sum+1;
	return 0;
}