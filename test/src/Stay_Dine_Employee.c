#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#include"stay_management.c"
#include"employee_management.c"
#include"dine_management.c"

/* This is an c file for Hotel Management system. Hotel management
includes stay at the hotel, Dine at the hotel and also managing
of all the employee records at the hotel. So the project has the
functionality to stay management in which features like reserving
room with customer details, editing the reservation, viewing
availabilty, and may more are delt with. In dine management
features such as displaying menu and letting user choose and
edit the order and also take the details of the customer to deliver
the order to room and also have the track of all previuos orders as
well. And finally in Employee management user can enter the record
of new employee and view all the existing employee details and also
can edit and search any employee from the entire list. Since integrating
too many functionality has code complexity we tried to implement each
functonality to different header files and included them in this main
class to access all the core features provided by each functions.*/

/*
 * @file Stay_Dine_Employee.c
 *
 * @brief Has the primary main function to display Main Menu..
 *
 * @author Praneeth Doppalapudi     - praneethdoppalapudi@cmail.carleton.ca
 * @author Bhavani Singetam         - bsing105@uottawa.ca
 * @author Sravya Yarlagadda        - sravyayarlagaddda@cmail.carleton.ca
 * @author Hitesh Chowdary Nagalla  - hiteshchowdarynagall@cmail.carleton.ca
 */

/* Function used to set color to text at output window*/
void setcolor(int ForgC){
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}

/* Function is called when exiting the entire program and
it deletes the dataBase of food management on exiting*/
void exit(int status){
    remove("completeOrder.txt");
    remove("custDetail.txt");
}

/* main function is called by complier to run the program*/
int main(){
	mainmenu();
	return 0; /*function call for displaying main menu*/
}

/*Function to display entire functionality of the project
inclusing stay, dine and employee management.*/
int mainmenu(){
    int option = 0;
    system("cls");   /* FOR CLEARING SCREEN*/
	setcolor(15);
	printf("                                                                           \n");
	printf("                                                                           \n");
	printf("                                                                           \n");
    printf("                                                                           \n");
 	printf("\t\t****************************************************************\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t*       ---------------------------------------------          *\n");
	printf("\t\t*        WELCOME TO STAY AND DINE MANAGEMENT SYSTEMS           *\n");
	printf("\t\t*       ---------------------------------------------          *\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t*                                                              *\n");
	printf("\t\t****************************************************************\n\n\n");
    printf("\t\t           *Please enter your choice from below*: \n");
    printf(" \t\t           ------------------------------------- \n");
    printf("\n\n");
    printf(" \t\t\t****************************************\n");
    printf(" \t\t\t*     Enter 1 -> Stay Management       *\n");
    printf(" \t\t\t*--------------------------------------*\n");
    printf(" \t\t\t*     Enter 2 -> Dine Management       *\n");
    printf(" \t\t\t*--------------------------------------*\n");
    printf(" \t\t\t*     Enter 3 -> Employee Management   *\n");
    printf(" \t\t\t*--------------------------------------*\n");
    printf(" \t\t\t*     Enter 4 -> Exit                  *\n");
    printf(" \t\t\t*--------------------------------------*\n");
    printf(" \t\t\t****************************************\n");
    printf("\n");
    scanf("%d",&option);
    if(option==1){
        stay_management(); /* Function call used for call stay management functionality*/
    }
    else if(option==2){
        dine_management(); /* Function call used for call dine management functionality*/
    }
    else if(option==3){
        employee_management();/* Function call used for call employee management functionality*/
    }
    else if(option==4){
        system("cls");
        printf("\n\n\t *****THANK YOU*****");
        printf("\n\t FOR TRUSTING OUR SERVICE");
        Sleep(2000);
        return 0;
    }else{
        system("cls");
        printf("Incorrect Input");
        printf("\n Press any key to continue");
        getch();
    }
}
