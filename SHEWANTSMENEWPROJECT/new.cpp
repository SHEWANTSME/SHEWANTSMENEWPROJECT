#include"pch.h"
#include <iostream>
using namespace std;

int main() {

	int number,i,tember;
	int min = 1000, max = -1000; // max를 작은숫자, min을 클 숫자로 해야 

	cin >> number;

	for (i = 1; i < number + 1; i++) {
		cin >> tember;
		//if (i == 1) min = tember;
		 if (tember < min) min=tember;
		 if (tember > max) max=tember;
	
			}
	cout << max - min << endl;
	
	return 0;
}
//이번문제는 생각해보니 그렇게 많이 해둘것이 없는게,, 굳이 쟤네들을 배열 만들어서 정렬한다음에 min max 찾는게아니라
//그냥  5 2 3 1 6   이러면,, 5 가 min이 되고 