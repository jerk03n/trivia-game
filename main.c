#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void clearScreen();
void adminMenu();
void mainMenu();

void clearScreen(){
    system("cls");
}

int checkPassword(){
    clearScreen();

    char password[] = "12345678";
    char inputPwd[21];
    char ch;
    int i = 0;

    printf("Enter password: ");
    while((ch = getch()) != 13 && i < sizeof(inputPwd) - 1){
        if (ch == 8){
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
        return 0; 
    }
}

void adminMenu(){
    int choice = 0;
    int canView = checkPassword();

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
                printf("Add Question");
                Sleep(1000);
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