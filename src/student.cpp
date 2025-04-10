#include "student.h"
#include <fstream>
#include "teacher.h" 
#include "globalFile.h"
#include"computerRoom.h"


//默认构造
Teacher::Teacher()
{
}

//有参构造 (职工编号，姓名，密码)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
	
	
	
}



//本科院招生办信息记录
void Teacher::Zhaosheng()
{
	cout<<"请选择要进行的操作"<<endl;
	cout<<"1表示进行记录新学生,2表示查看所有学生"<<endl;
	cout<<"按0退出"<<endl;
	//假如写错了，要怎么办将其修正呢？
	int mmm=0; 
	cin>>mmm;
	if(mmm==1)
	{
		string name,xingbie,jiguan,luquzhuanye,sushehao;
		double shenfenzheng;
		int gaokao,xuehao;
		fstream f;
		while(mmm==1)
	{
		f.open("student xiangxi.txt",ios::out|ios::app);
		cout<<"学生姓名："<<endl;
		cin>>name;
		cout<<"性别："<<endl;
		cin>>xingbie;
		cout<<"身份证号："<<endl;
		cin>>shenfenzheng;
		cout<<"籍贯："<<endl;
		cin>>jiguan;
		cout<<"高考成绩："<<endl;
		cin>>gaokao;
		cout<<"录取学院与专业："<<endl;
		cin>>luquzhuanye;  
		cout<<"学号："<<endl;
		cin>>xuehao;
		cout<<"宿舍号："<<endl;
		cin>>sushehao;	
		f<<name<<"\t"<<xingbie<<"\t"<<shenfenzheng<<"\t"<<jiguan<<"\t"<<gaokao<<"\t"<<luquzhuanye<<"\t"<<xuehao<<"\t"<<sushehao<<"\t"<<endl;
		f.close();
		
		cout<<"接来下请选择："	<<endl;
		cin>>mmm;
		  
	}}
	else if(mmm=2)
	{
		Teacher::showComputer();
		return;
	}
	
	else
	{
		return;
	}


}
//查看学生信息
void Teacher::showComputer()
{
	Teacher::initVector();
	cout << "学生详细信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->name <<"\t"<< it->xingbie<<"\t" << it->shenfenzheng<<"\t"<< it->jiguan<<"\t"<< it->gaokao<<"\t"<< it->luquzhuanye<<"\t"<< it->m_Id<<"\t"<< it->sushehao<<"\t"<< endl;
	}
	system("pause");
	system("cls");
}
void Teacher::initVector(){
	
	vCom.clear();
		//获取学生信息
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.name && ifs >> c.xingbie&& ifs >> c.shenfenzheng&& ifs >> c.jiguan&& ifs >> c.gaokao&& ifs >> c.luquzhuanye&& ifs >> c.m_Id&& ifs >> c.sushehao)
	{
		vCom.push_back(c);
	}
	cout << "当前学生数量为： " << vCom.size() << endl;

	ifs.close();	
	
	
} 
void Teacher::initVector2(){
	
	vJia.clear();
	
	ifstream ifs;

	ifs.open(JIANGXUEJIN, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Jiangxuejin j;
	while (ifs >> j.name && ifs >>j.m_Id&& ifs >> j.jiangxuejin)
	{
		vJia.push_back(j);
	}
	cout << "当前获奖学金的学生数量为： " << vJia.size() << endl;

	ifs.close();	
	
	
} 

	


//图书馆书籍管理
void Teacher::Shuji()
{
//	查看所有学生借阅的书 
//	输入学号查看     一次性打开文件 
	int choice ;
    fstream iof( "booksFile.dat" , ios::app|ios::binary|ios::in|ios::out ) ;
    if (!iof)
	{ cerr << "文件不存在，创建一个新文件" << endl;
	}	
    while (1)
  { cout << "********** 书库管理 **********\n请键入操作选择\n" ;
	cout << "\t 1 -在借书信息中添加记录" << endl;
	cout << "\t 2 -按学号删除记录" << endl;
	cout << "\t 3 -按学号查询图书信息" << endl;
	cout << "\t 4 -建立和浏览图书文件" << endl;
//	cout << "\t 5 -" << endl;
	cout << "\t 0 -退出" << endl;
	cin  >> choice;
	switch ( choice )
	{ 

		case 1 :Append(iof) ; break ;
	  case 2 :Sale(iof) ; break ;
	  case 3 :Inquire(iof) ; break;
	  case 4 :CreateTxt(iof) ; break ;
	 // case 5 :del(iof); break ;
	  case 0 :cout<<"\t -退出程序的运行！\n"<< endl; return ;
	  default : cout<< "\t -输入错误，请重新输入！\n" <<endl;
	}
    }
    iof.close() ;		// 关闭文件
    return ;

} 


void Teacher::xuankesystem() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------欢迎来到选课系统 ---------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "**        < 1 >添加课程信息" << endl;
	cout << "**        < 2 >显示所有课程信息" << endl;
	cout << "**        < 3 >通过课程名查询课程信息" << endl;
	cout << "**        < 4 >通过课程号查询课程信息" << endl;
	cout << "**        < 5 >将记录保存为txt文件" << endl;
	cout << "**        < 6 >删除课程信息记录" << endl;
	cout << "**        < 0 >退出此系统" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Teacher::xuanke() {
	primary xxs[101];
	int index = 0;
	int in;
	Teacher::xuankesystem();
	while (1) {
		bool flag1;
		cin >> in;
		if (in == 0) {
			cout << "感谢使用";
			break;
		}
		else if (in == 1) {
			int nums;
			cout << "请输入需要添加的课程数" << endl;
			cin >> nums;
			xxs->addstu(nums,xxs,index);
			Teacher::xuankesystem();
		}
		else if (in == 2) {
			xxs->show_all(xxs, index);
			Teacher::xuankesystem();
		}
		else if (in == 3) {
			int d;
			cout << "请选择查询(1)或者修改(0)课程信息" << endl;
			cin >> d;
			if (d == 1) {
				cout << "请输入查询的课程名:"<<endl;
				string name;
				cin >> name;
				xxs->search_by_name(name,xxs,index);
				Teacher::xuankesystem();
			}
			else if (d == 0) {
				cout << "请输入需要修改的课程名：" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				Teacher::xuankesystem();
			}
		}
		else if (in == 4) {
			int d;
			cout << "请选择查询(1)或者修改(0)课程信息" << endl;
			cin >> d;
			if (d == 1) {
				cout << "请输入查询的课程学号:" << endl;
				int target;
				cin >> target;
				xxs->search_by_num(target, xxs, index);
				Teacher::xuankesystem();
			}
			else if (d == 0) {
				cout << "请输入需要修改的课程学号：" << endl;
				int target;
				cin >> target;
				xxs->change_stu2(target, xxs, index);
				Teacher::xuankesystem();
			}
		}

		else if (in == 5) {
			xxs->output_list(xxs, index);
			Teacher::xuankesystem();
		}
		else if (in == 6) {
			cout << "请输入需要删除的课程的名字" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "已删除该课程信息" << endl;
			Teacher::xuankesystem();
		}
	}
	
}
void Teacher::chengjisystem() {

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------成绩管理-------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "**        < 1 >添加学生成绩信息记录" << endl;
	cout << "**        < 2 >显示所有学生成绩信息" << endl;
	cout << "**        < 3 >通过姓名查询修改学生信息" << endl;
	cout << "**        < 4 >通过学号查询修改学生信息" << endl;
	cout << "**        < 5 >将记录内学生排序" << endl;
	cout << "**        < 6 >将记录保存为txt文件" << endl;
	cout << "**        < 7 >删除学生信息记录" << endl;
	cout << "**        < 0 >退出此系统" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Teacher::Chengji() {
	primarychengji xxs[101];
	int index = 0;
	int in;
	Teacher::chengjisystem();
	while (1) {
		bool flag1;
		cin >> in;
		if (in == 0) {
			cout << "感谢使用";
			break;
		}
		else if (in == 1) {
			int nums;
			cout << "请输入需要添加的学生人数" << endl;
			cin >> nums;
			xxs->addstu(nums,xxs,index);
			Teacher::chengjisystem();
		}
		else if (in == 2) {
			xxs->show_all(xxs, index);
			Teacher::chengjisystem();
		}
		else if (in == 3) {
			int d;
			cout << "请选择查询(1)或者修改(0)学生信息" << endl;
			cin >> d;
			if (d == 1) {
				cout << "请输入查询的学生姓名:"<<endl;
				string name;
				cin >> name;
				xxs->search_by_name(name,xxs,index);
				Teacher::chengjisystem();
			}
			else if (d == 0) {
				cout << "请输入需要修改的学生姓名：" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				Teacher::chengjisystem();
			}
		}
		else if (in == 4) {
			int d;
			cout << "请选择查询(1)或者修改(0)学生信息" << endl;
			cin >> d;
			if (d == 1) {
				cout << "请输入查询的学生学号:" << endl;
				int target;
				cin >> target;
				xxs->search_by_num(target, xxs, index);
				Teacher::chengjisystem();
			}
			else if (d == 0) {
				cout << "请输入需要修改的学生学号：" << endl;
				int target;
				cin >> target;
				xxs->change_stu2(target, xxs, index);
				Teacher::chengjisystem();
			}
		}
		else if (in == 5) {
			cout << "请选择需要的排序方式:"<<endl;
			int d;
			cout << "<1>根据总分排序" << endl;
			cout << "<2>根据专业成绩排序" << endl;
			cout << "<3>根据微积分排序" << endl;
			cout << "<4>根据英语综合排序" << endl;
			cin >> d;
			if (d == 1) {
				xxs->total_sorting(xxs, index);
			}
			if (d == 2) {
				xxs->CHI_sorting(xxs, index);
			}
			if (d == 3) {
				xxs->MATH_sorting(xxs, index);
			}
			if (d == 4) {
				xxs->ENG_sorting(xxs, index);
			}
			Teacher::chengjisystem();
		}
		else if (in == 6) {
			xxs->output_list(xxs, index);
			Teacher::chengjisystem();
		}
		else if (in == 7) {
			cout << "请输入需要删除的学生的名字" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "已删除该学生信息" << endl;
			Teacher::chengjisystem();
		}
	}
	
}



//教务系统
void Teacher::Jiaowu()
{
//	1 课程添加 
//	2 成绩录入，加排名
//	 
	cout<<"请选择模块"<<endl;
	cout<<"1课程添加"<<endl;
	cout<<"2成绩录入"<<endl; 
	cout<<"请输入："<<endl;	
	int jiaowuint;
	cin>>jiaowuint;
	
	if (jiaowuint ==1)
	{
	
		Teacher::xuanke();
	}
	else if(jiaowuint==2)
	{
		Teacher::Chengji();
	}
	
	
}

//财务管理修改
void Teacher::Caiwu()
{
//	1 发奖学金 
//	2 查看余额 
	cout<<"请选择要进行的操作"<<endl;
	cout<<"1表示进行发放学生奖学金,2表示查看所有学生奖学金"<<endl;
	cout<<"按0退出"<<endl;
	int mmm=0; 
	cin>>mmm;
	if(mmm==1)
	{
		string name; 
		
		double jiangxuejin,xuehao;
		fstream f;
		while(mmm==1)
	{
		f.open(	JIANGXUEJIN,ios::out|ios::app);
		cout<<"学生姓名："<<endl;
		cin>>name;
		cout<<"学号："<<endl;
		cin>>xuehao;
		cout<<"奖学金："<<endl;
		cin>>jiangxuejin;
		f<<name<<"\t"<<xuehao<<"\t"<<jiangxuejin<<"\t"<<endl;
		f.close();
		
		cout<<"接来下请选择："	<<endl;
		cin>>mmm;
		  
	}}
	else if(mmm==2)
	{
		Teacher::initVector2();
		cout << "获奖学金的学生： " << endl;
	for (vector<Jiangxuejin>::iterator it = vJia.begin(); it != vJia.end(); it++)
	{
		cout<<it->name<<"\t"<<it->m_Id<<"\t奖学金"<<it->jiangxuejin<<"\t"<<endl; 

	}
	system("pause");
	system("cls");
		return;
	}
	else 
	{
		return;
	}

}

//后勤服务保障
void Teacher::Houqin()
{
	//查找 学生和老师 
    //宿舍和前面联系起来  
    Teacher::initVector();
	cout << "学生详细信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->name <<"\t"<< it->xingbie<<"\t"<< "学号"<<"\t"<< it->m_Id<<"\t宿舍号"<< it->sushehao<<"\t"<< endl;
	}
	system("pause");
	system("cls");
}

//默认构造
Student::Student()
{
}

//有参构造(学号、姓名、密码)
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	

}

//菜单界面
void Student::operMenu()
{
	cout <<"------------------------------------请选择要访问的项目-------------------------------------------------"<<endl;
	cout <<"---------------------------------------1本科院招生办-------------------------------------------------"<<endl;
	cout <<"---------------------------------------2图书馆-------------------------------------------------"<<endl;
	cout <<"---------------------------------------3教务系统-------------------------------------------------"<<endl;
	cout <<"---------------------------------------4财务管理-------------------------------------------------"<<endl;
	cout <<"---------------------------------------5后勤服务-------------------------------------------------"<<endl;
	cout <<"---------------------------------------0注销登录-------------------------------------------------"<<endl;
	cout <<"请选择您的操作："<<endl;
}

//本科院招生办
void Student::Zhaosheng()
{
	//查找自己的信息 （身份证…… 
	ifstream f("student xiangxi.txt",ios::in);
	if (!f)
	{
		cout<<"error"<<endl;
		return ;
	}
	
	string line;
	string a;
	

}

//图书馆
void Student::Shuji()
{
	//查找的时候再设一个函数 没有为零 
//	借几本书 
//	借书 ++
//	还书 -- 
//	 
   fstream iof( "booksFile.dat" , ios::app|ios::binary|ios::in|ios::out ) ;
Inquire(iof) ;
 } 
 

				
//教务系统
void Student::Jiaowu()
{
//	1课程号  课程名称  学时 老师 （查找，
//	2查看成绩与排名 

	cout<<"请选择模块"<<endl;
	cout<<"1课程查询"<<endl;
	cout<<"2成绩查询"<<endl; 
	cout<<"请输入："<<endl;	
	int jiaowuint;
	cin>>jiaowuint;
	
	if (jiaowuint ==1)
	{
//		Teacher::xuanke();
	
//		Student::xuanke();
	}
	else if(jiaowuint==2)
	{
		//Teacher::Chengji();
	}
	 


}

//财务管理
void Student::Caiwu()
{
//	1 查看自己的余额 
//	2 充值 （直接文件修改 
//	3 查看奖助学金 
}

//后勤服务
void Student::Houqin()
{
//	查自己宿舍，查第一个文件 
}

