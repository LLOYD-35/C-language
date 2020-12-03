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
//3. data structure(�ڷ���)       <-- 1��° ����
// typedef struct student {}     �л��� ���� ������ �� �غ�
struct student {					//object, entity, class
	int		studentID;				//�й�
	char	studentName[MAX_CHAR];		//�̸�
	char	studentDept[MAX_CHAR];		//�а�
	char    studentEmail[MAX_CHAR];		//e-mail
	char	studentPhone[MAX_CHAR];		//��ȭ��ȣ
	int		studentYear;			//�г�  ...  student_year   ,  stu_year
};
typedef struct student tStudent;    // �л��� ���� ����� ���� �ڷ��� ����


//4. global variable(��������)  --> ������ ����  error codes


//5. function prototype				<-- 2��° ����(�Ŵ��� �����-����������)
int choiceMainMenu(const int max);
int choiceSearchMenu(int* choice);
int insertStudent(tStudent arrary[], int* length, const int max);    // insert_student() �Է�
int insertStudentFromKeyboard(tStudent array[], int* length, const int max);
int insertStudentFromTextFile(char textFileName[], tStudent array[], int* length, const int max);
int deleteStudent(tStudent* array, int* length, const int max);	// ����
int modifyStudent(tStudent array[], const int length);	// ����
int printStudent(tStudent array[], const int length);		// ���
int searchStudent(tStudent array[], const int length);	// �˻�   --> ���� �޴��� �־����
int searchStudentByID(tStudent array[], const int length);
int searchStudentByName(tStudent array[], const int length);
int searchStudentByYear(tStudent array[], const int length);
int saveStudent(char* binFileName, tStudent array[], int length);		// ����
int loadStudent(char* binFileName, tStudent array[], const int max);		// �ҷ�����


#endif    // endif _STUDENT_H_