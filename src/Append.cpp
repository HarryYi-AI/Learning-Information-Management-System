// Append.cpp

#include "ex10_15.h"
void Append( fstream &f ) 
{ int choice ;
  bookData book ;
  int key ;
  long num ;
  f.seekp( 0, ios::end ) ;		// ��ָ���Ƶ��ļ�ĩβ
  long posEnd = f.tellp() ;		// ��¼�ļ�βλ��
  cout << "********** ���Ǽ� **********\n" ;
  while (1)
  { cout << "��������ѡ��\n"
         << "1���鼮��Ϣ¼��\t"
 	     << "2���޸Ľ����鼮\t"
	     << "0���˳�\n" ;
    cin >> choice ;
    switch ( choice )
	{ case 1:	// ׷���¼�¼
		{ cout <<"ѧ��: " ;
	      cin >> book.TP;
	      cout <<"ѧ������:" ;
	      cin >> book.bookName ;
		  cout <<"�������/����:" ;
		  cin >> book.bookChu ;
          cout << "ʣ���������:" ;
	      cin >> book.money ;
		  cout << "�ѽ�������:" ;
	      cin >> book.balance ;
	      f.write( (char *) & book , sizeof( bookData ) ) ;	// д���ļ�
		  break ;
		};
	  case 2:	// �޸ļ�¼
		{ f.seekp( 0, ios::beg );	// дָ���Ƶ��ļ�ͷ
		  cout << "ѧ��(TP) ��\n? " ;
          cin >> key ;			// �������
		  do 	// ����Ų��ң������ݸ����ṹ����book
			{ f.read((char *) & book , sizeof(bookData)) ; 
			} while ( book.TP != key && f.tellp() != posEnd ) ;
		  if ( book.TP == key )		// �ҵ���¼
			{ cout <<"ѧ�ţ�"<< book.TP << '\t'<<"ѧ��������" << book.bookName << '\t' <<"ʣ�����������"<< book.money << '\t'<<"����������"<< book.balance << endl ;
		      cout << "���������\n? " ;
	          cin >> num ;
              if ( num>0 ) book.balance += num ;		// �޸Ŀ����
			   else 
				{ cout << "�����������\n" ;
			      continue;
				}
              f.seekp( -long( sizeof( bookData ) ), ios::cur );	// ָ�븴λ
              f.write( ( char * ) & book , sizeof( bookData ) );	// д���ļ�
		      cout << "�ֽ�������\t\t" << book.balance << endl ;
			}
		   else 
             cout << "ѧ���������\n" ;
		  break ;
		}
	  case 0 :  return ;
	}
  }
}

