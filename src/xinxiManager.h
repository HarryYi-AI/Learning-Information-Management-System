#pragma once
#include<iostream>
using namespace std;

//��Ϣ������
class xinxiManager
{
public:

	//���캯��
	xinxiManager();
	
	//չʾ�˵�
	void show_Menu();
	
	void exitSystem();

	void initStudent();
	int  system1();
	int  system2();
	void createStudent();
	void saveStudent();

	//��������
	~xinxiManager();
};
