# Makefile для праекта PATIENT

bin/main: obj/main.o obj/patient.o
	gcc -o bin/main obj/main.o obj/patient.o

obj/main.o: src/main.c include/patient.h
	gcc -c src/main.c -o obj/main.o

obj/patient.o: src/patient/patient.c include/patient.h
	gcc -c src/patient/patient.c -o obj/patient.o

clean:
	rm -f obj/* bin/*
