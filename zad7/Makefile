all:
	cc baza.c main.c -o mydb

test: all
	./mydb baza.csv list_students 

test-memory:all
	valgrind ./mydb baza1.csv add_student Maciek Szmatko 707070 szmatkom@o2.pl baza1.csv

test1:all
	valgrind ./mydb baza1.csv add_course 1DM7453 Mechanika_cząstek_niematerialnych 2090Z baza1.csv

test2:all
	valgrind ./mydb baza1.csv add_student_to_course 123456 1DM4321 5 Świetnie! baza1.csv