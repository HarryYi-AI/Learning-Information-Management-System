#include "manager.h"



//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;


}

//选择菜单
void Manager::operMenu()
{
	cout <<"----------------------------------------------------------------------------------------"<<endl;
	cout <<"------------------------------------请选择要访问的项目-------------------------------------------------"<<endl;
	cout <<"---------------------------------------1添加账号-------------------------------------------------"<<endl;
	cout <<"---------------------------------------2查看账号-------------------------------------------------"<<endl;
	cout <<"--------------------------------------------------------------------------------------------"<<endl;
	cout <<"---------------------------------------0注销登录-------------------------------------------------"<<endl;
	cout <<"----------------------------------------------------------------------------------------"<<endl;
	cout <<"请选择您的操作："<<endl;
}




//添加账号  
void Manager::addPerson()
{

	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	string errorTip; //重复错误提示

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入";
	}
	ofs.open(fileName.c_str(), ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout <<tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, 1);

		if (ret) //有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	
	

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}
void printStudent(Student & s)
{
	cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher & t)
{
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;
    Manager::initVector(); 
	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}



void Manager::initVector()
{

	vStu.clear();
	vTea.clear();
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
    

    
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); //学生初始化

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;

	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
