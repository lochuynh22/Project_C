#include <stdio.h>
#include"function.c"
#include<stdbool.h>
#include <stdlib.h>


typedef struct accountInfo accountInfo;
typedef struct User User;
int main(){
    accountInfo tkn[100];
    User tkn_user[100];
    int choice;
    int n=0;
    char username[20], password[20];
    do{
        printf("\n***Bank Management System Using C***");
        printf("\n");
        printf("\tCHOOSE YOUR ROLE\n");
        printf("%-5s======================\n"," ");
        printf("%-5s[1] Admin.\n"," ");
        printf("%-5s[2] User.\n"," ");
        printf("%-5s[0] Exit the Program.\n"," ");
        printf("%-5s======================\n","");
        printf("%-5sEnter The Choice:"," ");
        scanf("%d", &choice);
        getchar();
        system("cls");
    switch(choice){
        case 1:{
        int admin_choice;
        printf("****===========Login===========****\n");
        while(1){
            printf("Enter username : ");
            fgets(username,sizeof(username), stdin);
            // loai bo ki tu '\n'
            username[strcspn(username,"\n")] = '\0';
            printf("Enter password : ");
            fgets(password,sizeof(password), stdin);
            password[strcspn(password,"\n")] = '\0';
            int isCheck = checkLogin(username,password);

            if(isCheck){
                break;
            }else{
                // bat nguoi dung nhap lai
                printf("Error: Inaccurate information\n");
            }
        }
        do{
            menuAdmin();
            scanf("%d",&admin_choice);
            getchar();
            system("cls");
        switch (admin_choice)
        {
            case 1:
                addUser(tkn,tkn_user,&n);
                break;
            case 2:
                displaylistuser(tkn,tkn_user,&n);
                break;
            case 3:
                finduser(tkn, tkn_user, &n);
                break;
            case 4:
                lockUnlockUser(tkn,tkn_user, &n);
                break;
            case  5:
                listsort(tkn,tkn_user, &n);
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!!!\n");
        }
        }while (admin_choice != 0);
        break;
    }
        case 2:{
        break;
    }
        case 0:
        break;  
    }
    }while(choice!=0);
    return 0;   
}

