#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp);
void Msort(vector<int>& nums, int left, int right, vector<int>& tmp);
void MergeSort(vector<int>& nums);

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

	MergeSort(nums);
	cout << '\n' << "Merge sort : ";
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;

	return 0;
}

/* �ϲ������������� */
void Merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp) {
	int i = left, j = mid + 1;

	while (i <= mid && j <= right) {
		if (nums[i] < nums[j]) {
			tmp.push_back(nums[i++]);
		}
		else {
			tmp.push_back(nums[j++]);
		}
	}

	while (i <= mid) {
		tmp.push_back(nums[i++]);
	}
	while (j <= right) {
		tmp.push_back(nums[j++]);
	}

	for (size_t i = 0; i < tmp.size(); i++) {
		nums[left + i] = tmp[i];	// ���������Ԫ�ظ���ԭ������δ�����Ԫ��
	}
	tmp.clear();	// ���tmp,������һ�κϲ�����
}

/* �������������Ϊ����������,�ֱ�������ٺϲ� */
void Msort(vector<int>& nums, int left, int right, vector<int>& tmp) {
	if (left < right) {
		int mid = left + ((right - left) >> 2);
		Msort(nums, left, mid, tmp);
		Msort(nums, mid + 1, right, tmp);
		Merge(nums, left, mid, right, tmp);
	}
}

void MergeSort(vector<int>& nums) {
	if (nums.size() < 2) return;
	
	vector<int> tmp;
	Msort(nums, 0, nums.size() - 1, tmp);
}