#include"pch.h"
#include <iostream>
using namespace std;

int main() {

	int number,i,tember;
	int min = 1000, max = -1000; // max�� ��������, min�� Ŭ ���ڷ� �ؾ� 

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
//�̹������� �����غ��� �׷��� ���� �صѰ��� ���°�,, ���� ���׵��� �迭 ���� �����Ѵ����� min max ã�°Ծƴ϶�
//�׳�  5 2 3 1 6   �̷���,, 5 �� min�� �ǰ� 