#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<fstream>
using namespace std;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //KAISA RA
WORD wOldColorAttrs;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        
typedef struct node
{

char row_no;
int seat_no,pin;
char book;
struct node *next,*prev;
}node;

class ceni
{
public:
node *hn;
ceni()
{
hn=NULL;
}
public:
void create()
{
node *nn,*cn;
int j=1;
volatile int k=2;
char c ='A';

do
{
int i=1;
do
{
k=(k*k)/10+100-k/2;
nn=new node();
nn->next=nn->prev=NULL;
nn->row_no=c;
nn->seat_no=i;
nn->pin=k;
nn->book='a';
if(hn==NULL)
{
hn=nn;
nn->next=nn->prev=hn;
}
else
{
cn=hn;

while(cn->next!=hn)
 cn=cn->next;

cn->next=nn;
nn->prev=cn;
nn->next=hn;
hn->prev=nn;
}
i++;
}while(i<=7);
j++;
c++;
}while(j<=10);
}

void display()
{
node *cn;
cn=hn;
cout<<"\t\t\t\t\t\t\t----------------------------------------------------------------------------------------------\n";
cout<<"\t\t\t\t\t\t\t|\t\t                            Platinum                                         |\n";
while(cn->next!=hn)
{
if((cn->prev)->row_no!=cn->row_no)
cout<<"\t\t\t\t\t\t\t| ";
cout<<cn->row_no;
cout<<cn->seat_no;

if(cn->book=='a')
{
GetConsoleScreenBufferInfo(h, &csbiInfo);
wOldColorAttrs = csbiInfo.wAttributes;
SetConsoleTextAttribute ( h, FOREGROUND_GREEN);
cout << " -> Avail  ";  //green text with black background
SetConsoleTextAttribute ( h, wOldColorAttrs);
}


else
{
GetConsoleScreenBufferInfo(h, &csbiInfo);
wOldColorAttrs = csbiInfo.wAttributes;
SetConsoleTextAttribute(h, FOREGROUND_RED);
cout << " -> Taken  ";  //red text
SetConsoleTextAttribute ( h, wOldColorAttrs);
}


if((cn->next)->row_no!=cn->row_no)
cout<<"|\n";
if(cn->row_no=='C'&&cn->seat_no==7)
{
cout<<"\t\t\t\t\t\t\t----------------------------------------------------------------------------------------------\n";
cout<<"\t\t\t\t\t\t\t|\t\t                             gold                                            |\n";
}
if(cn->row_no=='H'&&cn->seat_no==7)
{
cout<<"\t\t\t\t\t\t\t----------------------------------------------------------------------------------------------\n";
cout<<"\t\t\t\t\t\t\t|\t\t                             Silver                                          |\n";
}
cn=cn->next;
}
cout<<cn->row_no;
cout<<cn->seat_no;


if(cn->book=='a')
{
GetConsoleScreenBufferInfo(h, &csbiInfo);
wOldColorAttrs = csbiInfo.wAttributes;
SetConsoleTextAttribute ( h, FOREGROUND_GREEN);
cout << " -> Avail  ";  //green text with black background
SetConsoleTextAttribute ( h, wOldColorAttrs);
}


else
{
GetConsoleScreenBufferInfo(h, &csbiInfo);
wOldColorAttrs = csbiInfo.wAttributes;
SetConsoleTextAttribute(h, FOREGROUND_RED);
cout << " -> Taken  ";  //red text
SetConsoleTextAttribute ( h, wOldColorAttrs);
}


cout<<"|\n";
cout<<"\t\t\t\t\t\t\t----------------------------------------------------------------------------------------------\n\n";
GetConsoleScreenBufferInfo(h, &csbiInfo);
wOldColorAttrs = csbiInfo.wAttributes;
SetConsoleTextAttribute(h, FOREGROUND_GREEN);
cout<<"\t\t\t\t\t\t\t\t\t                              PRICES                                \n";
SetConsoleTextAttribute ( h, wOldColorAttrs);
cout<<"\t\t\t\t\t\t\t\t\tPLATINUM-> 150              GOLD-> 100                  SILVER->60\n\n";
}


void display1(node *tmp[20],int n)
{
if(n!=1)
{
Sleep(300);
system("cls");
cout<<".............PRINTING RECIEPTS.............."<<endl;
cout<<"               Please Wait ";
Sleep(3000);
system("cls");

ofstream file;
file.open("jethro.txt");

file<<"------------------------------------------------------------------\n";
file<<"| THANK YOU! \t\t\t\t\t\t\t  |"<<endl;
file<<"| YOU HAVE SUCCESFULLY BOOKED THE SEATS\t\t\t\t  |"<<endl;
for(int i=1;i<n;i++)
file<<"| "<<tmp[i]->row_no<<tmp[i]->seat_no<<" PIN : "<<tmp[i]->pin<<"\t\t\t\t\t\t\t  |\n";
file<<"| !!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\t\t  |\n";
file<<"| PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\t\t  |\n";
file<<" -----------------------------------------------------------------\n";

file.close();
cout<<"------------------------------------------------------------------\n";
cout<<"| THANK YOU! \t\t\t\t\t\t\t  |"<<endl;
cout<<"| YOU HAVE SUCCESFULLY BOOKED THE SEATS\t\t\t\t  |"<<endl;
for(int i=1;i<n;i++)
cout<<"| "<<tmp[i]->row_no<<tmp[i]->seat_no<<" PIN : "<<tmp[i]->pin<<"\t\t\t\t\t\t\t  |\n";
cout<<"| !!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\t\t  |\n";
cout<<"| PINS ARE REQUIRED AT THE TIME OF CANCELLATION OF SEATS\t\t  |\n";
cout<<" -----------------------------------------------------------------\n";

}
}


void book_seat()
{
node *cn,*temp[20];
int n,z,flag;
char row;
int seat;
char ch;
do
{
z=1;
cout<<"\n\t\t\t\t\t\t\tTickets You Want To Buy? ";
cin>>n;

cout<<"\n\t\t\t\t\t\t\tEnter Seat Number(s): \n";

for(int i=1;i<=n;i++)
{
cout<<"\t\t\t\t\t\t\tNO "<<i<<" = "; 
cin>>row>>seat;
cn=hn;
if(row>='A'&&row<='E')
{
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"\n\n\t\t\t\t\t\t\tINVALID CHOICE!\n";
cout<<cn->row_no<<cn->seat_no<<"\n\n\t\t\t\t\t\t\t Seat is alredy reserved \n";

}
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"INVALID CHOISE!\n";
cout<<cn->row_no<<cn->seat_no<<" Seat is alredy reserved\n";
}
}
}
else 
{
while(cn->prev!=hn)
{
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"\n\n\t\t\t\t\t\t\tINVALID CHOISE!\n";
cout<<cn->row_no<<cn->seat_no<<"\n\n\t\t\t\t\t\t\t Seat is alredy reserved \n";

}
}
cn=cn->prev;
}
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"\n\n\t\t\t\t\t\t\tINVALID CHOISE!\n";
cout<<cn->row_no<<cn->seat_no<<"\n\n\t\t\t\t\t\t\t Seat is alredy reserved\n";
}
}
	
}

}


system("cls");
display1(temp,z);
getch();
system("cls");
cout<<"\n\n\t\t\t\t\t\t\tPRESS [1] To check Seat Status\n";
cout<<"\t\t\t\t\t\t\tPRESS [2] To book other seat\n";
cout<<"\t\t\t\t\t\t\tPRESS [3] To Exit BOOKING PORTAL";
cout<<"\n\t\t\t\t\t\t\tChoose: ";
cin>>ch;
if(ch==1)
display();
}while(ch=='2');
}

void cancle()
{
char row,ch;
int seat,pin;
node *cn;
cout<<"\t\t\t\t\t\t\t\tSEAT CANCELLATION\n";
do
{
ch='a';
cn=hn;
cout<<"\t\t\t\t\t\t\tSEAT NUMBER :";
cin>>row>>seat;
cout<<"\t\t\t\t\t\t\tPIN :";
cin>>pin;
if(row>='A'&&row<='E')
{
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"\t\t\t\t\t\t\tAre you sure u want to cancle the Seat (y/n) ";
char c;
cin>>c;

if(c=='y'||c=='Y')
{
cout<<"\t\t\t\t\t\t\tSEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
getch();
}

}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"\t\t\t\t\t\t\tinvalid SEAT NUMBER && PIN combination!!!!\n";
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"\t\t\t\t\t\t\tAre you sure u want to cancle (y/n) ";
char c;
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"\t\t\t\t\t\t\tSEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"\t\t\t\t\t\t\tinvalid SEAT NUMBER && PIN combination!!!!\n";
}
}
else
{
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"\t\t\t\t\t\t\tAre you sure u want to cancle the Seat (y/n) ";
char c;
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"\t\t\t\t\t\t\tSEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"\t\t\t\t\t\t\tinvalid SEAT NUMBER && PIN combination!!!!\n";
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"\t\t\t\t\t\t\tAre you sure u want to cancle (y/n) ";
char c;
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"\t\t\t\t\t\t\tSEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"\t\t\t\t\t\t\tinvalid SEAT NUMBER && PIN combination!!!!\n";
}
}
system("cls");
cout<<"\n\n\t\t\t\t\t\t\tPRESS [1] To Check Seat Status\n";
cout<<"\t\t\t\t\t\t\tPRESS [2] To Cancel More Tickets\n";
cout<<"\t\t\t\t\t\t\tPRESS [3] To Exit CANCELLATION PORTAL\n";
cout<<"\t\t\t\t\t\t\tChoose: ";
cin>>ch;
if(ch==1)
display();
}while(ch=='2');
}
};


int main()
{
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
ceni aj;
	int ch;
	char c;
	int input, x;
	char a, pass[100];
	
	login:
		system("cls");
		cout<<"Enter Employee Password: ";  	
		for (x=0;;x++)
		{
			a=getch();
			cout<<"*";
			if (a==13) break;				
			else 
			pass[x]=a;
		}
	if (strcmp(pass,"123")==0)
	{
		SetConsoleTextAttribute(color, 11);
        cout<<"\n>>>>>>You are now login!<<<<<<<"<< endl;
        Sleep(800);
    }
	else
	{
    cout<<endl<<endl<<"                     Incorrect Password ! "<<endl<<endl;
    cout<<"             ------------Try Again----------";
    Sleep(500);
  	goto login;
    }
    system("cls");
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	SetConsoleTextAttribute(color, 13);
	cout<<"\t\t\t\t\t\t\t\t\t\t\t   Time of the computer presently"<<endl;
	SetConsoleTextAttribute(color, 13);
	cout<<"\t\t\t\t\t\t\t\t         \t\t         date->> "<<timePtr->tm_mon<<"/"<<timePtr->tm_mday<<"/"<< timePtr->tm_year + 1900<<endl;
	SetConsoleTextAttribute(color, 13);
	cout<<"\t\t\t\t\t\t\t\t\t       \t\t         Time->> "<<timePtr->tm_hour<<":"<<timePtr->tm_min<<":"<<timePtr->tm_sec<<endl;
	

	cout<<"\n";
	SetConsoleTextAttribute(color, 14);
	cout<<"\t\t\t\t\t\t\t\t\t                    @@@@@@   Cinemax  @@@@@@\n";
	SetConsoleTextAttribute(color, 14);
	cout<<"\t\t\t\t\t\t\t\t\t                    vvvvvv ARRANGEMENT vvvvvv\n";
	SetConsoleTextAttribute(color, 15);
	aj.create();
	aj.display();

do
{
a:	
cout<<"\n";
cout<<"\t\t\t\t\t\t\tPRESS 1-> BOOK TICKETS\n";
cout<<"\t\t\t\t\t\t\tPRESS 2-> CANCEL TICKETS\n";
cout<<"\t\t\t\t\t\t\tPRESS 3-> EXIT"<<endl;
cout<<"\t\t\t\t\t\t\tChoose: ";
cin>>ch;

switch(ch)
{
case 1:
aj.book_seat();
aj.display();
break;

case 2:
aj.cancle();
aj.display();
break;
case 3:
	exit(1);

default:
cout<<"\t\t\t\t\t\t\t----Wrong Choise-----";
break;
}
if(ch!=3)
{
getch();
system("cls");
cout<<"\n\n\t\t\t\t\t\t\tPRESS [1] To Main Menu\n";
cout<<"\t\t\t\t\t\t\tPRESS [2] To Exit CINEMAX PORTAL";
cout<<"\n\t\t\t\t\t\t\tInput: ";
cin>>c;


}

}while(c==1);
system("cls");
aj.display();
goto a;
return 0;

}
