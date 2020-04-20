/* This is an header file for Dine management system. when you go through
main menu you will see main page of dine management system. There you need to
choose you option from menu. option(1) for ordering food, It will take you to
the menu of food items Option (2) to review your previous orders. Option (3)
for return to main menu. As you pass through all this options you can check out
or you can review your order again. When your ready to checkout at the end it
will ask for details like firstname, lastname, phone number, room number etc..
at end you will get the popup of message about the delivery.*/

/*
 * @file dine_management.c
 *
 * @brief Has the primary functions of dine management..
 *
 * @author Praneeth Doppalapudi     - praneethdoppalapudi@cmail.carleton.ca
 * @author Bhavani Singetam         - bsing105@uottawa.ca
 * @author Sravya Yarlagadda        - sravyayarlagaddda@cmail.carleton.ca
 * @author Hitesh Chowdary Nagalla  - hiteshchowdarynagall@cmail.carleton.ca
 */

 #include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
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
	int i;
    int choice=0;
	int again=0;
	double price=0;
	/* This will clear the screen */
	system("cls");
    setcolor(15);
    for(i=0;i<80;i++)
    printf("-");
    printf("\n");
    printf("   \t\t             |WELCOME TO DINE MANGEMENT|            \t\t \n");
    for(i=0;i<80;i++)
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
        dine_management();
    }
}
void order_food(){
    int choice=0;
    printf("\t\t                    MENU                     \n");
    printf("\t\t*********************************************\n");
    printf("\t\t* Enter 1 -> Mushroom Croquettes--------15/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 2 -> Baked Churro Chips---------15/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 3 -> Chicken Empanadas----------15/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 4 -> Lamb Burger----------------20/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 5 -> Turkey Burger--------------20/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 6 -> Teriyaki Pineapple Burger--20/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 7 -> Flan-----------------------23/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 8 -> Turron---------------------23/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t* Enter 9 -> Churros--------------------23/-*\n");
    printf("\t\t*                                           *\n");
    printf("\t\t*********************************************\n\n");
    printf("\t\t   Enter 10-> Back To Main Menu             \n");
	char v='\0';
	/* choose the option that should be from 1 to 10 not the other.
	It will redirect to that item and adds to your cart*/
    printf("\n\nSelect the item from above :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1){
	 /* This is total price of your food items */
        total_price=total_price + 15;
		printf("\n");
        FILE *ttl;
        ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {1, "Mushroom Croquettes"};
        printf("Mushroom Croquettes is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();
	}
	else if(choice==2){
        total_price=total_price + 15;
		printf("\n");
        FILE *ttl;
	    ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {2, "Baked Churro Chips"};
        printf("Baked Churro Chips is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();

    }
    else if(choice==3){
        total_price=total_price + 15;
        printf("\n");
        FILE *ttl;
        ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {3, "Chicken Empanadas"};
        printf("Chicken Empanadas is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
        view_edit_order();
    }
    else if(choice==4){
        total_price=total_price + 20;
        printf("\n");
        FILE *ttl;
        ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {4, "Lamb Burger"};
        printf("Lamb Burger is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
        view_edit_order();
    }
    else if(choice==5){
        total_price=total_price + 20;
        printf("\n");
        FILE *ttl;
        ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
            }
        struct food_details input1 = {5, "Turkey Burger"};
        printf("Turkey Burger is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
        view_edit_order();
    }
	else if(choice==6){
		total_price=total_price + 20;
		printf("\n");
        FILE *ttl;
	    ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {6, "Teriyaki Pineapple Burger"};
        printf("Teriyaki Pineapple Burger is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();
    }
	else if(choice==7){
		total_price=total_price + 23;
		printf("\n");
        FILE *ttl;
	    ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {7, "Flan"};
        printf("Flan is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();
    }
	else if(choice==8){
		total_price=total_price + 23;
		printf("\n");
        FILE *ttl;
	    ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {8, "Turron"};
        printf("Turron is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();
    }
	else if(choice==9){
		total_price=total_price + 23;
		printf("\n");
        FILE *ttl;
	    ttl=fopen("order.txt","a");
        if(ttl==NULL){
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }
        struct food_details input1 = {9, "Churros"};
        printf("Churros is added to Checkout");
        fwrite (&input1, sizeof(struct food_details), 1, ttl);
        fclose(ttl);
		view_edit_order();
    }
    else if(choice==10){
        system("cls");
        mainmenu();
    }
    else{
	/* If you don't choose from 1 to 10 it will pop up message like this and retuns the previous menu again */
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		if(getch())
		dine_management();
    }
}
void view_edit_order(void){
    struct customer_detail input;
    int backmenu=0;
    int editch=0;
    system("cls");
	/* enter your choice to options below to order again food or edit your order or to go checkout your order */
    printf("\n *Please enter your choice from Below*:");
    printf("\n\n");
    printf(" \n Enter 1 -> To Order Again");
    printf("\n------------------------");
    printf(" \n Enter 2 -> To view and Edit your order");
    printf("\n----------------------------------------");
    printf(" \n Enter 3 -> To Checkout order");
    printf("\n------------------------------\n\n");
    scanf("%d",&again);
    printf("\n");
    if(again==1){
        printf("\n\n");
	/* If you choose to order food again it will return to menu of items */
        order_food();
    }
    else if(again==3){
        view_order();
        FILE *cust;
        char phone_no[15];
	/* Here we take the cutomer details to deliver the food */
        printf("Please Give Your Contact Details to deliver \n");
        printf(" First Name : ");
        scanf("%s",input.first_name);
        printf("Last Name : ");
        scanf("%s",input.last_name);
        printf("Phone : ");
        scanf("%s",&phone_no);
        printf("Room Number : ");
        scanf("%d",&input.room_no);
        printf("\n\n");
        cust = fopen("cust_detail.txt","w+");
	/* This is the message at end you check out */
		fwrite (&input, sizeof( struct customer_detail), 1, cust);
        printf("\n\n\n");
        printf("***********************************************************\n");
        printf("               Your Order Will Be At Your Door In 30 minutes.\n");
        printf("                        .....HAPPY ORDERING.....\n");
        printf("*******************************************************************\n");
        printf("Press Any To Go Mainmenu.");
        fclose(cust);
			/*details();*/
        if(getch()){
            dine_management();
        }
    }
    else if(again==2){
        view_order();
        printf("press 1 to edit your order or press 2 to go back menu \n");
        scanf("%d",&editch);
        if(editch==1){
            edit_order();
            view_order();
            printf("press 1 to get back to menu \n");
            scanf("%d",&backmenu);
            if(backmenu==1){
                view_edit_order();
            }
            else{
                printf("unable to go back");
            }
        }
        else if(editch==2){
            dine_management();
        }
    }
}
/* It displays the details of your food order */
void view_order(){
    FILE *tt2='NULL';
    tt2 = fopen("order.txt","r");
    int totatl = total_price;
    struct food_details input;
    printf("\n ********************Your order details***************\n");
    while(fread(&input, sizeof(input), 1, tt2)==1){
        printf ("\n id = %d \n item name = %s\n", input.item_no, input.item_name);
    }
    printf("\nGrand Total : %d\n",totatl);
    fclose(tt2);
}
/* This displays the previous order not related to this order */
void previous_order()
{
    FILE *tt1='NULL';
    FILE *tt2='NULL';
    tt1= fopen("order.txt","r");
    tt2= fopen("cust_detail.txt","r");
    int totall = total_price;
    struct food_details input1;
    struct customer_detail input2;
    printf("\n ********************Your order details***************\n");
    while(fread(&input1, sizeof(input1), 1, tt1)==1)
    printf ("\n Id= %d \n item name= %s \n ",input1.item_no,input1.item_name);
    while(fread(&input2, sizeof(input2), 1, tt2)==1)
    printf ("\n first name=%s \n last name=%s \n",input2.first_name,input2.last_name);
    printf ("\n  room number=%d ",input2.room_no);
    printf("\nGrand Total : %d\n",totall);
    fclose(tt2);
    printf("enter any key to exit");
    if(getch()){
        system("cls");
        mainmenu();
    }
}

/* This is to edit your order i.e to make any changes in your food items */
void edit_order(){
    FILE *f;
	struct food_details input;
	int itemnum=0;
	long int size=sizeof(input);
	if((f=fopen("order.txt","a+"))==NULL){
		exit(0);
	}
    FILE *ptr2=fopen("temp.txt","a");
	printf("Enter item number to delete:\n\n");
    scanf("%d",&itemnum);
	fflush(stdin);
    while(fread(&input,sizeof(struct food_details),1,f)==1){
        if((input.item_no)!=itemnum){
            fwrite(&input,sizeof(struct food_details),1,ptr2);
        }
        else {
            if(itemnum==1){
                total_price=total_price-15;
            }
            else if(itemnum==2){
                total_price=total_price-15;
            }
            else if(itemnum==3){
                total_price=total_price-15;
            }
            else if(itemnum==4){
                total_price=total_price-20;
            }
            else if(itemnum==5){
                total_price=total_price-20;
            }
            else if(itemnum==6){
                total_price=total_price-20;
            }
            else if(itemnum==7){
                total_price=total_price-23;
            }
            else if(itemnum==8){
                total_price=total_price-23;
            }
            else if(itemnum==9){
                total_price=total_price-23;
            }
        }
    }
	fclose(ptr2);
	fclose(f);
	/* It removes the file name order and renames order with temp*/
	remove("order.txt");
	rename("temp.txt","order.txt");
}


