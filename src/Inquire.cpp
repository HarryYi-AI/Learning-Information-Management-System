// Inquire.cpp
// ��ѯ
#include "ex10_15.h"
void Inquire(fstream& f) 
{ int choice ;
  bookData book ;
  int key ;
  f.seekg( 0, ios::end ) ;			// ��ָ���Ƶ��ļ�ĩβ
  long posEnd = f.tellg() ;			// ��¼�ļ�βλ��
  cout << "********** ��ѯ **********\n" ;
  while (1)
    { cout << "��������ѡ��\n"
         << "1����ѧ�Ų�ѯ\t"
		 << "2�����\t"
		 << "0���˳�\n" ;
      cin >> choice ;
      switch ( choice )
		{ case 1:		// ����ż���
			{ f.seekg( 0, ios::beg );
			  cout << "ѧ��(ID)��\n? " ;
			  cin >> key ;
			  do 
				{ f.read((char *) & book , sizeof(bookData)) ; 
				} while ( book.TP != key && f.tellg() != posEnd ) ;
			  if ( book.TP == key )
		         cout << book.bookName << '\t' << book.bookChu << '\t' <<book.bookZuo<<'\t'<< book.balance << endl;
			  else 
				{ cout << "ѧ���������\n" ;
				  continue;
				}
			  break ;
			}
		  case 2:		// ����ļ�
			{ f.seekg( 0, ios::beg );
			  do 		// ������м�¼
				{ f.read((char *) & book , sizeof(bookData)) ; 
				  cout <<"ѧ��������"<< book.bookName << '\t'<<"���У����" << book.bookChu << '\t'<<"����������"<<'\t'<< book.balance << endl ;
				} while ( book.TP != key && f.tellp() != posEnd ) ;
			  break ;
			}
		  case 0 :  return ;
		}
    }
}

