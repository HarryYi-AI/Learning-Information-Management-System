#include "primarychengji.h"
using namespace std;
void primarychengji::addstu(int nums, primarychengji Stu[101], int& index) {

	for (int i = 0; i < nums; i++)
	{
		cout << "�������" << i + 1 << "��ѧ��������:";
		cin >> Stu[i].name;

		cout << "�������" << i + 1 << "��ѧ�����Ա�:";
		cin >> Stu[i].sex;

		cout << "�������" << i + 1 << "��ѧ����רҵ:";
		cin >> Stu[i].class_info;

		cout << "�������" << i + 1 << "��ѧ�����꼶:";
		cin >> Stu[i].age;

		cout << "�������" << i + 1 << "��ѧ����ѧ��:";
		cin >> Stu[i].number;

		cout << "�������" << i + 1 << "��ѧ����רҵ�γɼ�:";
		cin >> Stu[i].Chinese;

		cout << "�������" << i + 1 << "��ѧ����΢���ֳɼ�:";
		cin >> Stu[i].Math;

		cout << "�������" << i + 1 << "��ѧ����Ӣ���ۺϳɼ�:";
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
	// д������
	for (int i = 0; i < amount; i++) {
		chengjidataFile << "������" << stu[i].name << ' ' <<"�꼶��" << stu[i].age << ' '<< "�Ա�" << stu[i].sex << ' ' <<"רҵ��" << stu[i].class_info << ' ';
		chengjidataFile << "רҵ�η�����" << stu[i].Chinese << ' '<<"΢���ַ�����" << stu[i].Math << ' ' <<"Ӣ���ۺϷ�����" << stu[i].English << ' '<<"�ܷ֣�" << stu[i].Total;
		
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

		//���������е�����
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

		//���������е�����
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

		//���������е�����
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

		//���������е�����
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
		cout <<"������"<< stu[i].name << ' ' <<"�꼶��"<< stu[i].age << ' ' <<"�Ա�"<< stu[i].sex << ' ' <<"רҵ��"<< stu[i].class_info << ' ';
		cout << "רҵ�γɼ���"<<stu[i].Chinese << ' ' <<"΢���ֳɼ���"<< stu[i].Math << ' ' << "Ӣ�"<<stu[i].English << ' '<<"�ܳɼ���" << stu[i].Total;
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
	cout << "�������޸ĺ�ѧ��������:";
	cin >> Stu[temp].name;

	cout << "�������޸ĺ�ѧ�����Ա�:";
	cin >> Stu[temp].sex;

	cout << "�������޸ĺ�ѧ����רҵ:";
	cin >> Stu[temp].class_info;

	cout << "�������޸ĺ�ѧ�����꼶:";
	cin >> Stu[temp].age;

	cout << "�������޸ĺ�ѧ����ѧ��:";
	cin >> Stu[temp].number;

	cout << "�������޸ĺ�ѧ����רҵ�γɼ�:";
	cin >> Stu[temp].Chinese;

	cout << "�������޸ĺ�ѧ����΢���ֳɼ�:";
	cin >> Stu[temp].Math;

	cout << "�������޸ĺ�ѧ����Ӣ���ۺϳɼ�:";
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
	cout << "�������޸ĺ�ѧ��������:";
	cin >> Stu[temp].name;

	cout << "�������޸ĺ�ѧ�����Ա�:";
	cin >> Stu[temp].sex;

	cout << "�������޸ĺ�ѧ����רҵ:";
	cin >> Stu[temp].class_info;

	cout << "�������޸ĺ�ѧ�����꼶:";
	cin >> Stu[temp].age;

	cout << "�������޸ĺ�ѧ����ѧ��:";
	cin >> Stu[temp].number;

	cout << "�������޸ĺ�ѧ����רҵ�γɼ�:";
	cin >> Stu[temp].Chinese;

	cout << "�������޸ĺ�ѧ����΢���ֳɼ�:";
	cin >> Stu[temp].Math;

	cout << "�������޸ĺ�ѧ����Ӣ���ۺϳɼ�:";
	cin >> Stu[temp].English;

	Stu[temp].Total = Stu[temp].Chinese + Stu[temp].Math + Stu[temp].English;
}
