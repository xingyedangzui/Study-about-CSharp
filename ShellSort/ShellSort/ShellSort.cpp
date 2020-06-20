/*
* ���������㷨
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

//�������ܣ�ֱ�Ӳ����㷨����������
//����������������㣬�����յ�
void dinsert_sort(const int start, const int end) {
	for (int i = start + 1; i <= end; ++i) {
		if (numbers[i] < numbers[i - 1]) {
			int temp = numbers[i];
			int j = i - 1;
			do {    //�����ƶ���Ѱ�Ҳ���λ��
				numbers[j + 1] = numbers[j];
				--j;
			} while (j >= start && numbers[j] > temp);
			numbers[j + 1] = temp;  //����Ԫ��
		}
	}
}

//�������ܣ��۰�����㷨����������
//����������������㣬�����յ�
void binsert_sort(const int start, const int end) {
	int low = 0, high = 0, middle = 0;
	for (int i = start + 1; i <= end; ++i) {
		int temp = numbers[i];
		low = start;
		high = i - 1;
		while (low <= high) {   //�۰�����Ѱ�Ҳ���λ��
			middle = (low + high) / 2;
			if (numbers[middle] > temp) {
				high = middle - 1;  //��λ��ǰ�벿��
			}
			else {
				low = middle + 1;   //��λ����벿��
			}
		}
		for (int k = i - 1; k >= low; --k) {
			numbers[k + 1] = numbers[k];    //�ɿ��ƶ����ճ�����λ��
		}
		numbers[low] = temp;    //����Ԫ��
	}
}

//�������ܣ�ϣ�������㷨�����ֵ�������
//����������������㣬�����յ�
void shell_sort(const int start, const int end) {
	int increment = end - start + 1;    //��ʼ����������
	int temp{ 0 };
	do {    //ÿ�μ�С������ֱ��increment = 1
		increment = increment / 3 + 1;
		for (int i = start + increment; i <= end; ++i) {    //��ÿ�����ֽ���ֱ�Ӳ�������
			if (numbers[i - increment] > numbers[i]) {
				temp = numbers[i];
				int j = i - increment;
				do {    //�ƶ�Ԫ�ز�Ѱ��λ��
					numbers[j + increment] = numbers[j];
					j -= increment;
				} while (j >= start && numbers[j] > temp);
				numbers[j + increment] = temp;  //����Ԫ��
			}
		}
	} while (increment > 1);
}

//�������ܣ��������amount��start����end�ڵ������������ָ������
//�����������������Χ��㣬�������Χ�յ㣬�������������
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

	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl;
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

	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl;
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

	cout << "��ǰ�����㷨����ʱ��Ϊ��" << difftime(c_end, c_start) << "ms" << endl;
	for (auto iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
		cout << *iter << " ";
	}

	system("pause");
	return 0;
}