// Append.cpp

#include "ex10_15.h"
void Append( fstream &f ) 
{ int choice ;
  bookData book ;
  int key ;
  long num ;
  f.seekp( 0, ios::end ) ;		// 读指针移到文件末尾
  long posEnd = f.tellp() ;		// 记录文件尾位置
  cout << "********** 入库登记 **********\n" ;
  while (1)
  { cout << "请键入操作选择\n"
         << "1：书籍信息录入\t"
 	     << "2：修改借阅书籍\t"
	     << "0：退出\n" ;
    cin >> choice ;
    switch ( choice )
	{ case 1:	// 追加新记录
		{ cout <<"学号: " ;
	      cin >> book.TP;
	      cout <<"学生姓名:" ;
	      cin >> book.bookName ;
		  cout <<"借出（主/东）:" ;
		  cin >> book.bookChu ;
          cout << "剩余借阅天数:" ;
	      cin >> book.money ;
		  cout << "已借阅数量:" ;
	      cin >> book.balance ;
	      f.write( (char *) & book , sizeof( bookData ) ) ;	// 写入文件
		  break ;
		};
	  case 2:	// 修改记录
		{ f.seekp( 0, ios::beg );	// 写指针移到文件头
		  cout << "学号(TP) ：\n? " ;
          cin >> key ;			// 输入书号
		  do 	// 按书号查找，读数据赋给结构变量book
			{ f.read((char *) & book , sizeof(bookData)) ; 
			} while ( book.TP != key && f.tellp() != posEnd ) ;
		  if ( book.TP == key )		// 找到记录
			{ cout <<"学号："<< book.TP << '\t'<<"学生姓名：" << book.bookName << '\t' <<"剩余借阅天数："<< book.money << '\t'<<"借阅数量："<< book.balance << endl ;
		      cout << "入库数量：\n? " ;
	          cin >> num ;
              if ( num>0 ) book.balance += num ;		// 修改库存量
			   else 
				{ cout << "数量输入错误\n" ;
			      continue;
				}
              f.seekp( -long( sizeof( bookData ) ), ios::cur );	// 指针复位
              f.write( ( char * ) & book , sizeof( bookData ) );	// 写入文件
		      cout << "现借阅量：\t\t" << book.balance << endl ;
			}
		   else 
             cout << "学号输入错误\n" ;
		  break ;
		}
	  case 0 :  return ;
	}
  }
}

