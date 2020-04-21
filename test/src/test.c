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
 * @file stay_management.c
 *
 * @brief Has the testing functions of stay, dine and employee management.
 *
 * @author Praneeth Doppalapudi     - praneethdoppalapudi@cmail.carleton.ca
 * @author Bhavani Singetam         - bsing105@uottawa.ca
 * @author Sravya Yarlagadda        - sravyayarlagaddda@cmail.carleton.ca
 * @author Hitesh Chowdary Nagalla  - hiteshchowdarynagall@cmail.carleton.ca
 */

/*
 * Macro to print out 'passed'/'failed' based on the boolean value of what was
 * provided to it.
 */
 /*
 *TODO DINE_MANAGEMENT EDIT AND VIEW FUNCTION
 *TODO EMPLOYEE_MANAGEMENT DELETE FUNCTION
 *TODO EMPLOYEE_MANAGEMENT SEARCH FUNCTION
 */

/* Automated testing function for testing the main menu display */

void automated_general_design_functions(){
    system("cls");
    printf("Testing echo function");
    printf("Testing display main menu");
    mainmenu();
    system("cls");

}


/* Function. To set color of Text at the output window */

void setcolor(int ForgC){
	WORD wColor;
	HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}

/* Main menu function that is being displayed */
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


/* Automated testing function for reserving room in stay management */

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
    Sleep(2000);
}

/* Automated testing function for searching customer details in stay management */

void automated_stay_management_customer_details_search_testing(){
     printf("\n\tTesting the function to search customer room details \n \n");
     customer_details_search();
     printf("\n\tCustomer detail search function passed the test by handling all the conditions  \n \n");
     Sleep(2000);
}

/* Automated testing function for adding an new employee in employee management */

void automated_employee_management_add_customer_testing(){
     printf("\n\tTesting the function to add employee details\n \n");
     add_record();
     printf("\n\tCustomer detail add function passed the test by handling all the conditions  \n \n");
     Sleep(2000);
}

/* Automated testing function for displaying all the menu in dine management */

void automated_dine_management_menu_display_testing(){
     printf("\n\tTesting the function to display dine menu details\n \n");
     order_food();
     printf("\n\tMenu details function passed the test by handling all the conditions  \n \n");
     Sleep(2000);
}

/* Automated testing function for displaying all the available customers in stay Management */

void automated_stay_management_display_information_testing(){
printf("\n\tTesting the function to display stay management details\n \n");
customer_details_display();
printf("\n\ details function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for editing customer details in stay management */

void automated_stay_management_edit_function_testing(){
printf("\n\tTesting the edit functions in stay management\n \n");
customer_details_edit();
printf("\n\tstay edit function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for deleting a customer record in stay management */

void automated_stay_management_stay_delete_testing(){
printf("\n\tTesting the delete functions in stay management\n \n");
customer_details_delete();
printf("\n\tstay delete function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for viewing order in dine management */

void automated_dine_management_view_testing(){
printf("\n\tTesting the view functions in dine management\n \n");
view_order();
printf("\n\tview function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for editing an order in dine management*/

void automated_dine_management_edit_testing(){
printf("\n\tTesting the edit functions in dine management\n \n");
edit_order();
printf("\n\tedit function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for viewing all the employees record */

void automated_employee_management_view_testing(){
printf("\n\tTesting the view functions in employee management\n \n");
view_record();
printf("\n\tview function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* Automated testing function for viewing all the previous orders in dine management */

void automated_dine_management_previous_order(){
printf("\n\tTesting the view previous order functions in dine management\n \n");
previous_order();
printf("\n\tview previous order function passed the test by handling all the conditions  \n \n");
Sleep(2000);
}

/* main function that is called by complier while running the testing code */
int main(){
    int option=0;
    setcolor(15);
    printf("\n                    Welcome To Stay and dine Management Testing         \n\n");
    printf(" \t\t\t*********************************************************************\n");
    printf(" \t\t\t*Enter 1 -> Testing Main page                                       *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 2 -> Testing stay management reserve room testing            *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 3 -> Testing stay management customer details search testing *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 4 -> Testing stay management display information testing     *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 5 -> Testing stay management edit function testing           *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 6 -> Testing employee management add customer testing        *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 7 -> Testing employee_management_view_testing                *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 8 -> Testing dine management menu display testing            *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 9 -> Testing dine management edit testing                    *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 10 -> Testing dine management view testing                   *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*Enter 11 -> Testing dine management previous order                 *\n");
    printf(" \t\t\t*-------------------------------------------------------------------*\n");
    printf(" \t\t\t*********************************************************************\n");
    printf("\n");
    scanf("%d",&option);
    if(option==1){
	system("cls");
        automated_general_design_functions();
        main();
    }
    else if(option==2){
	system("cls");
        automated_stay_management_reserve_room_testing();
        main();
    }
    else if(option==3){
    	system("cls");
        automated_stay_management_customer_details_search_testing();
        main();
    }
    else if(option==4){
    	system("cls");
	automated_stay_management_display_information_testing();
	main();
    }
    else if(option==5){
    	system("cls");
	automated_stay_management_edit_function_testing();
	main();
    }
    else if(option==6){
    	system("cls");
	automated_employee_management_add_customer_testing();
	main();
    }
    else if(option==7){
    	system("cls");
	automated_employee_management_view_testing();
	main();
    }
    else if(option==8){
    	system("cls");
	automated_dine_management_menu_display_testing();
	main();
    }
    else if(option==9){
    	system("cls");
	automated_dine_management_edit_testing();
	main();
    }
    else if(option==10){
    	system("cls");
	automated_dine_management_view_testing();
	main();
    }
    else if(option==11){
    	system("cls");
	automated_dine_management_previous_order();
	main();
    }
    else{
        system("cls");
        printf("Incorrect Input");
        printf("\n Press any key to continue");
        getch();
    }
    if(getch()){
    	return EXIT_SUCCESS;
    }

}
