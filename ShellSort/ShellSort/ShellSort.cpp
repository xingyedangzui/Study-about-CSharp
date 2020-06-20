/*
* 插入排序算法
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

//vector<int> numbers{3, 2, 4, 6, 1, 9, 5, 8, 7, 10};
//vector<int> numbers{72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
//vector<int> numbers{21, 25, 49, 25, 16, 8};
vector<int> numbers;

//函数功能，直接插入算法对数字排序
//函数参数，数列起点，数列终点
void dinsert_sort(const int start, const int end) {
	for (int i = start + 1; i <= end; ++i) {
		if (numbers[i] < numbers[i - 1]) {
			int temp = numbers[i];
			int j = i - 1;
			do {    //依次移动并寻找插入位置
				numbers[j + 1] = numbers[j];
				--j;
			} while (j >= start && numbers[j] > temp);
			numbers[j + 1] = temp;  //插入元素
		}
	}
}

//函数功能，折半插入算法对数字排序
//函数参数，数列起点，数列终点
void binsert_sort(const int start, const int end) {
	int low = 0, high = 0, middle = 0;
	for (int i = start + 1; i <= end; ++i) {
		int temp = numbers[i];
		low = start;
		high = i - 1;
		while (low <= high) {   //折半搜索寻找插入位置
			middle = (low + high) / 2;
			if (numbers[middle] > temp) {
				high = middle - 1;  //定位到前半部分
			}
			else {
				low = middle + 1;   //定位到后半部分
			}
		}
		for (int k = i - 1; k >= low; --k) {
			numbers[k + 1] = numbers[k];    //成块移动，空出插入位置
		}
		numbers[low] = temp;    //插入元素
	}
}

//函数功能，希尔排序算法对数字递增排序
//函数参数，数列起点，数列终点
void shell_sort(const int start, const int end) {
	int increment = end - start + 1;    //初始化划分增量
	int temp{ 0 };
	do {    //每次减小增量，直到increment = 1
		increment = increment / 3 + 1;
		for (int i = start + increment; i <= end; ++i) {    //对每个划分进行直接插入排序
			if (numbers[i - increment] > numbers[i]) {
				temp = numbers[i];
				int j = i - increment;
				do {    //移动元素并寻找位置
					numbers[j + increment] = numbers[j];
					j -= increment;
				} while (j >= start && numbers[j] > temp);
				numbers[j + increment] = temp;  //插入元素
			}
		}
	} while (increment > 1);
}

//函数功能，随机产生amount个start——end内的随机数并存入指定容器
//函数参数，随机数范围起点，随机数范围终点，随机数生成数量
void produceRandomNumbers(const int start, const int end, const int amount) {
	srand((unsigned)time(NULL));
	for (int cnt = 1; cnt <= amount; ++cnt) {
		numbers.push_back(start + (rand() % (end - start)));
	}
}


int main()
{
	time_t c_start, c_end;
	produceRandomNumbers(1, 1000, 1000);

	c_start = clock();
	dinsert_sort(0, 999);
	c_end = clock();

	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl;
	for (auto iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		cout << *iter << " ";
	}

	cout << endl;
	cout << endl;

	numbers.clear();
	produceRandomNumbers(1, 1000, 1000);

	c_start = clock();
	binsert_sort(0, 999);
	c_end = clock();

	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl;
	for (auto iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		cout << *iter << " ";
	}

	cout << endl;
	cout << endl;

	numbers.clear();
	produceRandomNumbers(1, 1000, 1000);

	c_start = clock();
	shell_sort(0, 999);
	c_end = clock();

	cout << "当前排序算法花费时间为：" << difftime(c_end, c_start) << "ms" << endl;
	for (auto iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		cout << *iter << " ";
	}

	system("pause");
	return 0;
}