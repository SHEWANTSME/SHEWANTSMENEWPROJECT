#include<iostream>
#include <algorithm>
using namespace std;

int sum(int alpha[] , int beta) {

	for (int j = 0; j < beta-1; j++) {
		alpha[j+1] = alpha[j] + alpha[j + 1];
	}
	return alpha[beta];

}

int get_max(int) {

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int number;
	cin >> number;
	int matrix[1000] = { 0, };
   int k, cnt = 0;
   while (number != 0) {
	   cin >> k;
	   matrix[cnt] = k;
	   cnt++;
	   number--;
   }
   // 1. �� ����
   //2. ���ӵ� �ΰ��� ������
   //3 ���ӵ� 3���� ��
   // 4 ���ӵ� 4���� ��
   // ... ���ӵ� n���� ��
   // �߿��� ���� ū���� return �ϸ� ��
   int large = matrix[0];
  // matrix[0] = large;
   // �� ������ �ִ�
   for (int i = 1; i < cnt; i++) {
	   large = max(large, matrix[i]);
   }
   //2. ���ӵ� �ΰ��� ������
   int large2;
   for (int i = 1; i < cnt-1; i++) {
	   large2 = max(matrix[i] + matrix[i + 1], matrix[0] + matrix[1]);
   }
     // 3. ���ӵ� 3���� ���� ��
   int large3;
   for (int i = 2; i < cnt - 2; i++) {
	   large3 = max(matrix[0] + matrix[1] + matrix[2], matrix[i ] + matrix[i+1] + matrix[i + 2]);
   }
// ���ӵ� n��
 //  int big[100000];

   int newcnt = cnt;
   int m[1000] = { 0, };
   int a = 1;
 /*  while (newcnt != 0) {
	   for (int i = n; i < cnt - n; i++) {
		   m[i] = max(sum(matrix, n), sum(matrix, i));
	}
   }*/
 //  for(int k=)











	return 0;
}