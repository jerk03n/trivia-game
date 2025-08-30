#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void clearScreen(){
    system("cls");
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