#include "student.h"

//  �ڷᱸ�� (�迭)
// tStudent gComputer[MAX_STUDENT];	// 50���� �л��� �����ϱ� ���� �迭 ����
// 50�� �л��� �����ϱ� ���� �������� ����(X)--> pointer
int choiceMenu(const int menuMax)                  //�Լ�����

{
    int select;
    printf("\t\t\t  �л����� ���α׷�\n\n");
    printf("\t\t      ------------------------\n\n");
    printf("\t\t\t1. �л� �Է�\n");
    printf("\t\t\t2. �л� ����\n");
    printf("\t\t\t3. �л� ����\n");
    printf("\t\t\t4. �л� ���\n");
    printf("\t\t\t5. �л� �˻�\n");
    printf("\t\t\t6. �л� �ڷ� �ҷ�����\n");
    printf("\t\t\t7. �л� �ڷ� �����ϱ�\n");
    printf("\t\t\t0. ���α׷� ����\n\n");
    printf("\t\t   # ���ϴ� ��ȣ�� �����ϼ��� ==>");
    scanf("%d", &select);
    if ((select >= 0) && (select <= menuMax))          //gSelect�� 0���� ũ�ų� ���� 7���� �۰ų� ���� ��찡 �ƴϸ� "�߸� �Է��ϼ˽��ϴ�." ���
    {

    }
    else
    {
        printf("\t\t\t\a�߸� �Է��ϼ̽��ϴ�.\n");
    }
    return select;                //select ��ȯ
}
/*
    �Լ� ����   :   �л� �˻� �޴� ����ϴ� �Լ�
    ���� ����   :
        - choice     :   ������ �޴� ��ȣ ����
*/
int choiceSearchMenu(int* choice)
{
    printf("\n\t\t\t ��  ��   ��   ��\n\n");
    printf("\t\t-----------------------------------\n\n");
    printf("\t\t\t1. �й����� �˻�\n");
    printf("\t\t\t2. �̸����� �˻�\n");
    printf("\t\t\t3. �г����� �˻�\n");
    printf("\t\t\t0. ���� �޴��� ���ư���\n\n");
    printf("\t\t   # ���ϴ� ��ȣ�� �����ϼ��� ==>");
    scanf("%d", choice);
    if ((0 <= *choice) && (*choice <= MAX_CHOICE_MENU))
    {
        return 1;
    }
    else
    {
        printf("\t\t\t\a�߸� �Է��ϼ̽��ϴ�.\n");
        return -1;
    }
}
/*
    �Լ� ����   :   �л� �Է� �޴� ����ϴ� �Լ�
    ���� ����   :
        - choice     :   ������ �޴� ��ȣ ����
*/
int choiceInsertMenu(const int menuMax)                  //�Լ�����

{
    int select;
    printf("\n\t\t\t  ��   ��   ��   ��\n\n");
    printf("\t\t      ------------------------\n\n");
    printf("\t\t\t1. �����Է� (Ű����)\n");
    printf("\t\t\t2. �ؽ�Ʈ���Ϸ� �Է��ϱ�\n");
    printf("\t\t\t0. ���� �޴��� ���ư���\n\n");
    printf("\t\t   # ���ϴ� ��ȣ�� �����ϼ��� ==>");
    scanf("%d", &select);
    if ((select >= 0) && (select <= menuMax))
    {

    }
    else
    {
        printf("\t\t\t\a�߸� �Է��ϼ̽��ϴ�.\n");
    }
    return select;  //select ��ȯ
}
/*
    �Լ� ����   :   �л��迭�� �л� �����͸� �Է��ϴ� �Լ�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
        - max       :   �迭�� �ִ�ũ��
*/
//  int insertStudent(tStudent *array, int length,const int max) ������ �ǹ� �����ͻ��

int insertStudentFromKeyboard(tStudent array[], int* length, const int max) {  // �迭�� ���      �Լ��� ���ڿ��� max�� �ٲ�� �ȵǴ� const Ű���� ��� 
    tStudent    st;         //�л����� �Է��� ���� ���� ����
    //  1.  �迭�� ���ִ� ���� �˻��Ѵ�. (full)
    if (*length == max)
    {
        printf("�л��迭�� �����ֽ��ϴ�.(full)\n");
        return -1;
    }
    //  2.  �л��ڷ� �Է�.
    printf("\n #�л��� �й��� �Է��ϼ��� :");
    scanf("%d", &st.studentID);
    printf("\n #�л��� �̸��� �Է��ϼ��� :");
    scanf("%s", st.studentName);
    printf("\n #�л��� �г��� �Է��ϼ��� :");
    scanf("%d", &st.studentYear);
    //  3.  �л��迭�� �Էµ� �л��ڷ� �߰�.
    array[*length] = st;
    //  4.  length++
    (*length)++;

    return 1;
}
/*
    �Լ� ����   :   �л������� ����Ǿ� �ִ� �ؽ�Ʈ���Ͽ��� �л������� �Է� �޾Ƽ�
                    �л��迭�� �Է��ϴ� �Լ�
    ���� ����   :
        - textFileName  :   �л��ڷᰡ ����Ǿ� �ִ� �ؽ�Ʈ ���� �̸�
        - array         :   �л��迭
        - length        :   �迭�� ����� �л���
        - max           :   �迭�� �ִ�ũ��
*/
int insertStudentFromTextFile(const char textFileName[], tStudent array[], int* length, const int max)
{
    FILE* fp;
    tStudent st;
    int index;
    //  1.  �ؽ�Ʈ ������ �����Ѵ�.   fopen()
    if ((fp = fopen(textFileName, "r")) == NULL)
    {
        printf("�л��Է����� : %s fopen() ������ �߻��Ͽ����ϴ�\n", textFileName);

        return -1;
    }
    //  2.  ���Ͽ��� �����͸� �о �л������� �Է��Ѵ�.
    while (!feof(fp))
    {
        fscanf(fp, "%d %d %s", &st.studentID, &st.studentYear, st.studentName);    // text file�� ������ ����    "201810031 1 kim"
        if (*length == max)
        {
            return -2;
        }
        else
        {
            array[*length] = st;
            (*length)++;
        }
    }
    for (index = 0; index < *length; index++)
    {
        printf("\n %d ��° �л�\n", index + 1);
        printf(" * �й� : %d\n", array[index].studentID);
        printf(" * �̸� : %s\n", array[index].studentName);
        printf(" * �г� : %d\n", array[index].studentYear);

    }
    fclose(fp);
    return 1;
}
//  3.  �л������� ���� �迭�� ����
//  4.  ���Ͽ��� �л��� ������ �� �ִ� ���� �˻��Ѵ�.  (������ ���� ���� �ߴ°�?)    feof()
//  5.1  ���� ���Ͽ� �л� �����Ͱ� ������ --> 2�����ΰ� ��
//  5.2 ������ --> ����  (�Էµ� ������ ����ϰ� ����)


/*
    �Լ� ����   :   �л��迭�� �л� �����͸� �Է��ϴ� �޴�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
        - max       :   �迭�� �ִ�ũ��
*/
int insertStudent(tStudent array[], int* length, const int max)
{
    int     choice;

    //  1.  �л��Է¸޴��� ����Ѵ�.   
    //  2.  �޴��� �����Ѵ�.   (1,2,0)
    choice = choiceInsertMenu(2);
    //  3.  �л� �Է� �޴��� ����
    //      3.1 �����Է��ϱ�  --> ���� �Լ� ���
    //      3.2 �ؽ�Ʈ���Ϸ� �Է��ϱ�
    switch (choice) {
    case 1:
        insertStudentFromKeyboard(array, length, max);
        break;
    case 2:
        insertStudentFromTextFile(INPUT_STUDENT_TEXT_FILE, array, length, max);
        break;
    default:
        break;
    }
    return 1;
}

/*
    �Լ� ����   :   �л��迭�� �л� �����͸� �����ϴ� �޴�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
        - max       :   �迭�� �ִ�ũ��
*/
int deleteStudent(tStudent* array, int* length, const int max)
{
    char    studentName[30];
    int index, j;                  //������ �л��� ��ġ�� ã�� ���� ����
    char select = 0;
    //  1.  �л��迭 empty --> return
    if (*length == 0) {
        printf("\n �迭�� ������ �����Ͱ� �����ϴ�. \n");
        return 0;
    }
    //  2.  ������ �л��� �̸� �Է¹ޱ� (scanf() --> gets())
    printf("\n # ������ �л��� �̸��� �Է��ϼ��� :");
    scanf("%s", studentName);
    //  3.  ������ �л� ��ġ �˻�    (0 ~ length - 1)
    for (index = 0; index < *length; index++)
    {
        //      3.1 ������ �л� �߰�
        if (strcmp(studentName, array[index].studentName) == 0)
            //if (!strcmp(studentName, array[index].studentName)    ���������� ��κ� �̷��� ���
        {
            //          3.1.1   ������ �л��� ������ ���
            printf("\n %d ��° �л�\n", index + 1);
            printf(" * �й� : %d\n", array[index].studentID);
            printf(" * �̸� : %s\n", array[index].studentName);
            printf(" * �г� : %d\n", array[index].studentYear);

            //          (3.1.2   �����ðڽ��ϱ�?(Y/N)-->report)
            printf("\n # �л� �����͸� �����Ͻðڽ��ϱ�? (Y/N)  ==>");
            getchar();  //�Է� ���۸� ���� ����.
            scanf("%c", &select);      //scanf �Է��� ���� ���� ����
            if (select == 'Y' || select == 'y')
            {
                //          3.1.3   �迭���� �л� ������ ����  [j] <- [j+1]    
                for (j = index; j < *length; j++)
                {
                    array[j] = array[j + 1];
                }
                //  3.1.4   �л��� ����--
                (*length)--;        //  *length= *length-1;
                printf("\n�̸��� %s�� �л��� �����Ǿ����ϴ�.\n", studentName);
                return 1;           //  ���� �Ϸ�
            }
            else if (select == 'N' || select == 'n')
            {
                deleteStudent(array, length, max);
                break;
            }


        }
    }
    //  4. ������ �л��� �߰����� ���� ��� (3.2) length  -->return (x) ������ ������ �����Ͻðڽ��ϱ� ���(Y/N) --> 2������ (������� �����ؾ��� ����!!)
    if (index == *length)
    {
        //      4.1 �޽��� ����� ����
        printf("\n # �̸��� %s�� �л��� �������� �ʽ��ϴ�.\n", studentName);

        return 1;
    }
    return 1;
}
/*
    �Լ� ����   :   �л��迭�� �л� �����͸� �����ϴ� �Լ�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int modifyStudent(tStudent array[], const int length)
{
    int index, studentId;
    tStudent st;
    //  1.  �迭�� ����ִ°��� �˻��Ѵ�.    (empty)
    if (length == 0) {
        printf("\n �迭�� �����Ͱ� �����ϴ�. \n");
        return 0;
    }
    //  2.  ������ �л��� �й��� �Է¹ޱ�.
    printf("\n # �˻��� �л��� �й��� �Է��ϼ��� :");
    scanf("%d", &studentId);
    //  3.  �л��迭���� �ش� �л� ã��.
    for (index = 0; index < length; index++)
    {
        //      3.1 ������ �л� ã�� ��� �л��ڷ� ���
        if (studentId == array[index].studentID)
        {
            printf("\n %d ��° �л�\n", index + 1);
            printf(" * �й� : %d\n", array[index].studentID);
            printf(" * �̸� : %s\n", array[index].studentName);
            printf(" * �г� : %d\n", array[index].studentYear);
            //      3.2 ������ �л� ���� �Է�
            printf("\n #�л��� �й��� �Է��ϼ��� :");
            scanf("%d", &st.studentID);                     // scanf("%d",&array[index].studentID); �̹���� ���� �ٲٴ� ���ε� �������ƾ� �Ѵ� ���� ������ �ջ�� ���� ����
            printf("\n #�л��� �̸��� �Է��ϼ��� :");
            scanf("%s", st.studentName);
            printf("\n #�л��� �г��� �Է��ϼ��� :");
            scanf("%d", &st.studentYear);
            //      3.3 �Է��� �л������� �л��迭�� ����
            array[index] = st;
            //      3.4 return(����)
            return 1;
        }
    }
    //  4.  ������ �л��� �� ã�� ��� 
    if (index == length)
    {
        //      4.1 �޽��� ����� ����
        printf("\n # �й��� %d�� �л��� �����ϴ�.\n", studentId);
        return -1;
    }
    return 1;
}
/*
    �Լ� ����   :    �л������͸� ����ϴ� �Լ�
        ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/

int printStudent(tStudent array[], const int length)
{
    int index;
    //  1.  �迭�� ����ִ°��� �˻��Ѵ�. (empty)
    if (length == 0) {
        printf("\n �迭�� �����Ͱ� �����ϴ�. \n");
        return 0;
    }
    //  2.  �迭�� �л������͸� ���. (0 ~ length)
    for (index = 0; index < length; index++)
    {
        printf("\n %d ��° �л�\n", index + 1);
        printf(" * �й� : %d\n", array[index].studentID);
        printf(" * �̸� : %s\n", array[index].studentName);
        printf(" * �г� : %d\n", array[index].studentYear);
    }
    return 1;
}
/*
    �Լ� ����   :   �л��迭���� �Է� ���� �й����� �л��� �˻��ϴ� �Լ�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int searchStudent(tStudent array[], const int length)
{
    int choice = 0;
    choiceSearchMenu(&choice);
    switch (choice) {
    case 1:
        searchStudentByID(array, length);
        break;
    case 2:
        searchStudentByName(array, length);
        break;
    case 3:
        searchStudentByYear(array, length);
    default:
        break;
    }
    return 1;
}
/*
    �Լ� ����   :   �л��迭���� �Է� ���� �й����� �л��� �˻��ϴ� �Լ�
    ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int searchStudentByID(tStudent array[], const int length)
{
    int index, studentId;
    //  1.  �迭�� empty Ȯ��    (length==0)
    if (length == 0) {
        printf("\n �迭�� �����Ͱ� �����ϴ�. \n");
        return 0;
    }
    //  2.  �˻��� �л��� �й��� �Է¹ޱ�
    printf("\n # �˻��� �л��� �й��� �Է��ϼ��� :");
    scanf("%d", &studentId);
    //  3.  �л��迭���� �ش� �л��� ã��    (0 ~ length-1)
    for (index = 0; index < length; index++)
    {
        //      3.1 �л��� �����ϸ� �л��ڷ� ���
        if (studentId == array[index].studentID) {          // ���� ==/    name ==> (strcmp(studentName, array[index].studentName)==0)  �Ǵ� !strcmp(studentName, array[index].studentName�� ��� �ؾ���.
            printf("\n %d ��° �л�\n", index + 1);
            printf(" * �й� : %d\n", array[index].studentID);
            printf(" * �̸� : %s\n", array[index].studentName);
            printf(" * �г� : %d\n", array[index].studentYear);
            return 1;
        }
    }
    //  4.  �ش��л��� ���� ���(for�� ������ ����)
    if (index == length)    //for�� ������ ����ٸ� ���ϴ� ���� �� ã����.
    {
        printf("\n # �й��� %d�� �л��� �����ϴ�.\n", studentId);
        return -1;
    }
    return 1;
}
/*
    �Լ� ����   :    �л��迭���� �Է� ���� �̸����� �л��� �˻��ϴ� �Լ�
        ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int searchStudentByName(tStudent array[], const int length)
{
    int index;
    char studentName[30] = { 0, };
    //  1.  �迭�� empty Ȯ��
    if (length == 0)
    {
        printf("\n �迭�� �����Ͱ� �����ϴ�.\n");
        return 0;
    }
    //  2.  �˻��� �л��� �̸��� �Է¹ޱ�
    printf("\n # �˻��� �л��� �̸��� �Է��ϼ��� :");
    scanf("%s", studentName);
    //  3.  �л��迭���� �ش� �л� �˻��ϱ�
    for (index = 0; index < length; index++)
    {
        //  3.1 �л��� �����ϸ� �л��ڷ� ���
        if (!strcmp(array[index].studentName, studentName))
        {
            printf("\n %d ��° �л�\n", index + 1);
            printf(" * �й� : %d\n", array[index].studentID);
            printf(" * �̸� : %s\n", array[index].studentName);
            printf(" * �г� : %d\n", array[index].studentYear);
            return 1;
        }
    }
    //  4.  �迭�� �ش��ϴ� �л��� �־����� Ȯ��.
    if (length == index)
    {
        printf("\n # �̸��� %s�� �л��� �����ϴ�.\n", studentName);
        return -1;
    }
    return 1;
}
/*
    �Լ� ����   :    �л��迭���� �Է� ���� �г����� �л��� �˻��ϴ� �Լ�
        ���� ����   :
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int searchStudentByYear(tStudent array[], const int length)
{
    int index, studentYear;
    int count = 0;
    //  1.  �迭�� empty Ȯ��
    if (length == 0) {
        printf("\n �迭�� �����Ͱ� �����ϴ�. \n");
        return 0;
    }
    //  2.  �˻��� �л��� �г� �Է¹ޱ�
    printf("\n # �˻��� �л��� �г��� �Է��ϼ��� :");
    scanf("%d", &studentYear);
    //  3.  �л��迭���� �ش� �л� �˻��ϱ�
    for (index = 0; index < length; index++)
    {
        //  3.1 �л��� �迭�� �ִ°�� ���
        if (array[index].studentYear == studentYear)
        {
            printf("\n %d ��° �л�\n", index + 1);
            printf(" * �й� : %d\n", array[index].studentID);
            printf(" * �̸� : %s\n", array[index].studentName);
            printf(" * �г� : %d\n", array[index].studentYear);
            count++;        //�г��� ���� �л��� count
        }

    }
    //  4.  �迭�� �ش��ϴ� �л��� �־����� �˻�.
    if (count == 0)     //for���� �������ö� count�� �ʱ�ȭ �� �״�� 0�̸� ã�� ���Ѱ�.
    {
        printf("\n # �г��� %d�� �л��� �����ϴ�.\n", studentYear);
        return -1;
    }
    else            //for���� ������������ 0�� �ƴϸ� ã����.
    {
        printf("\n # �г��� %d�� �л��� %d�� ã�ҽ��ϴ�.\n", studentYear, count);
        return 1;
    }
    return 1;
}
/*
    �Լ� ����   :    �л��迭�� �����͸� �������Ͽ� �����ϴ� �Լ�
        ���� ����   :
        - binFileName: �����Ϸ��� ���������� �̸�
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���
*/
int saveStudent(char* binFileName, tStudent array[], int length) {
    FILE* binFp;
    int index;
    //  1.  ���������� �����Ѵ�. ("wb")
    if ((binFp = fopen(binFileName, "wb")) == NULL)
    {
        printf("\n �������� : %s ���� �����Դϴ�.\n", binFileName);
        perror("\n sveStudent() ���� :");
        return -1;
    }
    //  2.  �л��迭���� �л������͸� �������Ͽ� �����Ѵ�.
    //      ( 0 ~ length)
    for (index = 0; index < length; index++)
    {
        fwrite(&array[index], sizeof(tStudent), 1, binFp);
    }
    printf(" �������� %s�� %d���� �л� ������ ������ �Ǿ����ϴ�.\n", binFileName, length);
    //  3.  ���������� �ݴ´�.
    fclose(binFp);
    return 1;
}
/*
    �Լ� ����   :    �������Ͽ��� �л� �����͸� �л��迭�� �о���̴� �Լ�
    ���� ����   :
        - binFileName: �����Ϸ��� ���������� �̸�
        - array     :   �л��迭
        - length    :   �迭�� ����� �л���     // �ʿ�� ����
        - max       :   �л��迭�� �ִ� ũ��
    return  :   �������Ͽ��� ���� �л� �������� ����
*/
int loadStudent(char* binFileName, tStudent array[], const int max)
{
    FILE* binfp;
    tStudent st;    //�������Ͽ��� �о�� �����͸� ���� �л�����

    int count = 0;  //�������Ͽ��� �о�� �л���
    //  1.  �������� �����Ѵ�. ("rb")
    if ((binfp = fopen(binFileName, "rb")) == NULL)
    {
        printf("\n �������� : %s ���� �����Դϴ�.\n", binFileName);
        perror("\n sveStudent() ���� :");
        return -1;
    }
    //  2.  �������Ͽ��� �л������͸� �д´�.  
    //fwite(&array[index], sizeof(tStudent), 1, binfp);
    fread(&st, sizeof(tStudent), 1, binfp);
    //  5.  ������ ���ΰ��� üũ feof()
    while (!feof(binfp))    //while (fread()=feof())
    {

        //  3.  �л��迭�� �ִ� ũ�⸦ �ʰ��ϴ��� Ȯ��
        if (count >= max)   //�������Ͽ��� ���� �л����� �迭�� ũ�⸦ �ʰ���
        {
            printf("\n �ε��� �л����� �迭�� �ִ�ũ��: %d�� �ʰ��߽��ϴ�.\n", max);
            //      3.2 �ʰ��ϸ� �Լ��� ����.
            return count;
        }
        //      3.1 �ʰ����� ������ �����͸� �迭�� �߰��Ѵ�. (count++)
        array[count] = st;      // array[count++] = st;
        count++;
        fread(&st, sizeof(tStudent), 1, binfp);
        //  4.  �������Ͽ��� ���� �����͸� �д´�. 
    }
    //Ʋ �ϱ� fread() ->while(!feof()) -> fread()
    //  5.1    feof()��  �ƴϸ� --3.1
    //   5.2   feof()�� �Լ� ����.
    printf("\n\n# �������� : %s���� %d���� �л� �����Ͱ� �ε��Ǿ����ϴ�.\n\n", binFileName, count);
    fclose(binfp);
    return count;
}

int main(void)
{
    tStudent computer[MAX_STUDENT];	// �л� ����ü �迭�� ���������� ���� **** ���� �߿��� �ڷᱸ��
    int studentCount = 0;           //  �迭�� �Էµ� �л���
    int select;
    char binFileName[40] = "student.bin";


    do {
        select = choiceMenu(MAX_MAIN_MENU);          //���� �޴� ���
        switch (select) {

        case 1:
            insertStudent(computer, &studentCount, MAX_STUDENT);        //  �л� �����͸� �Է��ϴ� �Լ� ȣ��
                        // ���       length          ����� define ���� �����ؼ� �Ƚ�� ��.

            break;
        case 2:
            deleteStudent(computer, &studentCount, MAX_STUDENT);
            break;
        case 3:
            modifyStudent(computer, studentCount);
            break;
        case 4:
            printStudent(computer, studentCount);
            break;
        case 5:
            searchStudent(computer, studentCount);
            break;
        case 6:
            studentCount = loadStudent(binFileName, computer, MAX_STUDENT);
            break;
        case 7:
            saveStudent(binFileName, computer, studentCount);   //�־�� �� ������ �迭�� �迭�� ������ ���� �� ���� �̸�
            break;
        default:
            break;
        }
    } while (!(select == 0));     //0�� ���Ḧ ������ ������ ����ؼ� �ݺ�
    return 0;
}
