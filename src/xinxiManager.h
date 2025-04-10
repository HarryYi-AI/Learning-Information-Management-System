#pragma once
#include<iostream>
using namespace std;

//信息管理类
class xinxiManager
{
public:

	//构造函数
	xinxiManager();
	
	//展示菜单
	void show_Menu();
	
	void exitSystem();

	void initStudent();
	int  system1();
	int  system2();
	void createStudent();
	void saveStudent();

	//析构函数
	~xinxiManager();
};
