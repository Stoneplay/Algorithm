#include<iostream>
#include<vector>

using namespace std;

void BubbleSort1(vector<int>& nums);
void BubbleSort2(vector<int>& nums);
void BubbleSort3(vector<int>& nums);

int main() {
	vector<int> nums1;

	cout << "Please input the sequence : " << endl;
	int num;
	while (cin >> num) {
		nums1.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}
	vector<int> nums2(nums1);
	vector<int> nums3(nums1);

	BubbleSort1(nums1);
	cout << '\n' << "Bubble sort 1 : ";
	for (size_t i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << ' ';
	}
	cout << endl;

	BubbleSort2(nums2);
	cout << "Bubble sort 2 : ";
	for (size_t i = 0; i < nums2.size(); i++) {
		cout << nums2[i] << ' ';
	}
	cout << endl;

	BubbleSort3(nums3);
	cout << "Bubble sort 3 : ";
	for (size_t i = 0; i < nums3.size(); i++) {
		cout << nums3[i] << ' ';
	}
	cout << endl;
	

	return 0;
}

void BubbleSort1(vector<int>& nums) {
	if (nums.size() < 2) return;

	for (size_t i = 0; i < nums.size(); i++) {
		for (size_t j = 0; j < nums.size() -1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
}

// 在某一次遍历过程中,未发生任何交换,则数组已经有序
void BubbleSort2(vector<int>& nums) {
	if (nums.size() < 2) return;
	
	bool isChange = true;
	int end = nums.size() - 1;	// 每次遍历结束的位置
	while (isChange) {
		isChange = false;	// 每次遍历开始前还未发生交换

		for (int i = 0; i < end; i++) {
			if (nums[i] > nums[i + 1]) {
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;

				isChange = true;
			}
		}
		end--;	// 末尾元素已经有序,无需遍历
	}
}

// 记录上一次遍历过程中最后一次发生元素交换的位置,该位置之后的元素一定是有序的,下一次遍历只需遍历该位置即可
void BubbleSort3(vector<int>& nums) {
	if (nums.size() < 2) return;

	int pos = nums.size() - 2;	
	while (pos > 0) {
		int end = pos;
		pos = 0;	// 清除上一次的记录,以防某次遍历未发生交换,则应结束遍历,而不是保留了上一次的记录
		for (int i = 0; i <= end; i++) {
			if (nums[i] > nums[i + 1]) {
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;

				pos = i;
			}
		}
	}
}