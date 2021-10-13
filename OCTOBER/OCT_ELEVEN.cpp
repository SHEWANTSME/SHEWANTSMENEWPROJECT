#include<iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}


int main() {



	//항상 이거 써주는거 잊지말기. 너가 c++을 배우는 이유는 just for test
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//이거 세개를 써줘야 가장 빠르게 입출력할수있음
	int a;
	cin >> a;
	int  b;
	int delta[1000000];
	for (int i = 0; i < a; i++) {
		cin >> b;
		delta[i] = b;
		
	}
	qsort(delta, a,sizeof(delta[0]),compare);
	cout << delta[0] << " " << delta[a - 1] << "\n";
	return 0;

}



