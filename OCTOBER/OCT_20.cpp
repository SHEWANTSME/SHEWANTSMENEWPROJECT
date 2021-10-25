#include <iostream>
using namespace std;

int newarr[8];// 정렬 배열은 반드시 전역변수,,
void merge(int a[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) { newarr[k] = a[i]; i++; } 
		else { newarr[k] = a[j]; j++; }
		k++;
	}
	//remained data input
	if (i > mid) {
		for (int t = j; t <= right; t++) {
			newarr[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			newarr[k] = a[t];
			k++;
		}
	}
	for (int i = left; i <= right; i++) {
		a[i] = newarr[i];
	}
}
void mergesort(int a[], int left, int right) {
	if (right > left) {
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}





void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap2(int &aa, int &bb) {
	int temp = aa;
	aa = bb;
	bb = temp;
}
int main() {
	/*int array[] = { 7,6,5,8,3,5,9,1 };
	mergesort(array, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	*/
	int a = 3; int b = 4;
	swap(&a, &b);
	cout << "a" << a << "b" << b << endl;
	swap2(a, b);
	cout << "a" << a << "b" << b << endl;



}