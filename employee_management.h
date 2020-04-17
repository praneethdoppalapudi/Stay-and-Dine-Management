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
/*function to add a record*/
void add_record(void){
	system("cls");
	if(getdata()==1){  /* function call to enter all the details*/
        fp=fopen("record1.txt","a+");
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Save any more?(Y / N): ");
		if(getch()=='n'){
	    	employee_management();
		}
		else{
	    	add_record();
		}
	}else{
	    employee_management();
	}
	int checkid(int c){  /*check whether the record is exist in list or not*/
	fp=fopen("record1.txt","a+");
    fseek (fp, 0, SEEK_END);
    if( ftell(fp) == 0){
        return 1;  /*returns 1 if employee_details exits*/
    }
    else{
        fseek (fp, 0, SEEK_SET);
        while(fread(&e,sizeof(e),1,fp)==1){
            if(e.id==c){
                return 0;  /*returns 0 if employee_details exits*/
            }
            else{
                return 1; /*return 1 if it not*/
            }
        }
    }

}

/* function to add all employee details taken from user*/
int getdata(){
	int t = 0;
	int  tempvar;
	printf("\tEnter Employee ID :\t");
	scanf("%d",&t);
	fflush(stdin);
	tempvar = checkid(t);
	fclose(fp);
	if(tempvar == 0){
		printf("\n\n");
		printf("\a***************The Employee Record Already Exists !!!\a");
		getch();
		return 0;
	}else if(tempvar==1){
        e.id=t;
        printf("\tEnter Employee Name : ");
        scanf("%s",e.name);
        fflush(stdin);
        printf("        Date Of Birth (dd/mm/yyyy) :");
        scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
        fflush(stdin);
        printf("        Year OF Joining :");
        scanf("%d",&e.YOJ);
        fflush(stdin);
        printf("        Place :");
        scanf("%s",e.place);
        fflush(stdin);
        printf("        Department :");
        scanf("%s",e.department);
        fflush(stdin);
        return 1;
	}
}
