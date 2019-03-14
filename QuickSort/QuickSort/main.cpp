#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

void exchange(int& a, int& b);
void QSort(vector<int>& nums, int left, int right);
void QuickSort(vector<int>& nums);

int main() {
	vector<int> nums;

	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	QuickSort(nums);
	cout << '\n' << "Quick sort : ";
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;

	return 0;
}

/* ��������Ԫ�ص�ֵ */
void exchange(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void QSort(vector<int>& nums, int left, int right) {
	if (left < right) {

		/* �������һ����Ԫ,��ֹ���ֿ��ŵ����� */
		srand((unsigned int)time(0));	// ���������
		int idx = rand() % (right - left + 1) + left;	// ����һ������±�
		exchange(nums[idx], nums[right]);

		/* �������� */
		int i = left - 1;	// С����ԪԪ�ص�����
		for (int j = left; j < right; j++) {
			if (nums[j] <= nums[right]) {
				exchange(nums[++i], nums[j]);	// ��nums[j]�ŵ�С����Ԫ������
			}
		}
		exchange(nums[++i], nums[right]);		// ����Ԫ���ڴ�����ԪԪ������ĵ�һ��λ��

		QSort(nums, left, i - 1);	// ��Ԫ��λ��Ϊi
		QSort(nums, i + 1, right);
	}
}

void QuickSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	QSort(nums, 0, nums.size() - 1);
}