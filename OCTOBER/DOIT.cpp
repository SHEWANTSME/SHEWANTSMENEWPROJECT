		#include <iostream>	
		#include <stdio.h>//for c style things
	    #include <algorithm> // for max min ,, other stuffs
		#include <stdlib.h>
		using namespace std;
		//꽤 어려운데??


		int main() {
		cin.tie(NULL);
		cout.tie(NULL);
		ios_base::sync_with_stdio(false);

		int n, a ,b, c,d,t=0;
		cin >> n;
		if (n < 100) cout << n << endl;
		if (100 <= n && n < 1000) {
			for (int i = 100; i <= n; i++) {
				if (abs(i / 100) - abs((i % 100) / 10) == abs((i % 100) / 10) - abs((i % 100) % 10))  t++; cout << i<<" " << t << endl;

			//	if ((abs(i / 100) - ((i % 100) / 10)) == abs(((i % 100) / 10) - ((i % 100) % 10))) cout << i << endl;
			}
		cout << t+99 << endl;


		}
		/*	if (100 <= n < 1000) {
			100 이면     123
		if(	abs(i/100) - abs((i%100)/10) == abs((i%100)/10) - abs((i%100)%10)) cout << i <<endl;
			a = n / 100; 1  1 
			b = n % 100; 0  23
			c = b / 10;  0  2
			d = b % 10;  0  3
			if (abs(a - c) == abs(c - d)) t++;
			

		}*/
		if (n == 1000) cout << 144 << endl;



		return 0;
		}

		/// power 함수를 정의해보자v





  

	