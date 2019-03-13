#include<iostream>
#include<vector>

using namespace std;

void InsertionSort(vector<int>& nums);

int main() {
	vector<int> nums;

	cout << "Please input the sequence : " << endl;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	InsertionSort(nums);
	cout << '\n' << "Insertion sort : ";
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;

	return 0;
}

void InsertionSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	for (size_t i = 1; i < nums.size(); i++) {
		int key = nums[i];	// δ��������ĵ�һ��λ��,��������Ԫ��;��λ����Ԫ�غ��ƵĹ����лᱻ����,�����ȱ���
		int j = i - 1;		// ��������������һ��λ��

		while (j >= 0 && nums[j] > key) {	// �Ӻ���ǰ���Ҳ���λ��
			nums[j + 1] = nums[j];	// ����key��Ԫ�غ���
			j--;	// ��ǰ���Ҳ���λ�� 
		}
		nums[j + 1] = key;	// ���������Ԫ��
	}
}