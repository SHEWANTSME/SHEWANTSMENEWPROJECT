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
void quick(int v[], int start, int end) { // 생각해보니까 원소를 변수로 지정할 필요가 없는게,, 어차피 인덱스의 연산으로 충분히 생각 가능함
	// 만약 헷갈려서 원소를 정의해야겠다 싶으면 그떄 가서 원소를 변수화 시키면 될듯!
	//int pivot = v[size]; // 피벗을 원소값이 아니라 인덱스로 해야함! 
	int pivot = end;
	int right = end;
	int left = start;
	
	//int left = v[start]; // 이럴 필요가 없다고요
	//int right = v[end];
	//int starts = start; // 일단 패스
	/*    for로 돌리려면 변수가 특정 범위에서 커지면서 까지 실행이 되어야 하는데
	이 경우는 그게 아니고 left가 right보다 클때 무조건 반복하며
	또 그 안에서 다른 조건이 있는거자나, ,이럴때는 while이 편함*/
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
	//for (int i = starts ; i < size; i++) {                       일단 패스
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
void merge(int v[], int start,int mid, int end) {// 추가배열 need. buffer라 해보자 , 중간값으로 인해 배열 divide니까 mid도 넣어주고
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
	printarray(value, 10);// 이거 다음에 value를 for 돌려서 찍으면, 정렬된애로 나옴,, 어떻게 다시 원상복구 시키드라..?
	int value2[10] = { 9,2,6,3,8,7,4,5,1,0 };
//	quick(value2, 0, 10);
	//printarray(value2, 10);
	// ㅅㅂ 왜 안되는거야 ㅡㅅㅡ 개똑같은데 ㅡㅡ
	

	int value3[10] = { 9,2,6,3,8,7,4,5,1,0 };
	//int buffer[10];
	mergesort(value3, 0, 10);
	printarray(value3, 10);
	// 또 뭐가 문제야 ㅡㅅㅡ
	int value4[10] = { 9,2,6,3,8,7,4,5,1,0 };



	



}