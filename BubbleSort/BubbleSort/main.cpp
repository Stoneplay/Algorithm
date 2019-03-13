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

// ��ĳһ�α���������,δ�����κν���,�������Ѿ�����
void BubbleSort2(vector<int>& nums) {
	if (nums.size() < 2) return;
	
	bool isChange = true;
	int end = nums.size() - 1;	// ÿ�α���������λ��
	while (isChange) {
		isChange = false;	// ÿ�α�����ʼǰ��δ��������

		for (int i = 0; i < end; i++) {
			if (nums[i] > nums[i + 1]) {
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;

				isChange = true;
			}
		}
		end--;	// ĩβԪ���Ѿ�����,�������
	}
}

// ��¼��һ�α������������һ�η���Ԫ�ؽ�����λ��,��λ��֮���Ԫ��һ���������,��һ�α���ֻ�������λ�ü���
void BubbleSort3(vector<int>& nums) {
	if (nums.size() < 2) return;

	int pos = nums.size() - 2;	
	while (pos > 0) {
		int end = pos;
		pos = 0;	// �����һ�εļ�¼,�Է�ĳ�α���δ��������,��Ӧ��������,�����Ǳ�������һ�εļ�¼
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