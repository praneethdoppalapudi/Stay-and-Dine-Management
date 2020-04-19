/* This is an header file for Stay Management system. when you go through
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

/*
 * @file stay_management.c
 *
 * @brief Has the primary functions of stay management..
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
/* Structure defining the customer details to reserve a room in a hotel*/
struct room_booking_customer_details {
    int customer_room_number;
    char customer_name[20];
    char customer_address[25];
    int customer_phone_number;
    char customer_nationality[15];
    char customer_email[20];
    int customer_period_of_stay[10];
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
        int entered = scanf("%d",&customer_choice);
	    if(customer_choice==1){
            add_customer_details("cust_det.txt");/*Function call to add customer details*/
	    }
        else if(customer_choice==2){
            customer_details_display();/*Function call to display customer details*/
	    }
        else if(customer_choice==3){
            customer_details_delete();/*Function call to delete customer details*/
	    }
        else if(customer_choice==4){
	        customer_details_search();/*Function call to search customer details*/
	        stay_management();
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

/*functionality to add customer details into the file*/
int add_customer_details(char *filename) {
    int checkdata = 0;
    FILE *f;
    int temp;
    char *ret;
    char esc_to_exit;
    if(strlen(filename)>15){
        printf("File name extented 15 characters");
        Sleep(2000);
        return -1;
    }
    ret = strrchr(filename, '.');
    printf("%s", ret);
    if(ret!= NULL){
        if(strcmp(ret,".txt") != 0){
            printf("Check the file Extension");
            Sleep(2000);
            return -1;
        }
    }else{
        printf("Check the file Extension");
        Sleep(2000);
            return -1;
    }
    f=fopen("..\\doc\\filename","a+");/*opening the file in write mode to save the details*/
    if(f==0) {
        f=fopen(filename,"w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
    }
    while(1){
        system("cls");
        /*Saving all the customer details into the structure room_booking_customer_details*/
        printf("\n Enter Customer Details:");
        printf("\n**************************");
        printf("\n Enter Room number:\n");
        checkdata = scanf("\n%d",&temp);
        fflush(stdin);
        int count = 0;
        while(1){
            if(count >=5){
                return -1;
            }
            else{
                if(!checkdata){
                printf("Enter Valid Input ! \n");
                checkdata = scanf("%d",&temp);
                fflush(stdin);
                count+=1;
                }
                else{
                    break;
                }
            }
        }
        if(check_room_number(temp) == 1){
            customer_room_details.customer_room_number = temp;
            printf("Enter customer name:\n");
            checkdata = scanf("%s",customer_room_details.customer_name);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
                }
                else{
                    if(!checkdata){
                        printf("Enter Valid Input data! \n");
                        checkdata = scanf("%s",customer_room_details.customer_nationality);
                        fflush(stdin);
                        count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            printf("Enter customer address:\n");
            checkdata = scanf("%s",customer_room_details.customer_address);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
                }
                else{
                    if(!checkdata){
                        printf("Enter Valid Input data! \n");
                        checkdata = scanf("%s",customer_room_details.customer_nationality);
                        fflush(stdin);
                        count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            printf("Enter Phone Number:\n");
            checkdata = scanf("%d",&customer_room_details.customer_phone_number);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
                }
                else{
                    if(!checkdata){
                        printf("Enter Valid Input for phone number! \n");
                        checkdata = scanf("%d",&customer_room_details.customer_phone_number);
                        fflush(stdin);
                        count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            printf("Enter customer nationality:\n");
            checkdata = scanf("%s",customer_room_details.customer_nationality);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
                }
                else{
                    if(!checkdata){
                        printf("Enter Valid Input data! \n");
                        checkdata = scanf("%s",customer_room_details.customer_nationality);
                        fflush(stdin);
                        count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            printf("Enter customer email:\n");
            scanf(" %s",customer_room_details.customer_email);
            fflush(stdin);
            printf("Enter customer period of stay(\'x\'days):\n");
            checkdata = scanf("%d",&customer_room_details.customer_period_of_stay);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
            }
            else{
                if(!checkdata){
                    printf("Enter Valid Number for Stay ! \n");
                    checkdata = scanf("%d",&customer_room_details.customer_period_of_stay);
                    fflush(stdin);
                    count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            printf("Enter Arrival date(dd\\mm\\yyyy):\n");
            checkdata = scanf("%s",&customer_room_details.customer_arrival_date);
            fflush(stdin);
            count = 0;
            while(1){
                if(count >=5){
                    return -1;
                }
                else{
                    if(!checkdata){
                        printf("Enter Valid Input data! \n");
                        checkdata = scanf("%s",customer_room_details.customer_nationality);
                        fflush(stdin);
                        count+=1;
                    }
                    else{
                        break;
                    }
                }
            }
            /*Saving all the details into the file*/
            fwrite(&customer_room_details,sizeof(customer_room_details),1,f);
            fflush(stdin);
            printf("\n\n1 Room is successfully booked!!");
            fclose(f);/*closing the file*/
            printf("\n Press esc key to exit,  any other key to add_customer_details another customer detail:");
            esc_to_exit=getche();
            if(esc_to_exit==27){
                break;
            }
            return 0;
        }
        else{
            printf("\n\n*****ROOM IS CURRENTLY UNAVAILABLE******");
            fclose(f);/*closing the file*/
            getch();
            return -1;
            break;
        }
    }
}


/*Functionality to Display Customer details saved into a file*/
void customer_details_display()
{
    FILE *f;
    int i;
    /*Opening file in read mode to display the information*/
    if((f=fopen("cust_det.txt","r"))==NULL) {
	    exit(0);
    }
    system("cls");
    printf("\n\t\t**********CUSTOMER DETAILS*********\n ");
        /*Displaying all customer Information*/
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
        printf("customer Room Number :\t%d\n",customer_room_details.customer_room_number);
        printf("customer Name:\t%s\n",customer_room_details.customer_name);
        printf("customer address:\t%s\n",customer_room_details.customer_address);
        printf("customer phone_number:\t%d\n",customer_room_details.customer_phone_number);
        printf("customer nationality: \t%s \n", customer_room_details.customer_nationality);
        printf("customer email: \t%s \n", customer_room_details.customer_email);
        printf("customer period of stay: \t%d \n",    customer_room_details.customer_period_of_stay);
        printf("customer arrival date: \t%s \n",    customer_room_details.customer_arrival_date);
        printf("-----------------------------\n");
    }
    printf("\n");
    fclose(f);
    getch();
}

/*Functionality to delete customer details which are saved in the file*/
void customer_details_delete(){
    FILE *f,*t;
    int i=1;
    int customer_room_number;
    /*Opening temporary file to save information after deleting*/
    if((t=fopen("temporary_details_store.txt","w"))==NULL) {
        exit(0);
    }
    /*Opening customer details file to read information and delete */
    if((f=fopen("cust_det.txt","r"))==NULL){
	    exit(0);
    }
    system("cls");
    printf("Enter the Room Number of the hotel to be deleted from the database: \n");
    scanf("%d",&customer_room_number);
    fflush(stdin);
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
            /*comparing the user entering room number with available room numbers in file*/
	    if(customer_room_details.customer_room_number == customer_room_number) {
            i=0;
	        continue;
	    }
	    else {
	        /*Copy the data into temporary file if the room number doesn't match */
            fwrite(&customer_room_details,sizeof(customer_room_details),1,t);
        }
    }
    if(i==1) {
        printf("\n\n Records of Customer in this  Room number is not found!!");
	    getch();
	    fclose(f);
	    fclose(t);
	    stay_management();
    }
    fclose(f);
    fclose(t);
    /*remove the customer details file after copying data into temporary file*/
    remove("cust_det.txt");
    /*Rename the temporary file with new customer detail file */
    rename("temporary_details_store.txt","cust_det.txt");
    printf("\n\nThe Customer is successfully removed....");
    getch();
}

/*Functionality to search a particular customer using room number*/
void customer_details_search()
{
    system("cls");
    FILE *f;
    int success_close;
    int customer_room_number;
    int flag=1;
    f=fopen("cust_det.txt","r+");

    if(f==0) {
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
    }
	else{
	    if( access( "cust_det.txt", R_OK ) == 0 ) {
			fflush(stdin);
			printf("Enter Room number of the customer to search its details: \n");
			scanf("%d",&customer_room_number);
			if((sizeof(customer_room_number)==sizeof(int)) && (sizeof(customer_room_details.customer_room_number)==sizeof(int))){
				while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
				/*Search the customer details by comparing room number in the file and room number provided by user */
					if(customer_room_details.customer_room_number == customer_room_number){
						flag=0;
						/*Displaying the customer details after searching the required information*/
						printf("\n\tRecord Found\n ");
						printf("\nRoom Number:\t%d",customer_room_details.customer_room_number);
						printf("\ncustomer name:\t%s",customer_room_details.customer_name);
						printf("\ncustomer address:\t%s",customer_room_details.customer_address);
						printf("\nPhone number:\t%d",customer_room_details.customer_phone_number);
						printf("\ncustomer nationality:\t%s",customer_room_details.customer_nationality);
						printf("\ncustomer email:\t%s",customer_room_details.customer_email);
						printf("\ncustomer period_of_stay:\t%d",customer_room_details.customer_period_of_stay);
						printf("\nArrival date:\t%s",customer_room_details.customer_arrival_date);
						flag=0;
						break;
					}
					else {
						printf("The file doesn't exist.");
					}
			   }
			}
		}
	}
    if(flag==1){
        printf("\n\tRequested Customer could not be found!");
    }
    success_close=fclose(f);
    if(success_close!=0){
		printf("File is not closed successfully!");
    }
    getch();
}

/*Functionality to edit existing customer details*/
void customer_details_edit()
{
    int i=1;
    FILE *f, *t;
    int customer_room_number;
    long int size=sizeof(customer_room_details);
    if((f=fopen("cust_det.txt","r+"))==NULL) {
        exit(0);
    }
     /*Opening temporary file to save information after deleting*/
    if((t=fopen("temporary_details_store.txt","w"))==NULL) {
        exit(0);
    }
    system("cls");
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%d",&customer_room_number);
    fflush(stdin);
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
            /*comparing the user entering room number with available room numbers in file*/
	    if(customer_room_details.customer_room_number == customer_room_number) {
            i=0;
	        continue;
	    }
	    else {
	        /*Copy the data into temporary file if the room number doesn't match */
            fwrite(&customer_room_details,sizeof(customer_room_details),1,t);
        }
    }
    if(i==1) {
        printf("\n\n Records of Customer in this  Room number is not found!!");
	    getch();
	    fclose(f);
	    fclose(t);
	    stay_management();
    }
    fclose(f);
    fclose(t);
    /*remove the customer details file after copying data into temporary file*/
    remove("cust_det.txt");
    /*Rename the temporary file with new customer detail file */
    rename("temporary_details_store.txt","cust_det.txt");
    if((f=fopen("cust_det.txt","a+"))==NULL) {
        exit(0);
    }
    /*Editing the  Customer Information*/
    printf("\nEnter Room Number     :");
    scanf("%d",&customer_room_details.customer_room_number);
    printf("\nEnter customer name    :");
    scanf("%s",&customer_room_details.customer_name);
    fflush(stdin);
    printf("\nEnter customer address        :");
    scanf("%s",&customer_room_details.customer_address);
    fflush(stdin);
    printf("\nEnter Phone number :");
    scanf("%d",&customer_room_details.customer_phone_number);
    fflush(stdin);
    printf("\nEnter customer nationality :");
    scanf("%s",&customer_room_details.customer_nationality);
    fflush(stdin);
    printf("\nEnter customer email :");
    scanf("%s",&customer_room_details.customer_email);
    fflush(stdin);
    printf("\nEnter customer period of stay :");
    scanf("%d",&customer_room_details.customer_period_of_stay);
    fflush(stdin);
    printf("\nEnter Arrival date :");
    scanf("%s",&customer_room_details.customer_arrival_date);
    fflush(stdin);
    fseek(f,size,SEEK_CUR);  /*to go to desired position in file*/
    fwrite(&customer_room_details,sizeof(customer_room_details),1,f);
    fclose(f);
    printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    getch();
}

int check_room_number(int num){  /*check whether the record is exist in list or not*/
    FILE *fs;
	fs=fopen("cust_det.txt","a+");
    fseek (fs, 0, SEEK_END);
    if( ftell(fs) == 0){
        fclose(fs);
        return 1;  /*returns 1 if customer_details exits*/
    }
    else{
        fseek (fs, 0, SEEK_SET);
        while(fread(&customer_room_details,sizeof(customer_room_details),1,fs)==1){
            if(customer_room_details.customer_room_number == num){
                fclose(fs);
                return 0;  /*returns 0 if customer_details exits*/
            }
        }
        fclose(fs);
        return 1; /*return 1 if it not*/
    }

}

