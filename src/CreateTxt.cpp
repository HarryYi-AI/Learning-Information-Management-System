// CreateTxt.cpp
// �������ж������ļ����ݣ� д���ı��ļ���������ʽ�����ı��ļ��������������ӡ
#include "ex10_15.h"
void CreateTxt(fstream& f) 
{ fstream ftxt("d:\\booksFile.txt" , ios::out) ;	// д��ʽ���ı��ļ�
  bookData book ;
  f.seekg( 0, ios::end ) ;
  long posEnd = f.tellg() ;		// ��¼�������ļ�ĩβλ��
  f.seekg( 0, ios::beg ) ;		// �ƶ���ָ�뵽�ļ�ͷ
  cout << "********** �����ı��ļ� **********\n" ;
  do 
	{ // �Ӷ������ļ�����¼
	  f.read((char *) & book , sizeof(bookData)) ; 	
	  // �Ѽ�¼д���ı��ļ�
	  ftxt <<"ѧ��:"<< book.TP << '\t'<<"ѧ������:" << book.bookName << '\t' <<"���У��:"<<book.bookChu<<'\t'<<"ʣ���������:"<<book.money<<'\t'<<"��������:"<< book.balance << endl;
	} while ( f.tellg() != posEnd ) ;
  ftxt.close() ;
  cout << "�ı��ļ��ѽ�����Ҫ����ļ���( Y/N ) \n" ;
  char answer , s[80];
  cin >> answer ;
  if ( answer=='Y' || answer=='y' )
  { ftxt.open( "d:\\booksFile.txt" , ios::in ) ;	// ���������ļ�
    while( !ftxt.eof() )			// ������ʾ�ı��ļ�
		{ ftxt.getline( s, 80 ) ;
		  cout << s << endl ;	
		}
  }
  ftxt.close() ;		// �ر��ı��ļ�
}

