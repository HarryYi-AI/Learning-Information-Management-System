#pragma once
#include<iostream>
using namespace std;
#include "identity.h"


#define _CRT_SECURE_NO_WARNINGS


#include<vector>

#include "ex10_15.h"
#include "primary.h"
#include "primarychengji.h"

//学生类
class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造(学号、姓名、密码)
	Student(int xuehao, string name, string pwd);

	//菜单界面
	virtual void operMenu(); 

	//本科院招生办信息记录
	void Zhaosheng(); 

	//图书馆书籍管理
	void Shuji(); 
	
	//教务系统
	void Jiaowu(); 
//	void xuanke();
	
	//财务管理修改
	void Caiwu();
	
	//后勤服务保障
	void Houqin();
	
	//学生学号
	int m_Id;
	

	
private :
	int xuehao;
	
};
//chengji类 
class Score{

public:

float cLauage;//c语言成绩

float math;//高数成绩

float english;//英语成绩

};
