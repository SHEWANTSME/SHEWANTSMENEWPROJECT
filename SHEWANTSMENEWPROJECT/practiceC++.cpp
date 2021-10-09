#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	int array[] = {0,3,2,4,5,6,7,9,8};
	cout << sizeof(array) << endl;
	//return 0; // int가 4byte니까 4*9 = 36이지
	cout << sizeof(array[0]) << endl;



}