#include "primary.h"
using namespace std;
void primary::addstu(int nums, primary Stu[101], int& index) {

	for (int i = 0; i < nums; i++)
	{
		cout << "�������" << i + 1 << "���γ���:";
		cin >> Stu[i].name;

		cout << "�������" << i + 1 << "���γ̵���ʦ:";
		cin >> Stu[i].sex;

		cout << "�������" << i + 1 << "���γ̵�ѧ��:";
		cin >> Stu[i].class_info;

		cout << "�������" << i + 1 << "���γ̵�ѧʱ:";
		cin >> Stu[i].age;

		cout << "�������" << i + 1 << "���γ̵Ŀγ̺�:";
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
	// д������
	for (int i = 0; i < amount; i++) {
		dataFile <<"����"<< "��" << stu[i].name << ' ' <<"ѧʱ��" << stu[i].age << ' '<< "��ʦ��" << stu[i].sex << ' ' <<"ѧ�֣�" << stu[i].class_info << ' ';
		
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
	cout << "�������޸ĺ�γ���:";
	cin >> Stu[temp].name;

	cout << "�������޸ĺ�γ̵���ʦ:";
	cin >> Stu[temp].sex;

	cout << "�������޸ĺ�γ̵�ѧ��:";
	cin >> Stu[temp].class_info;

	cout << "�������޸ĺ�γ̵�ѧʱ:";
	cin >> Stu[temp].age;

	cout << "�������޸ĺ�γ̵Ŀγ̺�:";
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
	cout << "�������޸ĺ�γ���:";
	cin >> Stu[temp].name;

	cout << "�������޸ĺ�γ̵���ʦ:";
	cin >> Stu[temp].sex;

	cout << "�������޸ĺ�γ̵�ѧ��:";
	cin >> Stu[temp].class_info;

	cout << "�������޸ĺ�γ̵�ѧʱ:";
	cin >> Stu[temp].age;

	cout << "�������޸ĺ�γ̵Ŀγ̺�:";
	cin >> Stu[temp].number;

}
