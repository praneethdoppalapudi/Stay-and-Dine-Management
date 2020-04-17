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

/*functionality to add customer details into the file*/
void add_customer_details() {
    FILE *f;
    char esc_to_exit;
    f=fopen("customer_details.txt","a+");/*opening the file in write mode to save the details*/
    if(f==0) {
        f=fopen("customer_details.txt","w+");
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
	    scanf("\n%s",customer_room_details.customer_room_number);
	    fflush(stdin);
	    if(check_room_number(customer_room_details.customer_room_number == 1)){
            printf("Enter customer name:\n");
            scanf("%s",customer_room_details.customer_name);
            fflush(stdin);
            printf("Enter customer address:\n");
            scanf("%s",customer_room_details.customer_address);
            fflush(stdin);
            printf("Enter Phone Number:\n");
            scanf("%s",customer_room_details.customer_phone_number);
            fflush(stdin);
            printf("Enter customer nationality:\n");
            scanf("%s",customer_room_details.customer_nationality);
            fflush(stdin);
            printf("Enter customer email:\n");
            scanf(" %s",customer_room_details.customer_email);
            fflush(stdin);
            printf("Enter customer period of stay(\'x\'days):\n");
            scanf("%s",&customer_room_details.customer_period_of_stay);
            fflush(stdin);
            printf("Enter Arrival date(dd\\mm\\yyyy):\n");
            scanf("%s",&customer_room_details.customer_arrival_date);
            fflush(stdin);
            /*Saving all the details into the file*/
            fwrite(&customer_room_details,sizeof(customer_room_details),1,f);
            fflush(stdin);
            printf("\n\n1 Room is successfully booked!!");
            printf("\n Press esc key to exit,  any other key to add_customer_details another customer detail:");
            esc_to_exit=getche();
            if(esc_to_exit==27){
                break;
            }
	    }
	    else{
            printf("\n\n*****ROOM IS CURRENTLY UNAVAILABLE******");
            getch();
            break;
	    }
    }
	fclose(f);/*closing the file*/
}

/*Functionality to delete customer details which are saved in the file*/
void customer_details_delete(){
    FILE *f,*t;
    int i=1;
    char customer_room_number[20];
    /*Opening temporary file to save information after deleting*/
    if((t=fopen("temporary_details_store.txt","w"))==NULL) {
        exit(0);
    }
    /*Opening customer details file to read information and delete */
    if((f=fopen("customer_details.txt","r"))==NULL){
	    exit(0);
    }
    system("cls");
    printf("Enter the Room Number of the hotel to be deleted from the database: \n");
    scanf("%s",customer_room_number);
    fflush(stdin);
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
            /*comparing the user entering room number with available room numbers in file*/
	    if(strcmp(customer_room_details.customer_room_number,customer_room_number)==0) {
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
    remove("customer_details.txt");
    /*Rename the temporary file with new customer detail file */
    rename("temporary_details_store.txt","customer_details.txt");
    printf("\n\nThe Customer is successfully removed....");
    getch();
}

/*Functionality to Display Customer details saved into a file*/
void customer_details_display()
{
    FILE *f;
    int i;
    /*Opening file in read mode to display the information*/
    if((f=fopen("customer_details.txt","r"))==NULL) {
	exit(0);
    }
    system("cls");
    printf("\n\t\t**********CUSTOMER DETAILS*********\n ");
        /*Displaying all customer Information*/
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
        printf("customer Room Number :\t%s\n",customer_room_details.customer_room_number);
        printf("customer Name:\t%s\n",customer_room_details.customer_name);
        printf("customer address:\t%s\n",customer_room_details.customer_address);
        printf("customer phone_number:\t%s\n",customer_room_details.customer_phone_number);
        printf("customer nationality: \t%s \n", customer_room_details.customer_nationality);
        printf("customer email: \t%s \n", customer_room_details.customer_email);
        printf("customer period of stay: \t%s \n",    customer_room_details.customer_period_of_stay);
        printf("customer arrival date: \t%s \n",    customer_room_details.customer_arrival_date);
        printf("-----------------------------\n");
    }
    printf("\n");
    fclose(f);
    getch();
}


/*Functionality to edit existing customer details*/
void customer_details_edit()
{
    int i=1;
    FILE *f, *t;
    char customer_room_number[20];
    long int size=sizeof(customer_room_details);
    if((f=fopen("customer_details.txt","r+"))==NULL) {
        exit(0);
    }
     /*Opening temporary file to save information after deleting*/
    if((t=fopen("temporary_details_store.txt","w"))==NULL) {
        exit(0);
    }
    system("cls");
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%s",customer_room_number);
    fflush(stdin);
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
            /*comparing the user entering room number with available room numbers in file*/
	    if(strcmp(customer_room_details.customer_room_number,customer_room_number)==0) {
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
    remove("customer_details.txt");
    /*Rename the temporary file with new customer detail file */
    rename("temporary_details_store.txt","customer_details.txt");
    if((f=fopen("customer_details.txt","a+"))==NULL) {
        exit(0);
    }
    /*Editing the  Customer Information*/
    printf("\nEnter Room Number     :");
    scanf("%s",&customer_room_details.customer_room_number);
    printf("\nEnter customer name    :");
    scanf("%s",&customer_room_details.customer_name);
    fflush(stdin);
    printf("\nEnter customer address        :");
    scanf("%s",&customer_room_details.customer_address);
    fflush(stdin);
    printf("\nEnter Phone number :");
    scanf("%s",&customer_room_details.customer_phone_number);
    fflush(stdin);
    printf("\nEnter customer nationality :");
    scanf("%s",&customer_room_details.customer_nationality);
    fflush(stdin);
    printf("\nEnter customer email :");
    scanf("%s",&customer_room_details.customer_email);
    fflush(stdin);
    printf("\nEnter customer period of stay :");
    scanf("%s",&customer_room_details.customer_period_of_stay);
    fflush(stdin);
    printf("\nEnter Arrival date :");
    scanf("%s",&customer_room_details.customer_arrival_date);
    fflush(stdin);
    fseek(f,size,SEEK_CUR);  //to go to desired position in file
    fwrite(&customer_room_details,sizeof(customer_room_details),1,f);
    fclose(f);
    printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    getch();
}


/*Functionality to search a particular customer using room number*/
void customer_details_search()
{
    system("cls");
    FILE *f;
    char customer_room_number[20];
    int flag=1;
    f=fopen("customer_details.txt","r+");
    if(f==0) {
        exit(0);
    }
    fflush(stdin);
    printf("Enter Room number of the customer to search its details: \n");
    scanf("%s", customer_room_number);
    while(fread(&customer_room_details,sizeof(customer_room_details),1,f)==1) {
        /*Search the customer details by comparing room number in the file and room number provided by user */
        if(strcmp(customer_room_details.customer_room_number,customer_room_number)==0){
	        flag=0;
    /*Displaying the customer details after searching the required information*/
	        printf("\n\tRecord Found\n ");
	        printf("\nRoom Number:\t%s",customer_room_details.customer_room_number);
	        printf("\ncustomer name:\t%s",customer_room_details.customer_name);
	        printf("\ncustomer address:\t%s",customer_room_details.customer_address);
	        printf("\nPhone number:\t%s",customer_room_details.customer_phone_number);
	        printf("\ncustomer nationality:\t%s",customer_room_details.customer_nationality);
	        printf("\ncustomer email:\t%s",customer_room_details.customer_email);
	        printf("\ncustomer period_of_stay:\t%s",customer_room_details.customer_period_of_stay);
	        printf("\nArrival date:\t%s",customer_room_details.customer_arrival_date);
	        flag=0;
	        break;
	    }
    }
    if(flag==1){
        printf("\n\tRequested Customer could not be found!");
    }
    getch();
    fclose(f);
}


int check_room_number(char c[20]){  /*check whether the record is exist in list or not*/
    FILE *fs;
	fs=fopen("customer_details.txt","a+");
    fseek (fs, 0, SEEK_END);
    if( ftell(fs) == 0){
        return 1;  /*returns 1 if employee_details exits*/
    }
    else{
        while(fread(&customer_room_details,sizeof(customer_room_details),1,fs)==1){
            if(strcmp(customer_room_details.customer_room_number,c) == 0){
                return 0;  /*returns 0 if employee_details exits*/
            }
            else{
                return 1; /*return 1 if it not*/
            }
        }
    }
    fclose(fs);

}
