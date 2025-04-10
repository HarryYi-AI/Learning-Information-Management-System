#pragma once
#include<iostream>
#include <string>
#include <fstream>

using namespace std;
class primarychengji {
private:
	int number;
	string name;
	string age;
	string sex;
	string class_info;
	float English;
	float Math;
	float Chinese;
	float Total;
public:
	void addstu(int nums, primarychengji stu[101],int &index);
	void search_by_name(string name, primarychengji stu[101],int index);
	void search_by_num(int num, primarychengji stu[101],int index);
	void delete_stu(string name, primarychengji stu[101],int &index);
	float CHI_average(primarychengji stu[101],int index);
	float MATH_average(primarychengji stu[101], int index);
	float ENG_average(primarychengji stu[101],int index);
	void total_sorting(primarychengji stu[101],int index);
	void CHI_sorting(primarychengji stu[101],int index);
	void MATH_sorting(primarychengji stu[101],int index);
	void ENG_sorting(primarychengji stu[101],int index);
	void output_list(primarychengji stu[101],int amount);
	void get_name();
	void show_all(primarychengji stu[101],int index);
	void change_stu1(string name, primarychengji stu[101], int index);
	void change_stu2(int target, primarychengji Stu[101], int index);
};

