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
   // 1. 각 원소
   //2. 연속된 두개의 원소합
   //3 연속된 3개의 합
   // 4 연속된 4개의 합
   // ... 연속된 n개의 합
   // 중에서 가장 큰값을 return 하면 됨
   int large = matrix[0];
  // matrix[0] = large;
   // 각 원소중 최댓값
   for (int i = 1; i < cnt; i++) {
	   large = max(large, matrix[i]);
   }
   //2. 연속된 두개의 원소합
   int large2;
   for (int i = 1; i < cnt-1; i++) {
	   large2 = max(matrix[i] + matrix[i + 1], matrix[0] + matrix[1]);
   }
     // 3. 연속된 3개의 원소 합
   int large3;
   for (int i = 2; i < cnt - 2; i++) {
	   large3 = max(matrix[0] + matrix[1] + matrix[2], matrix[i ] + matrix[i+1] + matrix[i + 2]);
   }
// 연속된 n개
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