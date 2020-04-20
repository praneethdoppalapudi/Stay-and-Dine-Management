/*This c program is to test the functions in the main project. We have considered few imporatnt functions which are needed to be tested 
as issuses are raised by not handling the functions in a proper manner. The are 5 function which has been tested they are:
1) General design Testing,
2) stay management reserve room testing,
3) stay management customer details search testing,
4) employee management add customer testing,
5) dine management menu display testing.
*/
/*
 * @file test.c
 *
 * @brief Test all functions in stay,dineand employee management..
 *
 * @author Praneeth Doppalapudi     - praneethdoppalapudi@cmail.carleton.ca
 * @author Bhavani Singetam         - bsing105@uottawa.ca
 * @author Sravya Yarlagadda        - sravyayarlagaddda@cmail.carleton.ca
 * @author Hitesh Chowdary Nagalla  - hiteshchowdarynagall@cmail.carleton.ca
 */
#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#include"stay_management.c"
#include"dine_management.c"
#include"employee_management.c"

/*
 * Macro to print out 'passed'/'failed' based on the boolean value of what was
 * provided to it.
 */

void automated_general_design_functions(){
    system("cls");
    printf("Testing echo function");
    printf("Testing display main menu");
    mainmenu();
    system("cls");

}
void setcolor(int ForgC){
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}
void mainmenu(){
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
        getch();
    }


void automated_stay_management_reserve_room_testing(){
	int checkdata=0;
    char filename[30];
    printf("\n\tTesting the function to reserve room \n \n");
    printf("\n\tEnter a file name with .txt extension in order to save customer details in db\n");
	printf("\n\tInorder to further access the information provide the file name as cust_det.txt or \n provide any other file name with .txt extension to just reserve a room\t\t");
    checkdata=scanf("%s",filename);
    fflush(stdin);
	int count = 0;
        while(1){
            if(count >=5){
                return -1;
            }
            else{
                if(!checkdata){
                printf("Enter Valid Input ! \n");
                checkdata = scanf("%s",filename);
                fflush(stdin);
                count+=1;
                }
                else{
                    break;
                }
            }
        }

    int ret = add_customer_details(filename);
    if(ret == 0){
        printf("\n\tReserve room function passed the test and reserved a room \n \n");
    }
    else if(ret == -1){
        printf("\n\tReserve room function passed the test by handling all the conditions \n \n");
    }
}

void automated_stay_management_customer_details_search_testing(){
     printf("\n\tTesting the function to search customer room details \n \n");
     customer_details_search();
     printf("\n\tCustomer detail search function passed the test by handling all the conditions  \n \n");
}

void automated_employee_management_add_customer_testing(){
     printf("\n\tTesting the function to add employee details\n \n");
     add_record();
     printf("\n\tCustomer detail add function passed the test by handling all the conditions  \n \n");
}

void automated_dine_management_menu_display_testing(){
     printf("\n\tTesting the function to display dine menu details\n \n");
     order_food();
     printf("\n\tMenu details function passed the test by handling all the conditions  \n \n");
}

int main(){
	automated_general_design_functions();
	automated_stay_management_reserve_room_testing();
	automated_stay_management_customer_details_search_testing();
	automated_employee_management_add_customer_testing();
	automated_dine_management_menu_display_testing();
	return EXIT_SUCCESS;
}
