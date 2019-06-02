#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int>&);
void HeapSort(vector<int>&);

int main() {
	vector<int> nums;
	int num;

	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}

	HeapSort(nums);
	Print(nums);
}

inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void Print(vector<int>& nums) {
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
}

// 存储堆元素的数组下标从0开始时，对于数组中下标为i的元素，及第i + 1个元素：
// LeftChild(i) = 2*i + 1
// RightChild(i) = 2*i + 2
// Parent(i) = (i - 1) / 2

/* 自上而下地维护最大堆性质 */
void SiftDown(vector<int>& nums, int current, int end) {
	int child = 2 * current + 1;	// 当前节点的左儿子
	if (child > end) return;	    // 当前节点无子节点

	int value = nums[current];	// 保存当前节点的值
	while (child <= end) {
		if (child < end && nums[child] < nums[child + 1]) {
			child++;	// 找到较大的子节点
		}

		if (value > nums[child]) {
			break;		// 父节点的值大于两个子节点的值,无需调整
		}
		else {
			nums[current] = nums[child];
			current = child;
			child = 2 * current + 1;
		}
	}
	nums[current] = value;		// 当预先保存的值插入到堆中
}

void HeapSort(vector<int>& nums) {
	if (nums.size() < 2) return;

	/* 建立最大堆 */
	for (int i = nums.size() / 2 - 1; i >= 0; i--) {
		SiftDown(nums, i, nums.size() - 1);	// 从最后一个非叶节点开始，依次对每一个非叶节点维护最大堆性质
	}
	//Print(nums);

	/* 从后往前，依次将每一个元素与未排序的元素中的最大元素进行交换，然后维护最大堆性质，直至完成整个数组的排序*/
	for (int i = nums.size() - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		SiftDown(nums, 0, i - 1);
	}
}