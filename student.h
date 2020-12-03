#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#define _CRT_SECURE_NO_WARNINGS    // scanf()

//1. header file
#include <stdio.h>
#include <string.h>					//	strcmp()

//2. constant
#define MAX_MAIN_MENU			7
#define	MAX_CHOICE_MENU			3
#define MAX_STUDENT				50
#define MAX_CHAR				30
#define INPUT_STUDENT_TEXT_FILE	"student.txt"
//3. data structure(자료형)       <-- 1번째 할일
// typedef struct student {}     학생을 위한 데이터 형 준비
struct student {					//object, entity, class
	int		studentID;				//학번
	char	studentName[MAX_CHAR];		//이름
	char	studentDept[MAX_CHAR];		//학과
	char    studentEmail[MAX_CHAR];		//e-mail
	char	studentPhone[MAX_CHAR];		//전화번호
	int		studentYear;			//학년  ...  student_year   ,  stu_year
};
typedef struct student tStudent;    // 학생을 위한 사용자 정의 자료형 선언


//4. global variable(전역변수)  --> 권하지 않음  error codes


//5. function prototype				<-- 2번째 할일(매뉴를 만들기-정보구조도)
int choiceMainMenu(const int max);
int choiceSearchMenu(int* choice);
int insertStudent(tStudent arrary[], int* length, const int max);    // insert_student() 입력
int insertStudentFromKeyboard(tStudent array[], int* length, const int max);
int insertStudentFromTextFile(char textFileName[], tStudent array[], int* length, const int max);
int deleteStudent(tStudent* array, int* length, const int max);	// 삭제
int modifyStudent(tStudent array[], const int length);	// 수정
int printStudent(tStudent array[], const int length);		// 출력
int searchStudent(tStudent array[], const int length);	// 검색   --> 하위 메뉴가 있어야함
int searchStudentByID(tStudent array[], const int length);
int searchStudentByName(tStudent array[], const int length);
int searchStudentByYear(tStudent array[], const int length);
int saveStudent(char* binFileName, tStudent array[], int length);		// 저장
int loadStudent(char* binFileName, tStudent array[], const int max);		// 불러오기


#endif    // endif _STUDENT_H_