#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"
#include<vector>
#include"computerRoom.h"
#include "ex10_15.h"
#include "primary.h"
#include "primarychengji.h"

class Teacher :public Identity
{
public:

	//默认构造
	Teacher();

	//有参构造 (职工编号，姓名，密码)
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//本科院招生办信息记录
	void Zhaosheng(); 
	//查看学生信息
	void showComputer();

	//图书馆书籍管理
	void Shuji(); 
	
	//教务系统
	void Jiaowu(); 
	void chengjisystem();
	void Chengji() ;
	void xuankesystem();
	void xuanke();
	
	//财务管理修改
	void Caiwu();
	
	//后勤服务保障
	void Houqin();
	

	int m_EmpId; //教师编号
	
	void initVector();
	
	vector<ComputerRoom> vCom;
	
	void initVector2();
	
	vector<Jiangxuejin> vJia; 


};
