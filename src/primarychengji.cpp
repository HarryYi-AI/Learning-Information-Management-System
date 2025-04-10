#include "primarychengji.h"
using namespace std;
void primarychengji::addstu(int nums, primarychengji Stu[101], int& index) {

	for (int i = 0; i < nums; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的姓名:";
		cin >> Stu[i].name;

		cout << "请输入第" << i + 1 << "个学生的性别:";
		cin >> Stu[i].sex;

		cout << "请输入第" << i + 1 << "个学生的专业:";
		cin >> Stu[i].class_info;

		cout << "请输入第" << i + 1 << "个学生的年级:";
		cin >> Stu[i].age;

		cout << "请输入第" << i + 1 << "个学生的学号:";
		cin >> Stu[i].number;

		cout << "请输入第" << i + 1 << "个学生的专业课成绩:";
		cin >> Stu[i].Chinese;

		cout << "请输入第" << i + 1 << "个学生的微积分成绩:";
		cin >> Stu[i].Math;

		cout << "请输入第" << i + 1 << "个学生的英语综合成绩:";
		cin >> Stu[i].English;

		Stu[i].Total = Stu[i].Chinese + Stu[i].Math + Stu[i].English;
	}
	index += nums;
}

void primarychengji::search_by_name(string Name, primarychengji stu[101],int index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].name == Name) {
			cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].sex << ' ' << stu[i].class_info << ' ';
			cout << stu[i].Chinese << ' ' << stu[i].Math << ' ' << stu[i].English << ' ' << stu[i].Total;
		}
	}
}

void primarychengji::search_by_num(int num, primarychengji stu[101],int index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].number == num) {
			cout << stu[i].name << ' ' << stu[i].age << ' ' << stu[i].sex << ' ' << stu[i].class_info << ' ';
			cout << stu[i].Chinese << ' ' << stu[i].Math << ' ' << stu[i].English << ' ' << stu[i].Total;
		}
	}
}

void primarychengji::output_list(primarychengji stu[101], int amount) {
	ofstream chengjidataFile;
	chengjidataFile.open("chengjidataFile.txt", ofstream::app);
	fstream file("chengjidataFile.txt", ios::out);
	// 写入数据
	for (int i = 0; i < amount; i++) {
		chengjidataFile << "姓名：" << stu[i].name << ' ' <<"年级：" << stu[i].age << ' '<< "性别：" << stu[i].sex << ' ' <<"专业：" << stu[i].class_info << ' ';
		chengjidataFile << "专业课分数：" << stu[i].Chinese << ' '<<"微积分分数：" << stu[i].Math << ' ' <<"英语综合分数：" << stu[i].English << ' '<<"总分：" << stu[i].Total;
		
	}
	chengjidataFile.close();
}

void primarychengji::delete_stu(string target, primarychengji stu[101], int& index) {
	for (int i = 0; i < index; i++) {
		if (stu[i].name == target) {
			for (int j = i; j < index; j++) {
				stu[j] = stu[j + 1];
			}
		}
	}
	index--;
}

float primarychengji::CHI_average(primarychengji stu[101], int index) {
	float result = 0;
	for (int i = 0; i < index; i++) {
		result += stu[i].Chinese;
	}
	return (result / index);
}

float primarychengji::MATH_average(primarychengji stu[101], int index) {
	float result = 0;
	for (int i = 0; i < index; i++) {
		result += stu[i].Math;
	}
	return (result / index);
}

float primarychengji::ENG_average(primarychengji stu[101], int index) {
	float result = 0;
	for (int i = 0; i < index; i++) {
		result += stu[i].English;
	}
	return (result / index);
}

void primarychengji::total_sorting(primarychengji stu[101], int index) {
	for (int i = 1; i < index; i++)
	{
		int j = i - 1;

		//插入数组中的数据
		primarychengji temp = stu[i];

		while (temp.Total > stu[j].Total && j >= 0)
		{
			stu[j + 1] = stu[j];

			j--;
		}

		stu[++j] = temp;
	}
}

void primarychengji::CHI_sorting(primarychengji stu[101], int index) {
	for (int i = 1; i < index; i++)
	{
		int j = i - 1;

		//插入数组中的数据
		primarychengji temp = stu[i];

		while (temp.Chinese > stu[j].Chinese && j >= 0)
		{
			stu[j + 1] = stu[j];

			j--;
		}

		stu[++j] = temp;
	}
}

void primarychengji::ENG_sorting(primarychengji stu[101], int index) {
	for (int i = 1; i < index; i++)
	{
		int j = i - 1;

		//插入数组中的数据
		primarychengji temp = stu[i];

		while (temp.English > stu[j].English && j >= 0)
		{
			stu[j + 1] = stu[j];

			j--;
		}

		stu[++j] = temp;
	}
}

void primarychengji::MATH_sorting(primarychengji stu[101], int index) {
	for (int i = 1; i < index; i++)
	{
		int j = i - 1;

		//插入数组中的数据
		primarychengji temp = stu[i];

		while (temp.Math > stu[j].Math && j >= 0)
		{
			stu[j + 1] = stu[j];

			j--;
		}

		stu[++j] = temp;
	}
}

void primarychengji::get_name() {
	cout << this->name;
}

void primarychengji::show_all(primarychengji stu[101], int index) {
	for (int i = 0; i < index; i++) {
		cout <<"姓名："<< stu[i].name << ' ' <<"年级："<< stu[i].age << ' ' <<"性别："<< stu[i].sex << ' ' <<"专业："<< stu[i].class_info << ' ';
		cout << "专业课成绩："<<stu[i].Chinese << ' ' <<"微积分成绩："<< stu[i].Math << ' ' << "英语："<<stu[i].English << ' '<<"总成绩：" << stu[i].Total;
		cout << endl;
	}
}

void primarychengji::change_stu1(string name1, primarychengji Stu[101], int index) {
	int temp;
	for (int i = 0; i < index; i++) {
		if (Stu[i].name == name1) {
			temp = i;
			break;
		}
	}
	cout << "请输入修改后学生的姓名:";
	cin >> Stu[temp].name;

	cout << "请输入修改后学生的性别:";
	cin >> Stu[temp].sex;

	cout << "请输入修改后学生的专业:";
	cin >> Stu[temp].class_info;

	cout << "请输入修改后学生的年级:";
	cin >> Stu[temp].age;

	cout << "请输入修改后学生的学号:";
	cin >> Stu[temp].number;

	cout << "请输入修改后学生的专业课成绩:";
	cin >> Stu[temp].Chinese;

	cout << "请输入修改后学生的微积分成绩:";
	cin >> Stu[temp].Math;

	cout << "请输入修改后学生的英语综合成绩:";
	cin >> Stu[temp].English;

	Stu[temp].Total = Stu[temp].Chinese + Stu[temp].Math + Stu[temp].English;
}

void primarychengji::change_stu2(int target, primarychengji Stu[101], int index) {
	int temp;
	for (int i = 0; i < index; i++) {
		if (Stu[i].number == target) {
			temp = i;
			break;
		}
	}
	cout << "请输入修改后学生的姓名:";
	cin >> Stu[temp].name;

	cout << "请输入修改后学生的性别:";
	cin >> Stu[temp].sex;

	cout << "请输入修改后学生的专业:";
	cin >> Stu[temp].class_info;

	cout << "请输入修改后学生的年级:";
	cin >> Stu[temp].age;

	cout << "请输入修改后学生的学号:";
	cin >> Stu[temp].number;

	cout << "请输入修改后学生的专业课成绩:";
	cin >> Stu[temp].Chinese;

	cout << "请输入修改后学生的微积分成绩:";
	cin >> Stu[temp].Math;

	cout << "请输入修改后学生的英语综合成绩:";
	cin >> Stu[temp].English;

	Stu[temp].Total = Stu[temp].Chinese + Stu[temp].Math + Stu[temp].English;
}
