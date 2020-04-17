* This is an header file for Stay Management system. when you go through
main menu you will see main page of Stay management system. There you need
to choose you option from menu.
Option(1) for booking a room for new customer record, It will take the required information
from user and save it in a file.
Option(2) to view all the existing customer entered in the system records.
that particular Information.
Option(3) to delete any customer record from already saved file.
Option(4) to search existing customer records from the existing file and display the Information.
Option(5) to Edit the existing customer details in the file.
Option(6) to return back to main menu. So all the management of Reserving the
room is done in this file */

/* Structure defining the customer details to reserve a room in a hotel*/
struct room_booking_customer_details {
    char customer_room_number[10];
    char customer_name[20];
    char customer_address[25];
    char customer_phone_number[15];
    char customer_nationality[15];
    char customer_email[20];
    char customer_period_of_stay[10];
    char customer_arrival_date[10];
}customer_room_details;

/* Main functionality of Stay Management*/
void stay_management(){
    int i=0;
    int customer_choice;/*The user choice is save in this variable*/
    system("cls");
    while (1) {
        system("cls");
	    setcolor(15);
        for(i=0;i<80;i++) {
		    printf("-");
        }
        printf("\n");
	    printf("   \t\t                 |WELCOME TO STAY MANGEMENT|              \t\t \n");
        for(i=0;i<80;i++){
            printf("-");
        }
	    printf("\n");
	    setcolor(15);
        printf("                                                                           \n");
	    printf("                                                                           \n");
        printf("                                                                           \n");
	    printf("\t\t       *Please enter your from Below*:   \n\n");
        printf(" \t\t\t****************************************\n");
	    printf(" \t\t\t*Enter 1 -> Book a Room                *\n");
	    printf(" \t\t\t*--------------------------------------*\n");
	    printf(" \t\t\t*Enter 2 -> View Room information      *\n");
	    printf(" \t\t\t*--------------------------------------*\n");
	    printf(" \t\t\t*Enter 3 -> Cancel Room                *\n");
	    printf(" \t\t\t*--------------------------------------*\n");
        printf(" \t\t\t*Enter 4 -> Search Customer Information*\n");
	    printf(" \t\t\t*--------------------------------------*\n");
        printf(" \t\t\t*Enter 5 -> Edit Room Information      *\n");
	    printf(" \t\t\t*--------------------------------------*\n");
	    printf(" \t\t\t*Enter 6 -> Exit                       *\n");
	    printf(" \t\t\t****************************************\n");
	    printf("\n\n");
        scanf("%d",&customer_choice);
	    if(customer_choice==1){
            add_customer_details();/*Function call to add customer details*/
	    }
        else if(customer_choice==2){
            customer_details_display();/*Function call to display customer details*/
	    }
        else if(customer_choice==3){
            customer_details_delete();/*Function call to delete customer details*/
	    }
        else if(customer_choice==4){
	    customer_details_search();/*Function call to search customer details*/
	    }
        else if(customer_choice==5){
            customer_details_edit();/*Function call to edit customer details*/
        }
        else if(customer_choice==6){
            system("cls");/*Clear the Screen andFunction call to return to main menu*/
            mainmenu();
        }
        else{
            system("cls");
            printf("Invalid Input");/*Error message displaying when incorrect input is provided*/
            printf("\n Press any key to continue");
            getch();
        }
    }
}
