CC=gcc
CFLAGS = -c -std=c99
MCMODEL = -mcmodel=large

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
$(shell mkdir  bin)
$(shell mkdir  build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER
all: tests


Stay_Dine_Employee.o: src/Stay_Dine_Employee.c
	$(CC) -ansi -pedantic -Wall -c src/Stay_Dine_Employee.c -o build/Stay_Dine_Employee.o

dine_management.o: src/dine_management.c
	$(CC) -ansi -pedantic -Wall -c src/dine_management.c -o build/dine_management.o

employee_management.o: src/employee_management.c
	$(CC) -ansi -pedantic -Wall -c src/employee_management.c -o build/employee_management.o

stay_management.o: src/stay_management.c
	$(CC) -ansi -pedantic -Wall -c src/stay_management.c -o build/stay_management.o

test.o: test/src/test.c
	$(CC) -ansi -pedantic -Wall -c test/src/test.c -o build/test.o

tests: Stay_Dine_Employee.o dine_management.o employee_management.o stay_management.o
	$(CC) -ansi -pedantic -Wall -o bin/hotel_management build/Stay_Dine_Employee.o
	$(CC) -ansi -pedantic -Wall -o bin/test build/test.o



#CLEAN COMMANDS
clean:
	rm -rf build
	rm -rf bin
