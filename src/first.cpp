#include<iostream>
#include"xinxiManager.h"
#include "globalFile.h"
#include "identity.h"
#include <fstream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//����Ա�˵�
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
        
		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson(); 
		}

		
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵� 
void studentMenu(Identity * &student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;
		
		if (select == 1)
		{
			stu->Zhaosheng();
			cout<<"��ϲ������У¼ȡ"<<endl;
			cout<<"�й�������ϸ�����벦��������绰��ȥ����������ѯ��"<<endl;
		}
		else if (select == 2)
		{
			stu->Shuji();
		}
		else if (select ==3)
		{
			stu->Jiaowu();
		}
		else if (select ==4)
		{
			stu->Caiwu();
		}
		else if (select ==5)
		{
			stu->Houqin();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}
//��ʦ�˵� 
void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{

			tea->Zhaosheng();
		}
			
		
			
		
		else if (select == 2)
		{
			tea->Shuji();
		}
		else if (select ==3)
		{
			tea->Jiaowu();
		}
		else if (select ==4)
		{
			tea->Caiwu();
		}
		else if (select ==5)
		{
			tea->Houqin();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼����
int LoginIn(string fileName, int type)
{

	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName.c_str(),ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return 0;
	}

	int xuehao = 0;
	string name;
	string pwd;

	if (type == 1)	//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> xuehao;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> xuehao;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (xuehao == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(xuehao, name, pwd);
				//����ѧ���˵� 
				studentMenu(person);
				return 1;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (xuehao == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(xuehao, name, pwd);
				//�����ʦ�˵�
				TeacherMenu(person); 
				return 1;
			}
		}
	}
	else if(type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name,pwd);
				managerMenu(person);
				return 1;
			}
		}
	}
	
	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return 0 ;
}




int main()
{
	xinxiManager xm;
	int choice=0;
	int s1,s2;
	while(1)
	{
		xm.show_Menu();
		cout<<"����������ѡ��"<<endl;
		cin>>choice; 
		
		if (choice == 0) {
			xm.exitSystem();
			break;} 
		else if (choice == 1) {
			
			if (LoginIn(STUDENT_FILE,1)==1){
				cout <<"��ӭ����ѧ��ϵͳ"<<endl; 
				
		
			}
			
			
			}
			
		else if (choice == 2) {
		
			if (LoginIn(TEACHER_FILE,2)==1){
				cout <<"��ӭ����ְ��ϵͳ"<<endl;
				
		
			}
			
			}
		else if (choice == 3) {
			
			
			if (LoginIn(ADMIN_FILE, 3)==1)
			{
				cout <<"��ӭ�������ϵͳ"<<endl; 
			}
			
			}		
		else 
		{
			system("cls");
			break;	
		}
	}
	system("pause");
	return 0;
	
}
