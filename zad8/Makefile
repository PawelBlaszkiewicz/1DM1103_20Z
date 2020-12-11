all:
	cc main.c baza.c -o mydb

test: all
	./mydb bazaza.csv list_students 

test-1: all
	./mydb bazaza.csv sort+_students 

test-2: all
	./mydb bazaza.csv sort-_students

test-3: all
	./mydb bazaza.csv sort_course_cod

test-4: all
	./mydb bazaza.csv sort_course_name

test-5: all
	./mydb bazaza.csv choose_marks_bycode 1DE1234

test-6: all
	./mydb bazaza.csv choose_marks_bystudent 000007

test-memory:all
	valgrind ./mydb bazaza.csv add_student Maciek Szmatko 707070 szmatkom@o2.pl bazaza.csv

test1:all
	valgrind ./mydb bazaza.csv add_course 1DM7453 Mechanika_cząstek_niematerialnych 2090Z bazaza.csv

test2:all
	valgrind ./mydb bazaza.csv add_student_to_course 123456 1DM4321 5 Świetnie! bazaza.csv