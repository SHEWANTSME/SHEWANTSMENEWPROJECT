#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void Selection( int v[], int size) {
	int min = 0;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (v[j] < v[min]) min = j;

		}
		swap(v[i],v[min]);
	}
}
void quick(int v[], int start, int end) { // �����غ��ϱ� ���Ҹ� ������ ������ �ʿ䰡 ���°�,, ������ �ε����� �������� ����� ���� ������
	// ���� �򰥷��� ���Ҹ� �����ؾ߰ڴ� ������ �׋� ���� ���Ҹ� ����ȭ ��Ű�� �ɵ�!
	//int pivot = v[size]; // �ǹ��� ���Ұ��� �ƴ϶� �ε����� �ؾ���! 
	int pivot = end;
	int right = end;
	int left = start;
	
	//int left = v[start]; // �̷� �ʿ䰡 ���ٰ��
	//int right = v[end];
	//int starts = start; // �ϴ� �н�
	/*    for�� �������� ������ Ư�� �������� Ŀ���鼭 ���� ������ �Ǿ�� �ϴµ�
	�� ���� �װ� �ƴϰ� left�� right���� Ŭ�� ������ �ݺ��ϸ�
	�� �� �ȿ��� �ٸ� ������ �ִ°��ڳ�, ,�̷����� while�� ����*/
	if (right > left) {
		while (left < right) {
			while (v[left] < v[pivot] && left < right) left++;
			while (v[right] > v[pivot] && right > left) right--;
			//	swap(v[left], v[right]);
			if (left > right) swap(v[right], v[pivot]);
			else swap(v[left], v[right]);
		}
		quick(v, start, right - 1);
		quick(v, right + 1, end);
	}
	//for (int i = starts ; i < size; i++) {                       �ϴ� �н�
	//	if (left < pivot&& start<=end) start++;
	//	if (right >= pivot&& start <=end) end--;
	//}
	//if (start == end) swap(v[start], pivot);
	//swap(v[start], v[end]);
	//quick(v, start, end - 1, );
	//quick(v,end+1,)


}
int buffer[10];
void mergesort(int v[],  int start, int end) {
	int mid = 0;
	if (start < end) {
		mid = (start + end) / 2;
		mergesort(v,  start, mid);
		mergesort(v, mid + 1, end);
		merge(v,  start, mid, end);

	}
}
void merge(int v[], int start,int mid, int end) {// �߰��迭 need. buffer�� �غ��� , �߰������� ���� �迭 divide�ϱ� mid�� �־��ְ�
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (v[i] <= v[j]) { buffer[k] = v[i]; i++; }
		else { buffer[k] = v[j]; j++; }
		k++;
	}
	if (i > mid) {
		for (int m = j; m <= end; m++) {
			buffer[k] = v[m];
			k++;
		}
	}
	else {
		for (int n = i; n <= mid; n++) {
			buffer[k] = v[n];
			k++;
		}
	}

}
void printarray(const int v[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
}
int main() {
	int value[10] = { 9,2,6,3,8,7,4,5,1,0 };
	Selection(value, 10);
	printarray(value, 10);// �̰� ������ value�� for ������ ������, ���ĵȾַ� ����,, ��� �ٽ� ���󺹱� ��Ű���..?
	int value2[10] = { 9,2,6,3,8,7,4,5,1,0 };
//	quick(value2, 0, 10);
	//printarray(value2, 10);
	// ���� �� �ȵǴ°ž� �Ѥ��� ���Ȱ����� �Ѥ�
	

	int value3[10] = { 9,2,6,3,8,7,4,5,1,0 };
	//int buffer[10];
	mergesort(value3, 0, 10);
	printarray(value3, 10);
	// �� ���� ������ �Ѥ���
	int value4[10] = { 9,2,6,3,8,7,4,5,1,0 };



	



}