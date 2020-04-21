# Organization : Carleton University

# Authors

- Bhavani Singetam -  bsing105@uottawa.ca - University of Ottawa
- Praneeth Doppalapudi - praneethdoppalapudi@cmail.carleton.ca - Carleton University
- Sravya Yarlagadda - sravyayarlagadda@cmail.carleton.ca - Carleton University
- Hitesh Nagalla - hiteshchowdarynagall@cmail.carleton.ca - Carleton University

# Stay_and_Dine_Management

Stay and Dine Management is a software that integrate the main functionality of stay management with Dine management and Employee management. This project aims to minimize the errors that occur while making bills and also to avoid delays in providing bills to customers, which can include taxes on basis of their cheques. In this project will take user choice as input i.e., whether to reserve a room, book an event, or to order food from menu supplied by the client. The output of the program is seamlessly fluent to use and easy to understand even to a non-technical user. This project provides trouble free environment, as it helps the user or admin to be efficient about the records without any strain.

# Installation

Installation steps are mentioned in [install.md](https://github.com/praneethdoppalapudi/Stay-and-Dine-Management/blob/dev/install.md)

# Usage
To run, you must first install it. Then you can follow instructions mentioned in [user_manual.md](https://github.com/praneethdoppalapudi/Stay-and-Dine-Management/blob/dev_development/dev_doc/User_Manual.md)

# File Structure

The correct file structure (after installing GSL library should be followed and run the binary)


```
├── DEV_DOC.md 	-> Usage file
           └── User_Manual.md
	   └── developer_manual.md	 
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
├── install.sh 	-> Installation script
├── build 	-> Object files
                  ├── Stay_Dine_Employee.o
		  ├── stay_management.o
		  ├── dine_management.o
		  ├── employee_management.o
		  ├── test.o
├── src 	-> Source files for stay and dine management system
│       ├── Stay_Dine_Employee.c
│       ├── stay_management.c
│       ├── dine_management.c
│       ├── employee_management.c
│       ├── test.c
└──
```
# For Developers

For developer manual [click here](https://github.com/praneethdoppalapudi/Stay-and-Dine-Management/blob/dev_development/dev_doc/developer_manual.md).

# License

This project is licensed under the GPL 3.0 License - see the file for details [LICENSE](https://github.com/praneethdoppalapudi/Stay-and-Dine-Management/blob/dev/LICENSE)

# Acknowledgements

Thanks to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.
