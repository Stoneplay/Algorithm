#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int> nums, int target);
int BinarySearch_first(vector<int> nums, int target);
int BinarySearch_last(vector<int> nums, int target);
int BinarySearch_count(vector<int> nums, int target);

int main() {
	vector<int> nums;
	int target;

	cout << "Please input a array in ascending order : " << endl;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') {
			break;
		}
	}
	cout << "The number you want to search : " << endl;
	cin >> target;

	cout << "\nThe arbitrary position of target : " << BinarySearch(nums, target) << endl;
	cout << "The first position of target : " << BinarySearch_first(nums, target) << endl;
	cout << "The last position of target : " << BinarySearch_last(nums, target) << endl;
	cout << "The quantity of target : " << BinarySearch_count(nums, target) << endl;

	return 0;
}

/* 查找某个数的下标(多个元素重复时返回任意一个元素的下标) */
int BinarySearch(vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);
	
	while (low <= high) {
		mid = low + ((high - low) >> 1);
		if (nums[mid] == target) {
			return mid;
		}
		else if(nums[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}

/* 查找某个数的下标(多个元素重复时返回第一个元素的下标) */
/* 等价于查找大于等于某个数的第一个下标 */
int BinarySearch_first(vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);

	while (low < high) {	// low == high时停止查找
		mid = low + ((high - low) >> 1);
		/* 由于数组有序，可将第一个等于target的元素视为小于等于target的元素 */
		if (nums[mid] >= target) {	// 去掉等号则查找大于某个数的第一个下标
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	if (nums[low] == target) {
		return low;
	}
	else {
		return -1;
	}
}

/* 查找某个数的下标(多个元素重复时返回最后一个元素的下标) */
/* 等价于查找小于等于某个数的最后一个下标 */
int BinarySearch_last (vector<int> nums, int target) {
	int low = 0, high = nums.size() - 1;
	int mid = low + ((high - low) >> 1);

	// low + 1 == high时停止查找:当查找区间只剩两个元素时,我们的目标应是右边界，
	// 但由于整数除法会向下取整，则再计算mid得出的结果是左边界，故应停止计算mid，转而单独对最后两个元素进行判断
	while (low + 1 < high) {	
		mid = low + ((high - low) >> 1);
		/* 由于数组有序，可将最后一个等于target的元素视为大于等于target的元素 */
		if (nums[mid] > target) {	
			high = mid - 1;
		}
		else {	// 去掉等号则查找小于某个数的最后一个下标
			low = mid;
		}
	}

	if (nums[high] == target) {
		return high;
	}
	else if (nums[low] == target) {
		return low;
	}
	else {
		return -1;
	}
}

/* 查找数组中某个数出现的次数 */
int BinarySearch_count(vector<int> nums, int target) {
	int first = BinarySearch_first(nums, target);
	int last = BinarySearch_last(nums, target);

	if (first == -1) {
		return 0;
	}
	else {
		return last - first + 1;
	}
}