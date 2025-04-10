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

//管理员菜单
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
        
		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson(); 
		}

		
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单 
void studentMenu(Identity * &student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;
		
		if (select == 1)
		{
			stu->Zhaosheng();
			cout<<"恭喜您被我校录取"<<endl;
			cout<<"有关招生详细资料请拨打招生办电话或去南门招生办询问"<<endl;
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		
	}
}
//教师菜单 
void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//教师菜单
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//登录功能
int LoginIn(string fileName, int type)
{

	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName.c_str(),ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return 0;
	}

	int xuehao = 0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> xuehao;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> xuehao;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (xuehao == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(xuehao, name, pwd);
				//进入学生菜单 
				studentMenu(person);
				return 1;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (xuehao == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(xuehao, name, pwd);
				//进入教师菜单
				TeacherMenu(person); 
				return 1;
			}
		}
	}
	else if(type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name,pwd);
				managerMenu(person);
				return 1;
			}
		}
	}
	
	cout << "验证登录失败!" << endl;

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
		cout<<"请输入您的选择："<<endl;
		cin>>choice; 
		
		if (choice == 0) {
			xm.exitSystem();
			break;} 
		else if (choice == 1) {
			
			if (LoginIn(STUDENT_FILE,1)==1){
				cout <<"欢迎进入学生系统"<<endl; 
				
		
			}
			
			
			}
			
		else if (choice == 2) {
		
			if (LoginIn(TEACHER_FILE,2)==1){
				cout <<"欢迎进入职工系统"<<endl;
				
		
			}
			
			}
		else if (choice == 3) {
			
			
			if (LoginIn(ADMIN_FILE, 3)==1)
			{
				cout <<"欢迎进入管理系统"<<endl; 
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
