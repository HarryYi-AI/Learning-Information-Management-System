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

	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����Ժ��������Ϣ��¼
	void Zhaosheng(); 
	//�鿴ѧ����Ϣ
	void showComputer();

	//ͼ����鼮����
	void Shuji(); 
	
	//����ϵͳ
	void Jiaowu(); 
	void chengjisystem();
	void Chengji() ;
	void xuankesystem();
	void xuanke();
	
	//��������޸�
	void Caiwu();
	
	//���ڷ�����
	void Houqin();
	

	int m_EmpId; //��ʦ���
	
	void initVector();
	
	vector<ComputerRoom> vCom;
	
	void initVector2();
	
	vector<Jiangxuejin> vJia; 


};
