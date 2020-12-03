#include "student.h"

//  자료구조 (배열)
// tStudent gComputer[MAX_STUDENT];	// 50명의 학생을 관리하기 위한 배열 선언
// 50명 학생을 관리하기 위한 전역변수 선언(X)--> pointer
int choiceMenu(const int menuMax)                  //함수구현

{
    int select;
    printf("\t\t\t  학생관리 프로그램\n\n");
    printf("\t\t      ------------------------\n\n");
    printf("\t\t\t1. 학생 입력\n");
    printf("\t\t\t2. 학생 삭제\n");
    printf("\t\t\t3. 학생 수정\n");
    printf("\t\t\t4. 학생 출력\n");
    printf("\t\t\t5. 학생 검색\n");
    printf("\t\t\t6. 학생 자료 불러오기\n");
    printf("\t\t\t7. 학생 자료 저장하기\n");
    printf("\t\t\t0. 프로그램 종료\n\n");
    printf("\t\t   # 원하는 번호를 선택하세요 ==>");
    scanf("%d", &select);
    if ((select >= 0) && (select <= menuMax))          //gSelect가 0보다 크거나 같고 7보다 작거나 같을 경우가 아니면 "잘못 입력하셧습니다." 출력
    {

    }
    else
    {
        printf("\t\t\t\a잘못 입력하셨습니다.\n");
    }
    return select;                //select 반환
}
/*
    함수 설명   :   학생 검색 메뉴 출력하는 함수
    인자 설명   :
        - choice     :   선택한 메뉴 번호 저장
*/
int choiceSearchMenu(int* choice)
{
    printf("\n\t\t\t 학  생   검   색\n\n");
    printf("\t\t-----------------------------------\n\n");
    printf("\t\t\t1. 학번으로 검색\n");
    printf("\t\t\t2. 이름으로 검색\n");
    printf("\t\t\t3. 학년으로 검색\n");
    printf("\t\t\t0. 메인 메뉴로 돌아가기\n\n");
    printf("\t\t   # 원하는 번호를 선택하세요 ==>");
    scanf("%d", choice);
    if ((0 <= *choice) && (*choice <= MAX_CHOICE_MENU))
    {
        return 1;
    }
    else
    {
        printf("\t\t\t\a잘못 입력하셨습니다.\n");
        return -1;
    }
}
/*
    함수 설명   :   학생 입력 메뉴 출력하는 함수
    인자 설명   :
        - choice     :   선택한 메뉴 번호 저장
*/
int choiceInsertMenu(const int menuMax)                  //함수구현

{
    int select;
    printf("\n\t\t\t  학   생   입   력\n\n");
    printf("\t\t      ------------------------\n\n");
    printf("\t\t\t1. 직접입력 (키보드)\n");
    printf("\t\t\t2. 텍스트파일로 입력하기\n");
    printf("\t\t\t0. 메인 메뉴로 돌아가기\n\n");
    printf("\t\t   # 원하는 번호를 선택하세요 ==>");
    scanf("%d", &select);
    if ((select >= 0) && (select <= menuMax))
    {

    }
    else
    {
        printf("\t\t\t\a잘못 입력하셨습니다.\n");
    }
    return select;  //select 반환
}
/*
    함수 설명   :   학생배열에 학생 데이터를 입력하는 함수
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
        - max       :   배열의 최대크기
*/
//  int insertStudent(tStudent *array, int length,const int max) 동일한 의미 포인터사용

int insertStudentFromKeyboard(tStudent array[], int* length, const int max) {  // 배열을 사용      함수의 인자에서 max는 바뀌면 안되니 const 키워드 사용 
    tStudent    st;         //학생정보 입력을 위한 변수 선언
    //  1.  배열이 차있는 가를 검사한다. (full)
    if (*length == max)
    {
        printf("학생배열이 꽉차있습니다.(full)\n");
        return -1;
    }
    //  2.  학생자료 입력.
    printf("\n #학생의 학번을 입력하세요 :");
    scanf("%d", &st.studentID);
    printf("\n #학생의 이름을 입력하세요 :");
    scanf("%s", st.studentName);
    printf("\n #학생의 학년을 입력하세요 :");
    scanf("%d", &st.studentYear);
    //  3.  학생배열에 입력된 학생자료 추가.
    array[*length] = st;
    //  4.  length++
    (*length)++;

    return 1;
}
/*
    함수 설명   :   학생정보가 저장되어 있는 텍스트파일에서 학생정보를 입력 받아서
                    학생배열에 입력하는 함수
    인자 설명   :
        - textFileName  :   학생자료가 저장되어 있는 텍스트 파일 이름
        - array         :   학생배열
        - length        :   배열에 저장된 학생수
        - max           :   배열의 최대크기
*/
int insertStudentFromTextFile(const char textFileName[], tStudent array[], int* length, const int max)
{
    FILE* fp;
    tStudent st;
    int index;
    //  1.  텍스트 파일을 오픈한다.   fopen()
    if ((fp = fopen(textFileName, "r")) == NULL)
    {
        printf("학생입력파일 : %s fopen() 오류가 발생하였습니다\n", textFileName);

        return -1;
    }
    //  2.  파일에서 데이터를 읽어서 학생변수에 입력한다.
    while (!feof(fp))
    {
        fscanf(fp, "%d %d %s", &st.studentID, &st.studentYear, st.studentName);    // text file의 순서와 동일    "201810031 1 kim"
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
        printf("\n %d 번째 학생\n", index + 1);
        printf(" * 학번 : %d\n", array[index].studentID);
        printf(" * 이름 : %s\n", array[index].studentName);
        printf(" * 학년 : %d\n", array[index].studentYear);

    }
    fclose(fp);
    return 1;
}
//  3.  학생변수의 값을 배열에 저장
//  4.  파일에서 학생의 정보가 더 있는 가를 검색한다.  (파일의 끝에 도달 했는가?)    feof()
//  5.1  만약 파일에 학생 데이터가 있으면 --> 2번으로가 감
//  5.2 없으면 --> 리턴  (입력된 정보를 출력하고 리턴)


/*
    함수 설명   :   학생배열에 학생 데이터를 입력하는 메뉴
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
        - max       :   배열의 최대크기
*/
int insertStudent(tStudent array[], int* length, const int max)
{
    int     choice;

    //  1.  학생입력메뉴를 출력한다.   
    //  2.  메뉴를 선택한다.   (1,2,0)
    choice = choiceInsertMenu(2);
    //  3.  학생 입력 메뉴를 실행
    //      3.1 직접입력하기  --> 기존 함수 사용
    //      3.2 텍스트파일로 입력하기
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
    함수 설명   :   학생배열에 학생 데이터를 삭제하는 메뉴
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
        - max       :   배열의 최대크기
*/
int deleteStudent(tStudent* array, int* length, const int max)
{
    char    studentName[30];
    int index, j;                  //삭제할 학생의 위치를 찾기 위한 변수
    char select = 0;
    //  1.  학생배열 empty --> return
    if (*length == 0) {
        printf("\n 배열에 삭제할 데이터가 없습니다. \n");
        return 0;
    }
    //  2.  삭제할 학생의 이름 입력받기 (scanf() --> gets())
    printf("\n # 삭제할 학생의 이름을 입력하세요 :");
    scanf("%s", studentName);
    //  3.  삭제할 학생 위치 검색    (0 ~ length - 1)
    for (index = 0; index < *length; index++)
    {
        //      3.1 삭제할 학생 발견
        if (strcmp(studentName, array[index].studentName) == 0)
            //if (!strcmp(studentName, array[index].studentName)    실전에서는 대부분 이렇게 사용
        {
            //          3.1.1   삭제할 학생의 정보를 출력
            printf("\n %d 번째 학생\n", index + 1);
            printf(" * 학번 : %d\n", array[index].studentID);
            printf(" * 이름 : %s\n", array[index].studentName);
            printf(" * 학년 : %d\n", array[index].studentYear);

            //          (3.1.2   삭제시겠습니까?(Y/N)-->report)
            printf("\n # 학생 데이터를 삭제하시겠습니까? (Y/N)  ==>");
            getchar();  //입력 버퍼를 비우기 위함.
            scanf("%c", &select);      //scanf 입력을 위한 버퍼 비우기
            if (select == 'Y' || select == 'y')
            {
                //          3.1.3   배열에서 학생 데이터 삭제  [j] <- [j+1]    
                for (j = index; j < *length; j++)
                {
                    array[j] = array[j + 1];
                }
                //  3.1.4   학생수 감소--
                (*length)--;        //  *length= *length-1;
                printf("\n이름이 %s인 학생이 삭제되었습니다.\n", studentName);
                return 1;           //  삭제 완료
            }
            else if (select == 'N' || select == 'n')
            {
                deleteStudent(array, length, max);
                break;
            }


        }
    }
    //  4. 삭제할 학생을 발견하지 못한 경우 (3.2) length  -->return (x) 원래는 삭제를 종료하시겠습니까 물어봄(Y/N) --> 2번으로 (여기까지 구현해야함 연습!!)
    if (index == *length)
    {
        //      4.1 메시지 출력후 종료
        printf("\n # 이름이 %s인 학생이 존재하지 않습니다.\n", studentName);

        return 1;
    }
    return 1;
}
/*
    함수 설명   :   학생배열에 학생 데이터를 수정하는 함수
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/
int modifyStudent(tStudent array[], const int length)
{
    int index, studentId;
    tStudent st;
    //  1.  배열이 비어있는가를 검사한다.    (empty)
    if (length == 0) {
        printf("\n 배열에 데이터가 없습니다. \n");
        return 0;
    }
    //  2.  수정할 학생의 학번을 입력받기.
    printf("\n # 검색할 학생의 학번을 입력하세요 :");
    scanf("%d", &studentId);
    //  3.  학생배열에서 해당 학생 찾기.
    for (index = 0; index < length; index++)
    {
        //      3.1 수정할 학생 찾은 경우 학생자료 출력
        if (studentId == array[index].studentID)
        {
            printf("\n %d 번째 학생\n", index + 1);
            printf(" * 학번 : %d\n", array[index].studentID);
            printf(" * 이름 : %s\n", array[index].studentName);
            printf(" * 학년 : %d\n", array[index].studentYear);
            //      3.2 수정할 학생 정보 입력
            printf("\n #학생의 학번을 입력하세요 :");
            scanf("%d", &st.studentID);                     // scanf("%d",&array[index].studentID); 이방법은 직접 바꾸는 것인데 쓰지말아야 한다 메인 데이터 손상될 수도 있음
            printf("\n #학생의 이름을 입력하세요 :");
            scanf("%s", st.studentName);
            printf("\n #학생의 학년을 입력하세요 :");
            scanf("%d", &st.studentYear);
            //      3.3 입력한 학생정보를 학생배열에 변경
            array[index] = st;
            //      3.4 return(종료)
            return 1;
        }
    }
    //  4.  수정할 학생을 못 찾은 경우 
    if (index == length)
    {
        //      4.1 메시지 출력후 종료
        printf("\n # 학번이 %d인 학생은 없습니다.\n", studentId);
        return -1;
    }
    return 1;
}
/*
    함수 설명   :    학생데이터를 출력하는 함수
        인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/

int printStudent(tStudent array[], const int length)
{
    int index;
    //  1.  배열이 비어있는가를 검사한다. (empty)
    if (length == 0) {
        printf("\n 배열에 데이터가 없습니다. \n");
        return 0;
    }
    //  2.  배열의 학생데이터를 출력. (0 ~ length)
    for (index = 0; index < length; index++)
    {
        printf("\n %d 번째 학생\n", index + 1);
        printf(" * 학번 : %d\n", array[index].studentID);
        printf(" * 이름 : %s\n", array[index].studentName);
        printf(" * 학년 : %d\n", array[index].studentYear);
    }
    return 1;
}
/*
    함수 설명   :   학생배열에서 입력 받은 학번으로 학생을 검색하는 함수
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
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
    함수 설명   :   학생배열에서 입력 받은 학번으로 학생을 검색하는 함수
    인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/
int searchStudentByID(tStudent array[], const int length)
{
    int index, studentId;
    //  1.  배열이 empty 확인    (length==0)
    if (length == 0) {
        printf("\n 배열에 데이터가 없습니다. \n");
        return 0;
    }
    //  2.  검색할 학생의 학번을 입력받기
    printf("\n # 검색할 학생의 학번을 입력하세요 :");
    scanf("%d", &studentId);
    //  3.  학생배열에서 해당 학생을 찾기    (0 ~ length-1)
    for (index = 0; index < length; index++)
    {
        //      3.1 학생이 존재하면 학생자료 출력
        if (studentId == array[index].studentID) {          // 정수 ==/    name ==> (strcmp(studentName, array[index].studentName)==0)  또는 !strcmp(studentName, array[index].studentName를 사용 해야함.
            printf("\n %d 번째 학생\n", index + 1);
            printf(" * 학번 : %d\n", array[index].studentID);
            printf(" * 이름 : %s\n", array[index].studentName);
            printf(" * 학년 : %d\n", array[index].studentYear);
            return 1;
        }
    }
    //  4.  해당학생이 없는 경우(for문 밖으로 나옴)
    if (index == length)    //for문 루프를 벗어났다면 원하는 값을 못 찾은것.
    {
        printf("\n # 학번이 %d인 학생은 없습니다.\n", studentId);
        return -1;
    }
    return 1;
}
/*
    함수 설명   :    학생배열에서 입력 받은 이름으로 학생을 검색하는 함수
        인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/
int searchStudentByName(tStudent array[], const int length)
{
    int index;
    char studentName[30] = { 0, };
    //  1.  배열이 empty 확인
    if (length == 0)
    {
        printf("\n 배열에 데이터가 없습니다.\n");
        return 0;
    }
    //  2.  검색할 학생의 이름을 입력받기
    printf("\n # 검색할 학생의 이름을 입력하세요 :");
    scanf("%s", studentName);
    //  3.  학생배열에서 해당 학생 검색하기
    for (index = 0; index < length; index++)
    {
        //  3.1 학생이 존재하면 학생자료 출력
        if (!strcmp(array[index].studentName, studentName))
        {
            printf("\n %d 번째 학생\n", index + 1);
            printf(" * 학번 : %d\n", array[index].studentID);
            printf(" * 이름 : %s\n", array[index].studentName);
            printf(" * 학년 : %d\n", array[index].studentYear);
            return 1;
        }
    }
    //  4.  배열에 해당하는 학생이 있었는지 확인.
    if (length == index)
    {
        printf("\n # 이름이 %s인 학생은 없습니다.\n", studentName);
        return -1;
    }
    return 1;
}
/*
    함수 설명   :    학생배열에서 입력 받은 학년으로 학생을 검색하는 함수
        인자 설명   :
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/
int searchStudentByYear(tStudent array[], const int length)
{
    int index, studentYear;
    int count = 0;
    //  1.  배열이 empty 확인
    if (length == 0) {
        printf("\n 배열에 데이터가 없습니다. \n");
        return 0;
    }
    //  2.  검색할 학생의 학년 입력받기
    printf("\n # 검색할 학생의 학년을 입력하세요 :");
    scanf("%d", &studentYear);
    //  3.  학생배열에서 해당 학생 검색하기
    for (index = 0; index < length; index++)
    {
        //  3.1 학생이 배열에 있는경우 출력
        if (array[index].studentYear == studentYear)
        {
            printf("\n %d 번째 학생\n", index + 1);
            printf(" * 학번 : %d\n", array[index].studentID);
            printf(" * 이름 : %s\n", array[index].studentName);
            printf(" * 학년 : %d\n", array[index].studentYear);
            count++;        //학년이 같은 학생을 count
        }

    }
    //  4.  배열에 해당하는 학생이 있었는지 검사.
    if (count == 0)     //for문을 빠져나올때 count가 초기화 한 그대로 0이면 찾지 못한것.
    {
        printf("\n # 학년이 %d인 학생은 없습니다.\n", studentYear);
        return -1;
    }
    else            //for문을 빠져나왔을때 0이 아니면 찾은것.
    {
        printf("\n # 학년이 %d인 학생을 %d명 찾았습니다.\n", studentYear, count);
        return 1;
    }
    return 1;
}
/*
    함수 설명   :    학생배열의 데이터를 이진파일에 저장하는 함수
        인자 설명   :
        - binFileName: 저장하려는 이진파일의 이름
        - array     :   학생배열
        - length    :   배열에 저장된 학생수
*/
int saveStudent(char* binFileName, tStudent array[], int length) {
    FILE* binFp;
    int index;
    //  1.  이진파일을 오픈한다. ("wb")
    if ((binFp = fopen(binFileName, "wb")) == NULL)
    {
        printf("\n 이진파일 : %s 오픈 오류입니다.\n", binFileName);
        perror("\n sveStudent() 오류 :");
        return -1;
    }
    //  2.  학생배열에서 학생데이터를 이진파일에 저장한다.
    //      ( 0 ~ length)
    for (index = 0; index < length; index++)
    {
        fwrite(&array[index], sizeof(tStudent), 1, binFp);
    }
    printf(" 이진파일 %s에 %d명의 학생 정보가 저장이 되었습니다.\n", binFileName, length);
    //  3.  이진파일을 닫는다.
    fclose(binFp);
    return 1;
}
/*
    함수 설명   :    이진파일에서 학생 데이터를 학생배열로 읽어들이는 함수
    인자 설명   :
        - binFileName: 저장하려는 이진파일의 이름
        - array     :   학생배열
        - length    :   배열에 저장된 학생수     // 필요는 없음
        - max       :   학생배열의 최대 크기
    return  :   이진파일에서 읽은 학생 데이터의 개수
*/
int loadStudent(char* binFileName, tStudent array[], const int max)
{
    FILE* binfp;
    tStudent st;    //이진파일에서 읽어온 데이터를 위한 학생변수

    int count = 0;  //이진파일에서 읽어온 학생수
    //  1.  이진파일 오픈한다. ("rb")
    if ((binfp = fopen(binFileName, "rb")) == NULL)
    {
        printf("\n 이진파일 : %s 오픈 오류입니다.\n", binFileName);
        perror("\n sveStudent() 오류 :");
        return -1;
    }
    //  2.  이진파일에서 학생데이터를 읽는다.  
    //fwite(&array[index], sizeof(tStudent), 1, binfp);
    fread(&st, sizeof(tStudent), 1, binfp);
    //  5.  파일의 끝인가를 체크 feof()
    while (!feof(binfp))    //while (fread()=feof())
    {

        //  3.  학생배열의 최대 크기를 초과하는지 확인
        if (count >= max)   //이진파일에서 읽은 학생수가 배열의 크기를 초과함
        {
            printf("\n 로딩된 학생수가 배열의 최대크기: %d를 초과했습니다.\n", max);
            //      3.2 초과하면 함수를 종료.
            return count;
        }
        //      3.1 초과하지 않으면 데이터를 배열에 추가한다. (count++)
        array[count] = st;      // array[count++] = st;
        count++;
        fread(&st, sizeof(tStudent), 1, binfp);
        //  4.  이진파일에서 다음 데이터를 읽는다. 
    }
    //틀 암기 fread() ->while(!feof()) -> fread()
    //  5.1    feof()가  아니면 --3.1
    //   5.2   feof()면 함수 종료.
    printf("\n\n# 이진파일 : %s에서 %d명의 학생 데이터가 로딩되었습니다.\n\n", binFileName, count);
    fclose(binfp);
    return count;
}

int main(void)
{
    tStudent computer[MAX_STUDENT];	// 학생 구조체 배열을 지역변수로 선언 **** 가장 중요한 자료구조
    int studentCount = 0;           //  배열에 입력된 학생수
    int select;
    char binFileName[40] = "student.bin";


    do {
        select = choiceMenu(MAX_MAIN_MENU);          //메인 메뉴 출력
        switch (select) {

        case 1:
            insertStudent(computer, &studentCount, MAX_STUDENT);        //  학생 데이터를 입력하는 함수 호출
                        // 대상       length          상수로 define 으로 정의해서 안써두 됨.

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
            saveStudent(binFileName, computer, studentCount);   //주어야 할 데이터 배열과 배열의 데이터 개수 와 파일 이름
            break;
        default:
            break;
        }
    } while (!(select == 0));     //0번 종료를 선택할 때까지 계속해서 반복
    return 0;
}
