#pragma once
#include<iostream>
using namespace std;
#include "identity.h"


#define _CRT_SECURE_NO_WARNINGS


#include<vector>

#include "ex10_15.h"
#include "primary.h"
#include "primarychengji.h"

//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���(ѧ�š�����������)
	Student(int xuehao, string name, string pwd);

	//�˵�����
	virtual void operMenu(); 

	//����Ժ��������Ϣ��¼
	void Zhaosheng(); 

	//ͼ����鼮����
	void Shuji(); 
	
	//����ϵͳ
	void Jiaowu(); 
//	void xuanke();
	
	//��������޸�
	void Caiwu();
	
	//���ڷ�����
	void Houqin();
	
	//ѧ��ѧ��
	int m_Id;
	

	
private :
	int xuehao;
	
};
//chengji�� 
class Score{

public:

float cLauage;//c���Գɼ�

float math;//�����ɼ�

float english;//Ӣ��ɼ�

};
