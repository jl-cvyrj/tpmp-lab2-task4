# Overview
Repository for task 4 of laboratory work 2.
Contains data structure "PATIENT" with fields:
- last name, first name, patronymic
- gender, nationality
- height, weight
- date of birth (year, month, day)
- phone number
- home address (postal code, country, region, district, city, street, house, apartment)
- hospital number, department
- medical card number
- diagnosis, blood type

The program displays data about patients from department 4.

# Author
*Karalina Paulouskaya, group 10*

# Usage
The program works via command line. Supported commands:
- ```make``` - compile the program
- ```./bin/main``` - run the program (displays patients from department 4)
- ```make clean``` - remove temporary files

Project structure:
- ```src/``` - source files (main.c, patient.c)
- ```include/``` - header files (patient.h)
- ```bin/``` - executable files
- ```Makefile``` - build script

# Additional Notes
Program is written in C language.
Patient data is stored in an array of structures.
Filtering by department number (4) is implemented during output.
This repository is used as a submodule in the main laboratory work repository.
