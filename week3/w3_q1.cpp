#include<iostream>
#include<algorithm>

using namespace std;

struct list {
	int number;
	int index;
};

bool compare(list& s1, list& s2) {
	return s1.number > s2.number;
}

int main() {
	int arraySize, index;
	list L[100000];

	cin >> arraySize;
	for (index = 0; index < arraySize; index++) {
		cin >> L[index].number;
		L[index].index = index;
	}

	int len = index;

	if (len == 3) {
		cout << L[0].number + L[2].number;
	}
	else {
		sort(L, L + len, compare);
		int tmp, max = -INT16_MAX;
		for (index = 0; index < 1000; index++) {
			for (int i = index + 1; i < 1000; i++) {
				if (abs(L[index].index - L[i].index) > 1) {
					tmp = L[index].number + L[i].number;
					if (tmp > max) {
						max = tmp;
					}
				}
			}
		}	
		cout << max;
	}
	return 0;
}
