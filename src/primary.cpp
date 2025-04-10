#include "primary.h"
using namespace std;
void primary::addstu(int nums, primary Stu[101], int& index) {

	for (int i = 0; i < nums; i++)
	{
		cout << "请输入第" << i + 1 << "个课程名:";
		cin >> Stu[i].name;

		cout << "请输入第" << i + 1 << "个课程的老师:";
		cin >> Stu[i].sex;

		cout << "请输入第" << i + 1 << "个课程的学分:";
		cin >> Stu[i].class_info;

		cout << "请输入第" << i + 1 << "个课程的学时:";
		cin >> Stu[i].age;

		cout << "请输入第" << i + 1 << "个课程的课程号:";
		cin >> Stu[i].number;


	}
	index += nums;
}

void primary::search_by_name(string Name, primary stu[101],int index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].name == Name) {
			cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].sex << ' ' << stu[i].class_info << ' ';

		}
	}
}

void primary::search_by_num(int num, primary stu[101],int index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].number == num) {
			cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].sex << ' ' << stu[i].class_info << ' ';

		}
	}
}

void primary::output_list(primary stu[101], int amount) {
	ofstream dataFile;
	dataFile.open("dataFile.txt", ofstream::app);
	fstream file("dataFile.txt", ios::out);
	// 写入数据
	for (int i = 0; i < amount; i++) {
		dataFile <<"名称"<< "：" << stu[i].name << ' ' <<"学时：" << stu[i].age << ' '<< "老师：" << stu[i].sex << ' ' <<"学分：" << stu[i].class_info << ' ';
		
	}
	dataFile.close();
}

void primary::delete_stu(string target, primary stu[101], int& index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].name == target) {
			for (int j = i; j < index; j++) {
				stu[j] = stu[j + 1];
			}
		}
	}
	index--;
}



void primary::get_name() {
	cout << this->name;
}

void primary::show_all(primary stu[101], int index) {
	for (int i = 0; i < index; i++) {
		cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].sex << ' ' << stu[i].class_info << ' ';
	
		cout << endl;
	}
}

void primary::change_stu1(string name1, primary Stu[101], int index) {
	int temp;
	for (int i = 0; i < index; i++) {
		if (Stu[i].name == name1) {
			temp = i;
			break;
		}
	}
	cout << "请输入修改后课程名:";
	cin >> Stu[temp].name;

	cout << "请输入修改后课程的老师:";
	cin >> Stu[temp].sex;

	cout << "请输入修改后课程的学分:";
	cin >> Stu[temp].class_info;

	cout << "请输入修改后课程的学时:";
	cin >> Stu[temp].age;

	cout << "请输入修改后课程的课程号:";
	cin >> Stu[temp].number;

}

void primary::change_stu2(int target, primary Stu[101], int index) {
	int temp;
	for (int i = 0; i < index; i++) {
		if (Stu[i].number == target) {
			temp = i;
			break;
		}
	}
	cout << "请输入修改后课程名:";
	cin >> Stu[temp].name;

	cout << "请输入修改后课程的老师:";
	cin >> Stu[temp].sex;

	cout << "请输入修改后课程的学分:";
	cin >> Stu[temp].class_info;

	cout << "请输入修改后课程的学时:";
	cin >> Stu[temp].age;

	cout << "请输入修改后课程的课程号:";
	cin >> Stu[temp].number;

}
