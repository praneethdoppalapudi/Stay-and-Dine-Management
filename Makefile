CC=gcc
CFLAGS = -c -std=c99
MCMODEL = -mcmodel=large

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
 $(shell mkdir  bin)
 $(shell mkdir  build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER
all: tests
	
tests: Stay_Dine_Employee.o dine_management.o employee_management.o stay_management.o 
	$(CC) -g -o build/Stay_Dine_Employee.o build/dine_management.o build/employee_management.o build/stay_management.o 

	
Stay_Dine_Employee.o: src/Stay_Dine_Employee.c
	$(CC) -g -c $(MCMODEL)  src/Stay_Dine_Employee.c -o build/Stay_Dine_Employee.o
	
dine_management.o: src/dine_management.c
	$(CC) -g -c $(MCMODEL) src/dine_management.c -o build/dine_management.o

employee_management.o: src/employee_management.c
	$(CC) -g -c $(MCMODEL) src/employee_management.c -o build/employee_management.o
		
stay_management.o: src/stay_management.c
	$(CC) -g -c $(MCMODEL) src/stay_management.c -o build/stay_management.o


#CLEAN COMMANDS
clean:	
	rm -rf build
	rm -rf bin
