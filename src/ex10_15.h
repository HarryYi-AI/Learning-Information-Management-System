
//ex10_15.h

#ifndef EX10_15_H
#define EX10_15_H
/*
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
struct bookData
{ int TP ;
  char bookName[40] ; //ѧ������ 
  char bookChu[40] ; //���У������У��/��У���� 
  char bookZuo[40] ;
  int  money; //ʣ��������� 
  long balance; //�ѽ������� 
} ;

void Append(fstream &f );
void Sale(fstream &f) ;
void Inquire(fstream &f) ;
void CreateTxt(fstream &f) ;
#endif

