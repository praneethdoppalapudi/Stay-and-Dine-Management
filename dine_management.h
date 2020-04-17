/* This is an header file for Dine management system. when you go through
main menu you will see main page of dine management system. There you need to
choose you option from menu. option(1) for ordering food, It will take you to
the menu of food items Option (2) to review your previous orders. Option (3)
for return to main menu. As you pass through all this options you can check out
or you can review your order again. When your ready to checkout at the end it
will ask for details like firstname, lastname, phone number, room number etc..
at end you will get the popup of message about the delivery.*/

/* Stucture definition for customer details when ordering food */
struct customer_detail
{
    char first_name[10];
    char last_name[10];
    int room_no;
};
/* Stucture definition for food items*/
struct food_details
{
    int item_no;
    char item_name[10];
}m;
int again=0;
int quantity=0;
double total_price=0;

void dine_management(void){
    int choice=0;
	int again=0;
	double price=0;
/* This will clear the screen */
	system("cls");
    setcolor(15);
    for(int i=0;i<80;i++)
    printf("-");
    printf("\n");
    printf("   \t\t             |WELCOME TO DINE MANGEMENT|            \t\t \n");
    for(int i=0;i<80;i++)
    printf("-");
    printf("\n");
    setcolor(15);
/* Enter your Choice to begin your food management */
    printf("\t\t *Please enter your choice from Below*:");
    printf("\n\n");
    printf("\t\t                                             \n");
    printf("\t\t*********************************************\n");
    printf("\t\t* Enter 1 -> Order Food                     *\n");
    printf("\t\t*-------------------------------------------*\n");
    printf("\t\t* Enter 2 -> View Previous Orders           *\n");
    printf("\t\t*-------------------------------------------*\n");
    printf("\t\t* Enter 3 -> Return to Main Menu            *\n");
    printf("\t\t*********************************************\n");
    scanf("%d",&choice);
    if(choice==1){
/* This returns the function of ordering the food */
        order_food();
    }
    else if(choice==2){
/* This is to view your previous food orders */
        previous_order();
    }
/* This returns to your main menu */
    else if(choice==3){
        system("cls");
        mainmenu();
    }
    else{
/* Input should be from 1-3 else it will display this message and returns to previous menu again */
        printf("\n\n INCORRECT INPUT..PLEASE ENTER VALID INPUT \n\n");
    }
        dine_management();

}
