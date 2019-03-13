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
		int key = nums[i];	// 未排序区域的第一个位置,即待插入元素;该位置在元素后移的过程中会被覆盖,故需先保存
		int j = i - 1;		// 已排序区域的最后一个位置

		while (j >= 0 && nums[j] > key) {	// 从后向前查找插入位置
			nums[j + 1] = nums[j];	// 将比key的元素后移
			j--;	// 向前查找插入位置 
		}
		nums[j + 1] = key;	// 插入待排序元素
	}
}