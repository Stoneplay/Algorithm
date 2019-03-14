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

/* 交换两个元素的值 */
void exchange(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void QSort(vector<int>& nums, int left, int right) {
	if (left < right) {

		/* 随机产生一个主元,防止出现快排的最坏情况 */
		srand((unsigned int)time(0));	// 随机数种子
		int idx = rand() % (right - left + 1) + left;	// 产生一个随机下标
		exchange(nums[idx], nums[right]);

		/* 快速排序 */
		int i = left - 1;	// 小于主元元素的区域
		for (int j = left; j < right; j++) {
			if (nums[j] <= nums[right]) {
				exchange(nums[++i], nums[j]);	// 将nums[j]放到小于主元的区域
			}
		}
		exchange(nums[++i], nums[right]);		// 将主元放在大于主元元素区域的第一个位置

		QSort(nums, left, i - 1);	// 主元的位置为i
		QSort(nums, i + 1, right);
	}
}

void QuickSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	QSort(nums, 0, nums.size() - 1);
}