#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int A, B, C;                       //��������3�˵ķ��������Աȳ���С�Ϳ���
	int W_A, W_B, W_C;              //��¼ÿ����˵�Ļ�
	for (A = 0; A < 3; A++) {
		for (B = 0; B < 3; B++) {
			for (C = 0; C < 3; C++) {
				W_A = (B > A) + (C == A);
				W_B = (A > B) + (C < A);
				W_C = (C > B) + (B > A);
				//��Ϊ"��������ȷ���Եĸ����Ƿ���Ĺ�ϵ"
				if (A<B&&B<C && W_A>W_B&&W_B>W_C) {
					cout << "A<B<C" << endl;
				}
				if (A<C&&C<B && W_A>W_C&&W_C>W_B) {
					cout << "A<C<B" << endl;
				}
				if (B<A&&A<C && W_B>W_A&&W_A>W_C) {
					cout << "B<A<C" << endl;
				}
				if (B<C&&C<A && W_B>W_C&&W_C>W_A) {
					cout << "B<C<A" << endl;
				}
				if (C<B&&B<A && W_C>W_B&&W_B>W_A) {
					cout << "C<B<A" << endl;
				}
				if (C<A&&A<B && W_C>W_A&&W_A>W_B) {
					cout << "C<A<B" << endl;
				}
			}
		}
	}
	return 0;
}
