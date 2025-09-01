#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct questionData{
    char topic[20];
    int questionNum;
    char question[150];
    char choice1[30];
    char choice2[30];
    char choice3[30];
    char answer[30];
};

struct questionData records[100];
int recordCount = 0;

void clearScreen();
void clearInpBuffer();
void removeNewline(char *str);
int checkPassword();
int askIfRetry();

void adminMenu();
void mainMenu();

void addQuestion(struct questionData records[], int *recordCount);
/*******************************************************************************************************/
void clearScreen(){
    system("cls");
}

void clearInpBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){

    }
}

void removeNewline(char *str){
    str[strcspn(str, "\n")] = '\0';
}

int checkPassword(){
    clearScreen();

    char password[] = "12345678";
    char inputPwd[21];
    char ch;
    int i = 0;

    printf("Enter password: ");
    while((ch = getch()) != 13 && i < sizeof(inputPwd) - 1){
    // stops if 'enter' is pressed or array limit is reached
        if (ch == 8){ // if backspace is pressed, delete last inputted char
            if(i > 0){
                i--;
                printf("\b \b"); 
            }
        }else{
            inputPwd[i++] = ch;
            printf("*");
        }
    }

    inputPwd[i] = '\0';
    if(strcmp(password, inputPwd) == 0){
        return 0; // passwords match
    }
}

int askIfRetry(){
    int isMatchingPwd = 1; // default to not matching
    int flag = 0;
    char ch;
    
    while(flag != 1){
        isMatchingPwd = checkPassword();
        if(isMatchingPwd == 0){
            flag = 1; // user inputted correct password
        }else{
            printf("\nIncorrect password, would you like to retry? (y/n): ");
            scanf(" %c", &ch);
            if(ch != 'y'){ // no error handling if 'n' or 'y' is not pressed
                flag = 1; // user doesn't want to retry 
            }
        }
    }

    return isMatchingPwd;
}

void addQuestion(struct questionData records[], int *recordCount){
    char inptQues[150];
    char inptAns[30]; 

    clearScreen();
    clearInpBuffer();

    printf("Input new question: ");
    fgets(inptQues, sizeof(inptQues), stdin);
    removeNewline(inptQues);

    printf("Input answer to new question: ");
    fgets(inptAns, sizeof(inptAns), stdin);
    removeNewline(inptAns);

    for(int i = 0; i < *recordCount; i++){
        if(strcmp(records[i].question, inptQues) == 0 && 
           strcmp(records[i].answer, inptAns) == 0){

            printf("This question and answer pair already exists.\n");
            printf("Question%d: %s\nAnswer: %s\n", records[i].questionNum, 
                    records[i].question, records[i].answer);
                    Sleep(1000);
            return; 
        }
    }

    struct questionData newRecord;
    strcpy(newRecord.question, inptQues);
    strcpy(newRecord.answer, inptAns);

    printf("Input topic: ");
    fgets(newRecord.topic, sizeof(newRecord.topic), stdin);
    removeNewline(newRecord.topic);

    printf("Input first choice: ");
    fgets(newRecord.choice1, sizeof(newRecord.choice1), stdin);
    removeNewline(newRecord.choice1);

    printf("Input second choice: ");
    fgets(newRecord.choice2, sizeof(newRecord.choice2), stdin);
    removeNewline(newRecord.choice2);

    printf("Input third choice: ");
    fgets(newRecord.choice3, sizeof(newRecord.choice3), stdin);
    removeNewline(newRecord.choice3);

    int lastQNum = 0;
    for(int i = 0; i < *recordCount; i++){
        if(strcmp(records[i].topic, newRecord.topic) == 0 &&
           records[i].questionNum > lastQNum){

            lastQNum = records[i].questionNum;
           }
    }
    newRecord.questionNum = lastQNum + 1;

    if(*recordCount < 100){
        records[*recordCount] = newRecord;
        (*recordCount)++;

        FILE *fp = fopen("questions.txt", "a");
        if (fp != NULL)
        {
            fprintf(fp, "%s| %d| %s| %s| %s| %s| %s\n",
                    newRecord.topic,
                    newRecord.questionNum,
                    newRecord.question,
                    newRecord.choice1,
                    newRecord.choice2,
                    newRecord.choice3,
                    newRecord.answer);
            fclose(fp);
        }
        else
        {
            printf("Error! Could not open file for saving.\n");
        }
        printf("New Question Added Successfully!\n");
        printf("Returning to Admin Menu...");
        Sleep(1000);
        return;
    }
}

void adminMenu(){
    int choice = 0;
    int canView = askIfRetry();

    if(canView == 0){
        while (1){
            clearScreen();
            printf("====ADMIN MENU====\n");
            printf("[1] Add Question\n");
            printf("[2] Edit Question\n");
            printf("[3] Delete Question\n");
            printf("[4] Import Question\n");
            printf("[5] Export Question\n");
            printf("[6] Return to Main Menu\n");
            printf("Type the number corresponding to your choice.\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch (choice){
            case 1:
                Sleep(1000);
                addQuestion(records, &recordCount);
                break;
            case 2:
                printf("Edit Question");
                Sleep(1000);
                break;
            case 3:
                printf("Delete Question");
                Sleep(1000);
                return;
            case 4:
                printf("Import Question");
                Sleep(1000);
                break;
            case 5:
                printf("Export Question");
                Sleep(1000);
                break;
            case 6:
                printf("Return to Main Menu");
                Sleep(1000);
                return;
            default:
                printf("Invalid input");
                Sleep(1000);
            }
        }
    }
}

void mainMenu(){
    int choice = 0;

    while(1){
        clearScreen();
        printf("====MAIN MENU====\n");
        printf("[1] Manage Data\n");
        printf("[2] Play\n");
        printf("[3] Exit\n");
        printf("Type the number corresponding to your choice.\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Manage Data");
                Sleep(1000);
                adminMenu();
                break;
            case 2: 
                printf("Play");
                Sleep(1000);
                break;
            case 3: 
                printf("Exit");
                Sleep(1000);
                return;
            default:
                printf("Invalid input");
                Sleep(1000);
        }
    }
}

int main(){
    mainMenu();
    return 0;
}