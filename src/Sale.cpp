// Sale.cpp

#include "ex10_15.h"
void Sale(fstream& f) 
{ int choice ;
  bookData book ;
  int key ;
  long num ;
  f.seekp( 0, ios::end ) ;
  long posEnd = f.tellp() ;		// ��¼�ļ�ĩβλ��
  cout << "**********  ���۵Ǽ� **********\n" ;
  while (1)
  { cout << "��������ѡ��\n"
         << "1�����ĵǼ�\t"
		 << "0���˳�\n" ;
    cin >> choice ;
    switch ( choice )
	{ case 1:
		{ f.seekp( 0, ios::beg );		// ���ļ�ͷ��ʼ����
		  cout << "ѧ��(TP)��\n? " ;
		  cin >> key ;
		  do 		// ����Ų���
			{ f.read((char *) & book , sizeof(bookData)) ; 
			} while ( book.TP != key && f.tellp() != posEnd ) ;
		  if ( book.TP == key )		// �ҵ�
			{ cout<<"ѧ��:"<<book.TP<<'\t'<<"ѧ��������"<<book.bookName<<'\t'<<"����������"<<book.balance<<endl;
	          cout << "����������\n? " ;
	          cin >> num ;
			  if ( num>0 && book.balance>=num ) 	// �޸Ŀ����
				book.balance -= num ;
			  else 
				{ cout << "�����������\n" ;
				  continue;
				}
              f.seekp( -long( sizeof( bookData ) ), ios::cur );		// �ļ�ָ�븴λ
              f.write( (char *) & book , sizeof( bookData ) ) ;		// �޸��ļ���¼
	          cout << "���ѽ�����o\t\t" << book.balance << endl ;
			}
			else 
				cout << "ѧ���������\n" ;
			break ;
		}
		case 0 :  return ;
	}
  }
}

