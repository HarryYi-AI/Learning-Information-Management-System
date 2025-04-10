#include "student.h"
#include <fstream>
#include "teacher.h" 
#include "globalFile.h"
#include"computerRoom.h"


//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι��� (ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
	
	
	
}



//����Ժ��������Ϣ��¼
void Teacher::Zhaosheng()
{
	cout<<"��ѡ��Ҫ���еĲ���"<<endl;
	cout<<"1��ʾ���м�¼��ѧ��,2��ʾ�鿴����ѧ��"<<endl;
	cout<<"��0�˳�"<<endl;
	//����д���ˣ�Ҫ��ô�콫�������أ�
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
		cout<<"ѧ��������"<<endl;
		cin>>name;
		cout<<"�Ա�"<<endl;
		cin>>xingbie;
		cout<<"���֤�ţ�"<<endl;
		cin>>shenfenzheng;
		cout<<"���᣺"<<endl;
		cin>>jiguan;
		cout<<"�߿��ɼ���"<<endl;
		cin>>gaokao;
		cout<<"¼ȡѧԺ��רҵ��"<<endl;
		cin>>luquzhuanye;  
		cout<<"ѧ�ţ�"<<endl;
		cin>>xuehao;
		cout<<"����ţ�"<<endl;
		cin>>sushehao;	
		f<<name<<"\t"<<xingbie<<"\t"<<shenfenzheng<<"\t"<<jiguan<<"\t"<<gaokao<<"\t"<<luquzhuanye<<"\t"<<xuehao<<"\t"<<sushehao<<"\t"<<endl;
		f.close();
		
		cout<<"��������ѡ��"	<<endl;
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
//�鿴ѧ����Ϣ
void Teacher::showComputer()
{
	Teacher::initVector();
	cout << "ѧ����ϸ��Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->name <<"\t"<< it->xingbie<<"\t" << it->shenfenzheng<<"\t"<< it->jiguan<<"\t"<< it->gaokao<<"\t"<< it->luquzhuanye<<"\t"<< it->m_Id<<"\t"<< it->sushehao<<"\t"<< endl;
	}
	system("pause");
	system("cls");
}
void Teacher::initVector(){
	
	vCom.clear();
		//��ȡѧ����Ϣ
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.name && ifs >> c.xingbie&& ifs >> c.shenfenzheng&& ifs >> c.jiguan&& ifs >> c.gaokao&& ifs >> c.luquzhuanye&& ifs >> c.m_Id&& ifs >> c.sushehao)
	{
		vCom.push_back(c);
	}
	cout << "��ǰѧ������Ϊ�� " << vCom.size() << endl;

	ifs.close();	
	
	
} 
void Teacher::initVector2(){
	
	vJia.clear();
	
	ifstream ifs;

	ifs.open(JIANGXUEJIN, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Jiangxuejin j;
	while (ifs >> j.name && ifs >>j.m_Id&& ifs >> j.jiangxuejin)
	{
		vJia.push_back(j);
	}
	cout << "��ǰ��ѧ���ѧ������Ϊ�� " << vJia.size() << endl;

	ifs.close();	
	
	
} 

	


//ͼ����鼮����
void Teacher::Shuji()
{
//	�鿴����ѧ�����ĵ��� 
//	����ѧ�Ų鿴     һ���Դ��ļ� 
	int choice ;
    fstream iof( "booksFile.dat" , ios::app|ios::binary|ios::in|ios::out ) ;
    if (!iof)
	{ cerr << "�ļ������ڣ�����һ�����ļ�" << endl;
	}	
    while (1)
  { cout << "********** ������ **********\n��������ѡ��\n" ;
	cout << "\t 1 -�ڽ�����Ϣ����Ӽ�¼" << endl;
	cout << "\t 2 -��ѧ��ɾ����¼" << endl;
	cout << "\t 3 -��ѧ�Ų�ѯͼ����Ϣ" << endl;
	cout << "\t 4 -���������ͼ���ļ�" << endl;
//	cout << "\t 5 -" << endl;
	cout << "\t 0 -�˳�" << endl;
	cin  >> choice;
	switch ( choice )
	{ 

		case 1 :Append(iof) ; break ;
	  case 2 :Sale(iof) ; break ;
	  case 3 :Inquire(iof) ; break;
	  case 4 :CreateTxt(iof) ; break ;
	 // case 5 :del(iof); break ;
	  case 0 :cout<<"\t -�˳���������У�\n"<< endl; return ;
	  default : cout<< "\t -����������������룡\n" <<endl;
	}
    }
    iof.close() ;		// �ر��ļ�
    return ;

} 


void Teacher::xuankesystem() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------��ӭ����ѡ��ϵͳ ---------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "**        < 1 >��ӿγ���Ϣ" << endl;
	cout << "**        < 2 >��ʾ���пγ���Ϣ" << endl;
	cout << "**        < 3 >ͨ���γ�����ѯ�γ���Ϣ" << endl;
	cout << "**        < 4 >ͨ���γ̺Ų�ѯ�γ���Ϣ" << endl;
	cout << "**        < 5 >����¼����Ϊtxt�ļ�" << endl;
	cout << "**        < 6 >ɾ���γ���Ϣ��¼" << endl;
	cout << "**        < 0 >�˳���ϵͳ" << endl;
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
			cout << "��лʹ��";
			break;
		}
		else if (in == 1) {
			int nums;
			cout << "��������Ҫ��ӵĿγ���" << endl;
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
			cout << "��ѡ���ѯ(1)�����޸�(0)�γ���Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ�Ŀγ���:"<<endl;
				string name;
				cin >> name;
				xxs->search_by_name(name,xxs,index);
				Teacher::xuankesystem();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵĿγ�����" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				Teacher::xuankesystem();
			}
		}
		else if (in == 4) {
			int d;
			cout << "��ѡ���ѯ(1)�����޸�(0)�γ���Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ�Ŀγ�ѧ��:" << endl;
				int target;
				cin >> target;
				xxs->search_by_num(target, xxs, index);
				Teacher::xuankesystem();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵĿγ�ѧ�ţ�" << endl;
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
			cout << "��������Ҫɾ���Ŀγ̵�����" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "��ɾ���ÿγ���Ϣ" << endl;
			Teacher::xuankesystem();
		}
	}
	
}
void Teacher::chengjisystem() {

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------�ɼ�����-------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "**        < 1 >���ѧ���ɼ���Ϣ��¼" << endl;
	cout << "**        < 2 >��ʾ����ѧ���ɼ���Ϣ" << endl;
	cout << "**        < 3 >ͨ��������ѯ�޸�ѧ����Ϣ" << endl;
	cout << "**        < 4 >ͨ��ѧ�Ų�ѯ�޸�ѧ����Ϣ" << endl;
	cout << "**        < 5 >����¼��ѧ������" << endl;
	cout << "**        < 6 >����¼����Ϊtxt�ļ�" << endl;
	cout << "**        < 7 >ɾ��ѧ����Ϣ��¼" << endl;
	cout << "**        < 0 >�˳���ϵͳ" << endl;
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
			cout << "��лʹ��";
			break;
		}
		else if (in == 1) {
			int nums;
			cout << "��������Ҫ��ӵ�ѧ������" << endl;
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
			cout << "��ѡ���ѯ(1)�����޸�(0)ѧ����Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ��ѧ������:"<<endl;
				string name;
				cin >> name;
				xxs->search_by_name(name,xxs,index);
				Teacher::chengjisystem();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵ�ѧ��������" << endl;
				string name;
				cin >> name;
				xxs->change_stu1(name, xxs, index);
				Teacher::chengjisystem();
			}
		}
		else if (in == 4) {
			int d;
			cout << "��ѡ���ѯ(1)�����޸�(0)ѧ����Ϣ" << endl;
			cin >> d;
			if (d == 1) {
				cout << "�������ѯ��ѧ��ѧ��:" << endl;
				int target;
				cin >> target;
				xxs->search_by_num(target, xxs, index);
				Teacher::chengjisystem();
			}
			else if (d == 0) {
				cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
				int target;
				cin >> target;
				xxs->change_stu2(target, xxs, index);
				Teacher::chengjisystem();
			}
		}
		else if (in == 5) {
			cout << "��ѡ����Ҫ������ʽ:"<<endl;
			int d;
			cout << "<1>�����ܷ�����" << endl;
			cout << "<2>����רҵ�ɼ�����" << endl;
			cout << "<3>����΢��������" << endl;
			cout << "<4>����Ӣ���ۺ�����" << endl;
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
			cout << "��������Ҫɾ����ѧ��������" << endl;
			string name;
			cin >> name;
			xxs->delete_stu(name, xxs, index);
			cout << "��ɾ����ѧ����Ϣ" << endl;
			Teacher::chengjisystem();
		}
	}
	
}



//����ϵͳ
void Teacher::Jiaowu()
{
//	1 �γ���� 
//	2 �ɼ�¼�룬������
//	 
	cout<<"��ѡ��ģ��"<<endl;
	cout<<"1�γ����"<<endl;
	cout<<"2�ɼ�¼��"<<endl; 
	cout<<"�����룺"<<endl;	
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

//��������޸�
void Teacher::Caiwu()
{
//	1 ����ѧ�� 
//	2 �鿴��� 
	cout<<"��ѡ��Ҫ���еĲ���"<<endl;
	cout<<"1��ʾ���з���ѧ����ѧ��,2��ʾ�鿴����ѧ����ѧ��"<<endl;
	cout<<"��0�˳�"<<endl;
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
		cout<<"ѧ��������"<<endl;
		cin>>name;
		cout<<"ѧ�ţ�"<<endl;
		cin>>xuehao;
		cout<<"��ѧ��"<<endl;
		cin>>jiangxuejin;
		f<<name<<"\t"<<xuehao<<"\t"<<jiangxuejin<<"\t"<<endl;
		f.close();
		
		cout<<"��������ѡ��"	<<endl;
		cin>>mmm;
		  
	}}
	else if(mmm==2)
	{
		Teacher::initVector2();
		cout << "��ѧ���ѧ���� " << endl;
	for (vector<Jiangxuejin>::iterator it = vJia.begin(); it != vJia.end(); it++)
	{
		cout<<it->name<<"\t"<<it->m_Id<<"\t��ѧ��"<<it->jiangxuejin<<"\t"<<endl; 

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

//���ڷ�����
void Teacher::Houqin()
{
	//���� ѧ������ʦ 
    //�����ǰ����ϵ����  
    Teacher::initVector();
	cout << "ѧ����ϸ��Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->name <<"\t"<< it->xingbie<<"\t"<< "ѧ��"<<"\t"<< it->m_Id<<"\t�����"<< it->sushehao<<"\t"<< endl;
	}
	system("pause");
	system("cls");
}

//Ĭ�Ϲ���
Student::Student()
{
}

//�вι���(ѧ�š�����������)
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	

}

//�˵�����
void Student::operMenu()
{
	cout <<"------------------------------------��ѡ��Ҫ���ʵ���Ŀ-------------------------------------------------"<<endl;
	cout <<"---------------------------------------1����Ժ������-------------------------------------------------"<<endl;
	cout <<"---------------------------------------2ͼ���-------------------------------------------------"<<endl;
	cout <<"---------------------------------------3����ϵͳ-------------------------------------------------"<<endl;
	cout <<"---------------------------------------4�������-------------------------------------------------"<<endl;
	cout <<"---------------------------------------5���ڷ���-------------------------------------------------"<<endl;
	cout <<"---------------------------------------0ע����¼-------------------------------------------------"<<endl;
	cout <<"��ѡ�����Ĳ�����"<<endl;
}

//����Ժ������
void Student::Zhaosheng()
{
	//�����Լ�����Ϣ �����֤���� 
	ifstream f("student xiangxi.txt",ios::in);
	if (!f)
	{
		cout<<"error"<<endl;
		return ;
	}
	
	string line;
	string a;
	

}

//ͼ���
void Student::Shuji()
{
	//���ҵ�ʱ������һ������ û��Ϊ�� 
//	�輸���� 
//	���� ++
//	���� -- 
//	 
   fstream iof( "booksFile.dat" , ios::app|ios::binary|ios::in|ios::out ) ;
Inquire(iof) ;
 } 
 

				
//����ϵͳ
void Student::Jiaowu()
{
//	1�γ̺�  �γ�����  ѧʱ ��ʦ �����ң�
//	2�鿴�ɼ������� 

	cout<<"��ѡ��ģ��"<<endl;
	cout<<"1�γ̲�ѯ"<<endl;
	cout<<"2�ɼ���ѯ"<<endl; 
	cout<<"�����룺"<<endl;	
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

//�������
void Student::Caiwu()
{
//	1 �鿴�Լ������ 
//	2 ��ֵ ��ֱ���ļ��޸� 
//	3 �鿴����ѧ�� 
}

//���ڷ���
void Student::Houqin()
{
//	���Լ����ᣬ���һ���ļ� 
}

