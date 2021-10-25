//#include <iostream>
/*
using namespace std;

typedef int* pint;

void foo(pint ptr       /* 같은거임int *ptr*//*) {
	cout << *ptr << " " << ptr << " " << &ptr << endl;}*/
//template < typename/*혹은 class struct은 안됨*/ T>
/*T getmax(T x, T y) {
	return (x > y) ? x : y;
} */
/*
int main() {
	int value = 5;
	int *ptr = &value; 
	cout << &ptr << endl; // 001EFCE4
	foo(ptr);// 001EFC04 나옴 &ptr
	foo(&value);// 001EFC04 나옴 &ptr
//	foo(5); -> 이렇겐 안됨 
	// 포인터 변수도 변수이기 때문에 주소가 다름
	}
	*/
#include <iostream> 
using namespace std;
void swap(int *k, int *q) {
	int temp = *k;
	*k = *q;
	*q = temp;
}
void printarray(int a[], int size) {
	for (int beta = 0; beta < size; beta++) {
		cout << a[beta] << endl;
	}
}

void bubblesort(int arr[]) {//bubble sort -> 옆에있는놈과 비교해서 더 작은놈 앞으로/
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}
void insertionsort(int arr[]) { // 각 숫자를 적절한 위치에 삽입 when needed
	for (int i = 0; i < 9; i++) {
		int j = i;
		if (arr[j + 1] < arr[j]) {
			for (int k = 0; k < j+1; k++) {
				if (arr[k] > arr[j + 1]) swap(&arr[k], &arr[j + 1]);
			}	
		}	
	//	for (j = 0; j <= i; j++) cout << arr[j] << endl;
	}// 거의 정렬된 상태에선 굉장히 효율적
}
void insertionsort2(int arr[]) {
	for (int i = 0; i < 9; i++) {
		int j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			swap(&arr[j], &arr[j + 1]);
			j--;
		}
	//	for (j = 0; j <= i; j++) cout << arr[j] << endl;
	}
}
void selectionsort(int alpha[]) { //// smallest to the front 
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (alpha[i] > alpha[j]) swap(&alpha[i], &alpha[j]);
		}
	}

}
void quicksort(int *data, int left, int right) {
   // if (left >= right) return ; // 원소가 1개인 경우 // return;은 그냥 나가는거임 저 조건일때 void 탈출
	
	if (right > left) { // 그냥 이렇게 하면 되네,, 
		int pivot = left; // 1원소  = 피벗
		int i = left + 1;
		int j = right;
		while (i <= j) {
			while (data[i] <= data[pivot] && i < right) i++; // 피벗보다 큰값만날때 까지
			while (data[j] >= data[pivot] && j > left) j--; // 피벗보다 작은값 만날때 까지
			if (i > j) swap(data[j], data[pivot]);
			else swap(data[j], data[i]);
		}
		quicksort(data, left, j - 1); // 정해진 놈 왼쪽 정렬
		quicksort(data, j + 1, right); // 정해진놈 오른쪽 정렬
	}
}
void quicksort2(int*arr, int left, int right) {
	int pivot = arr[(left + right) / 2]; // 피벗 중앙값
	int right2 = right;
	int left2 = left;
	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (arr[right > pivot]) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	int index = left;
	if (left < index - 1) {
		quicksort2(arr, left2, left - 1);
	 	}
	quicksort2(arr, left + 1, right2);

}
int main() {
	int alpha[10];
	int beta[10];
	int ceta[10];
	int deta[10];
	int eeta[10];
	for (int i = 0; i < 10; i++) {
		cin >> alpha[i];
		beta[i] = alpha[i];
		ceta[i] = beta[i];
		deta[i] = ceta[i];
		eeta[i] = deta[i];
	}

	selectionsort(alpha);
	bubblesort(beta);
	insertionsort(ceta);
	insertionsort2(deta);
	quicksort(eeta, 0, 9);
	printarray(alpha, 10);
    printarray(beta,10);
    printarray(ceta, 10);
	printarray(eeta, 10);
}




















































