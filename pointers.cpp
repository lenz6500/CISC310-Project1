// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv){

    Student student;
    double average;
	char placehldr[128];
	int isValid;
	int decimal;

	student.f_name = (char*)malloc(sizeof(char)*128);
	student.l_name = (char*)malloc(sizeof(char)*128);

	student.id = -1;

	while(student.id == -1){

		std::cout << "Please enter the student's id number: ";
		
		std::cin >> placehldr;
		isValid = 1;
		for(int i = 0; i < strlen(placehldr); i++){
			if(isdigit(placehldr[i]) == false){
				isValid = 0;
			}
		}

		if(isValid == 1){
	
			student.id = atoi(placehldr);

			if(student.id < 0){
				std::cout << "Sorry, I cannot understand your answer" << std::endl;
				student.id = -1;
			}
			if(student.id > 100000000){
				std::cout << "Sorry, I cannot understand your answer" << std::endl;
				student.id = -1;
			}
		} else {
			std::cout << "Sorry, I cannot understand your answer" << std::endl;
		}
	}

	std::cout << "Please enter the student's first name: ";
	std::cin >> student.f_name;

	std::cout << "Please enter the student's last name: ";
	std::cin >> student.l_name;

	student.n_assignments = -1;
	while(student.n_assignments == -1){

		std::cout << "Please enter how many assignments were graded: ";

		std::cin >> placehldr;
		isValid = 1;
		for(int i = 0; i < strlen(placehldr); i++){
			if(isdigit(placehldr[i]) == false){
				isValid = 0;
			}
		}

		if(isValid == 1){
	
			student.n_assignments = atoi(placehldr);

			if(student.n_assignments  <= 0){
				std::cout << "Sorry, I cannot understand your answer" << std::endl;
				student.n_assignments = -1;
			}
			if(student.n_assignments  > 2147483647){
				std::cout << "Sorry, I cannot understand your answer" << std::endl;
				student.n_assignments = -1;
			}
		} else {
			std::cout << "Sorry, I cannot understand your answer" << std::endl;
		}
	}

	student.grades = (double*)malloc(sizeof(double)*student.n_assignments);

	std::cout << std::endl;

	for(int i = 0; i < student.n_assignments; i++){

		student.grades[i] = -1;
		while(student.grades[i] == -1){
			std::cout << "Please enter grade for assignment ";
			std::cout << i;
			std::cout << ": ";

			std::cin >> placehldr;
			isValid = 1;
			decimal = 0;		

			for(int i = 0; i < strlen(placehldr); i++){
		
				if(isdigit(placehldr[i]) == false){
					if(placehldr[i] == '.'){
						if(decimal == 0){
							decimal ++;
						} else {
							isValid = 0;
						}
					} else {
						isValid = 0;
					}
				}
			}

			if(isValid == 1){
		
				student.grades[i] = atof(placehldr);
				if(student.grades[i] < 0){
					std::cout << "Sorry, I cannot understand your answer" << std::endl;
					student.grades[i] = -1;
				}
				if(student.grades[i] >= 1000){
					std::cout << "Sorry, I cannot understand your answer" << std::endl;
					student.grades[i] = -1;
				}
			} else {
			std::cout << "Sorry, I cannot understand your answer" << std::endl;
			}
		}	
	}
	std::cout << std::endl;

	average = 0;
    calculateStudentAverage(&student, &average);

	std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
	std::cout << "  Average grade: ";

	average = floor(average*10+0.5)/10;

	std::cout << average << std::endl;

    return 0;
}

void calculateStudentAverage(void *object, double *avg){

	double total;
	total = 0;

	for(int i = 0; i < ((Student*)object)->n_assignments; i++){
		
		total = total + ((Student*)object)->grades[i];
		*avg = total;
		*avg = *avg / ((Student*)object)->n_assignments;
	}

}
