#pragma once
#include<iostream>
#include <string>
#include <fstream>

using namespace std;
class primary {
private:
	int number;
	string name;
	int age;
	string sex;
	int class_info;


public:
	void addstu(int nums, primary stu[101],int &index);
	void search_by_name(string name, primary stu[101],int index);
	void search_by_num(int num, primary stu[101],int index);
	void delete_stu(string name, primary stu[101],int &index);
	float CHI_average(primary stu[101],int index);
	float MATH_average(primary stu[101], int index);
	float ENG_average(primary stu[101],int index);
	void total_sorting(primary stu[101],int index);
	void CHI_sorting(primary stu[101],int index);
	void MATH_sorting(primary stu[101],int index);
	void ENG_sorting(primary stu[101],int index);
	void output_list(primary stu[101],int amount);
	void get_name();
	void show_all(primary stu[101],int index);
	void change_stu1(string name, primary stu[101], int index);
	void change_stu2(int target, primary Stu[101], int index);
};

