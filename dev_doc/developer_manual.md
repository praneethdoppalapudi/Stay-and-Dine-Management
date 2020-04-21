**Introduction**

Stay and Dine Management is a software that integrate the main functionality of stay management with Dine management and Employee management. This project aims to minimize the errors that occur while making bills and also to avoid delays in providing bills to customers, which can include taxes on basis of their cheques. In this project will take user choice as input i.e., whether to reserve a room, book an event, or to order food from menu supplied by the client. The output of the program is seamlessly fluent to use and easy to understand even to a non-technical user. This project provides trouble free environment, as it helps the user or admin to be efficient about the records without any strain.
The flow of program goes as follows.
1.	**Stay_dine_employee.c** – It is main file that allows to execute all other files.
•	It has menu of options with 
	Stay management
	Dine Management
	Employee management
	Exit
•	If you choose one of the options it will lead to that functionality.

2.	**Stay_management.c** – It allows to the functionality of stay management system. 
•	It has menu of options with 
	Book a room – It allows customer to book a room.
	View Room Information – Here you can view details of customer of that particular room.
	Cancel room – It allows you cancellation of booked room.
	Search customer information – It allows you to search the particular customer based on his first name, last name etc..
	Edit Room information – It allows to edit the customer details.
	Exit – It returns you again to the main menu.

3.	**Dine_management.c** – It allows to the functionality of Dine management system. 
•	It has menu of options with 
	Order food – It let the customer to order his food by displaying the menu of al the food items like mushrooms etc.. 
	To view and edit order – It allows customer if there is need of changes to their order,
	Check out order – it allows customer to checkout their order by taking their details of information like name and room number.

4.	**Employee_management.c** – It allows the functionality to Employee management system.
•	     It has menu of options with 
	Add new Employee – If there is any new employee to that system it allows to add the details of that employee.
	Search Employee – It allows to search the record of any employee of that system.
	Delete Employee – It allows to remove the details of that particular employee.
	View Employee records – It allows to view all the details of the employees.

**Program Flow**

![Diagram](https://github.com/praneethdoppalapudi/Stay-and-Dine-Management/blob/dev/image_assets/flow%20diagram.png)

The stay_dine_employee.c calls the functions in following files to run the algorithm:
	The functions in stay_management.c contains all the stay management features of the project.
	The functions in dine_management.c contains all the dine management features of the project.
	The functions in dine_management.c contains all the dine management features of the project.
