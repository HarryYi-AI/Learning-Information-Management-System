
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
  char bookName[40] ; //学生姓名 
  char bookChu[40] ; //借出校区（主校区/东校区） 
  char bookZuo[40] ;
  int  money; //剩余借阅天数 
  long balance; //已借阅数量 
} ;

void Append(fstream &f );
void Sale(fstream &f) ;
void Inquire(fstream &f) ;
void CreateTxt(fstream &f) ;
#endif

