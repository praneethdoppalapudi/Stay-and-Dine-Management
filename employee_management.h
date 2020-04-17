/* This is an header file for Employee Management system. when you go through
main menu you will see main page of Employee management system. There you need to
choose you option from menu. option(1) for Adding new employee record, It will take
the options from user to input record (2) to search existing employee records.
Option (3) to delete any employee record, (4) to view all the existing employee
records, (5) to return back to main menu. So all the management of employee record
is done in this file */

/* Stucture definition for employee details to add and read an employee */

#include<stdio.h>

struct employee_details{
    char name[30];
    int id;
    int dd; int mm; int yyyy;
    int YOJ;
    char place[20];
    char department[20];
};
struct employee_details e;
char findrecord = '\0';
FILE *fp = NULL,*ft = NULL;

/* Main functionality of employee management*/
void employee_management(void){
    system("cls");
    printf("   \t\t                 |WELCOME TO EMPLOYEE MANGEMENT|              \t\t \n");
    int i = 0;
    printf("\n");
    setcolor(15);
    printf("\t\t              *Please enter your choice from Below*: \n\n");
    printf(" \t\t\t************************************************\n");
    printf(" \t\t\t*Enter 1 -> Add New Employee Record            *\n");
    printf(" \t\t\t*----------------------------------------------*\n");
    printf(" \t\t\t*Enter 2 -> Search Employee Record             *\n");
    printf(" \t\t\t*----------------------------------------------*\n");
    printf(" \t\t\t*Enter 3 -> Delete Employee Record             *\n");
    printf(" \t\t\t*----------------------------------------------*\n");
    printf(" \t\t\t*Enter 4 -> View Employee Records              *\n");
    printf(" \t\t\t*----------------------------------------------*\n");
    printf(" \t\t\t*Enter 5 -> Back to Main Menu                  *\n");
    printf(" \t\t\t************************************************\n");
    printf("\n");
    scanf("%d",&i);
    printf("\n\n");
    printf("\n\n");
	if(i==1){
		add_record(); /* function call to add a record*/
	}
	else if(i==2){
		search_record();/* function call to search a record*/
	}
	else if(i==3){
		delete_record();/* function call to delete a record*/
	}
	else if(i==4){
		view_record();/* function call to view all employee records*/
	}
	else if(i==5){
		mainmenu();/* function call to exit to main menu*/
	}
	else{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		employee_management();
	}
}

