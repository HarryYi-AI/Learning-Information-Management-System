#include <iostream>
#include "primary.h"
using namespace std;

void system() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------��ӭ����ѡ��ϵͳ ---------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "**        < 1 >��ӿγ���Ϣ" << endl;
	cout << "**        < 2 >��ʾ���пγ���Ϣ" << endl;
	cout << "**        < 3 >ͨ���γ�����ѯ�γ���Ϣ" << endl;
	cout << "**        < 4 >ͨ���γ̺Ų�ѯ�γ���Ϣ" << endl;
	cout << "**        < 5 >����¼����Ϊtxt�ļ�" << endl;
	cout << "**        < 6 >ɾ���γ���Ϣ��¼" << endl;
	cout << "**        < 0 >�˳���ϵͳ" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
int main() {
	primary xxs[101];
	int index = 0;
	int in;
	system();
	while (1) {
		bool flag1;
		cin >> in;
		if (in == 0) {
			cout << "��лʹ��";
			break;
		}
		else if (in == 1) {
			int nums;
			cout << "��������Ҫ��ӵĿγ���" << endl;
			cin >> nums;
			xxs->addstu(nums,xxs,index);
			system();
		}
		else if (in == 2) {
			xxs->show_all(xxs, index);
			system();
		}
		else if (in == 3) {
			int d;
			cout << "��ѡ���ѯ(1)�����޸�(0)�γ���Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ�Ŀγ���:"<<endl;
				string name;
				cin >> name;
				xxs->search_by_name(name,xxs,index);
				system();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵĿγ�����" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				system();
			}
		}
		else if (in == 4) {
			int d;
			cout << "��ѡ���ѯ(1)�����޸�(0)�γ���Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ�Ŀγ�ѧ��:" << endl;
				int target;
				cin >> target;
				xxs->search_by_num(target, xxs, index);
				system();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵĿγ�ѧ�ţ�" << endl;
				int target;
				cin >> target;
				xxs->change_stu2(target, xxs, index);
				system();
			}
		}

		else if (in == 5) {
			xxs->output_list(xxs, index);
			system();
		}
		else if (in == 6) {
			cout << "��������Ҫɾ���Ŀγ̵�����" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "��ɾ���ÿγ���Ϣ" << endl;
			system();
		}
	}
	
}

