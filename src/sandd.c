#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


void reserveRoom(char fileName[30]);

struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomNumber[10];
	char name[20];
	char address[25];
	char phoneNumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivalDate[10];
}reserveRoomStruct;

struct employee
{

	char name[30];
	int id;
	//char DOB[10];
	int dd; int mm; int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];

	int quantity;
};
struct employee e;

FILE *fp,*ft,*dp,*dt;


// function used for coloring the text.

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}


void main()
{
   mainmenu();  // function used to display all available features.
}


void mainmenu(){
int i;
    char choice;
 system("cls");   // FOR CLEARING SCREEN
	setcolor(15);
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");
	printf(" -------------------------------------------------------------------------\n\n\n\n");
 	printf("\t\t****************************************************************\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t*       ---------------------------------------------          *\n");
	printf("\t\t*        WELCOME TO STAY AND DINE MANAGEMENT SYSTEMS           *\n");
	printf("\t\t*       ---------------------------------------------          *\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t****************************************************************\n\n\n");

    printf("\t\t *Please enter your choice from below*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Stay Management");
		printf("\n------------------------");
		printf(" \n Enter 2 -> Dine Management");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");


		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				staymanagement();break;
			case '2':
				//dinemanagement();break;
			case '3':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}

void staymanagement(){
int i=0;

	char customername;
	char choice;

    char * fileName = "bookingRecord.txt";

	getch();
    system("cls");
   // login();
	while (1)      // INFINITE LOOP
	{
		system("cls");
		setcolor(15);
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |WELCOME TO STAY MANGEMENT|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		setcolor(15);
		printf("\t\t *Please enter your choice from Below*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Reserve a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':

				reserveRoom(fileName);break;
			case '2':
				//listAllBokings();break;
			case '3':
				//deleteBooking();break;
			case '4':
				//searchBookings();break;
			case '5':
				//editBoking();break;
			case '6':
				system("cls");
				mainmenu();
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}

}

void reserveRoom(char fileName[30])
{
    FILE *f;
	char test;
    f=fopen(fileName,"a+");
                if(f==0)
                {   f=fopen(fileName,"w+");
                    system("cls");
                    printf("Please hold on while we set our database in your computer!!");
                    printf("\n Process completed press any key to continue!! ");
                    getch();
                }


	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",reserveRoomStruct.roomNumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",reserveRoomStruct.name);
		printf("Enter Address:\n");
		scanf("%s",reserveRoomStruct.address);
		printf("Enter Phone Number:\n");
		scanf("%s",reserveRoomStruct.phoneNumber);
		printf("Enter Nationality:\n");
		scanf("%s",reserveRoomStruct.nationality);
		printf("Enter Email:\n");
		scanf(" %s",reserveRoomStruct.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&reserveRoomStruct.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&reserveRoomStruct.arrivalDate);
		fwrite(&reserveRoomStruct,sizeof(reserveRoomStruct),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}
void stayadd()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}


