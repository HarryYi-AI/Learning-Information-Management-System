#include <iostream>
#include "primary.h"
using namespace std;

void system() {
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
int main() {
	primary xxs[101];
	int index = 0;
	int in;
	system();
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
			system();
		}
		else if (in == 2) {
			xxs->show_all(xxs, index);
			system();
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
				system();
			}
			else if (d == 0) {
				cout << "请输入需要修改的课程名：" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				system();
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
				system();
			}
			else if (d == 0) {
				cout << "请输入需要修改的课程学号：" << endl;
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
			cout << "请输入需要删除的课程的名字" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "已删除该课程信息" << endl;
			system();
		}
	}
	
}

