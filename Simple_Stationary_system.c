// int finalprice[10] = {10, 7, 3, 5, 12, 40, 12, 40, 22, 55};
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int k = 0;
int reciept = 0;
int itemprice;

void MainFrame(int *item_code, int *item_stock, int *user_item, int *user_quantity, char *username)
{
    int choice;
    int i_code, flag = 0;
    system("cls");
    printf("\n\n\n******************************************************************************\n");
    printf("\t\t  O N L N E   S T A T I O N A R Y    S H O P \n\n");
    printf("                            SELECT YOUR ITEM HERE !!\n\n");
    printf("1.  Pen     \n\n2.  Pencil\n\n3.  Eraser\n\n4.  Sharpner\n\n5.  Scale\n\n6.  Notebook\n\n7.  File\n\n8.  Assignment Sheets\n\n9.  Marker\n\n10. Water Bottle\n");
    printf("\n\n\n\n ------------------\n");
    // printf("| Press ESC - Exit |\n");
    printf("| Press KEY - Exit |\n");
    printf(" ------------------\n");
    printf("\n******************************************************************************\n");

    while (flag == 0)
    {
        printf("\n\nEnter the choice : ");
        scanf("%d", &choice);
        choice = choice - 1;
        if (choice >= 0 && choice <= 9)
        {
            int quantity;
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            if (quantity < item_stock[choice])
            {
                reciept++;
                item_stock[choice] = item_stock[choice] - quantity;
                user_item[k] = item_code[choice];
                user_quantity[k] = quantity;
                k++;
            }
            else
            {
                printf("Item is out of stock");
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    system("cls");
    int sum = 0;
    if (reciept > 0)
    {
        printf("\n\n\n******************************************************************************\n");
        printf("\t\t  O N L N E   S T A T I O N A R Y    S H O P \n\n");
        printf("                             PAYMENT SUMMARY !!\n\n");
        printf("\nReturn Policy : Return your items in First 10 Days..\n");
        printf("--------------------------------------------------------------------\n\n");
        printf("ITEMS                   QUANTITY                TOTAL\n\n");

        for (int i = 0; i < k; i++)
        {
            char product[90];
            if (user_item[i] == 101)
            {
                strcpy(product, "Pen              ");
                itemprice = 10;
            }
            else if (user_item[i] == 102)
            {
                strcpy(product, "Pencil           ");
                itemprice = 7;
            }
            else if (user_item[i] == 103)
            {
                strcpy(product, "Eraser           ");
                itemprice = 3;
            }
            else if (user_item[i] == 104)
            {
                strcpy(product, "Sharpner         ");
                itemprice = 5;
            }
            else if (user_item[i] == 105)
            {
                strcpy(product, "Scale            ");
                itemprice = 12;
            }
            else if (user_item[i] == 106)
            {
                strcpy(product, "Notebook         ");
                itemprice = 40;
            }
            else if (user_item[i] == 107)
            {
                strcpy(product, "File             ");
                itemprice = 12;
            }
            else if (user_item[i] == 108)
            {
                strcpy(product, "Assignment Sheet ");
                itemprice = 40;
            }
            else if (user_item[i] == 109)
            {
                strcpy(product, "White Board Markr");
                itemprice = 22;
            }
            else if (user_item[i] == 110)
            {
                strcpy(product, "Water Bottle     ");
                itemprice = 55;
            }
            printf("%s          %d                    %d\n", product, user_quantity[i], itemprice * user_quantity[i]);
            sum = sum + (itemprice * user_quantity[i]);
        }
        printf("--------------------------------------------------------------------\n\n");
        printf("\n TOTAL AMOUNT : %d\n", sum);
        printf("                        <<THANK YOU %s, VISIT AGAIN >>", username);
        printf("\n\n\n******************************************************************************\n");
    }
}
int login(char *name, char *pass)
{
    char username[90], password[90];
    printf("\n\n\n******************************************************************************\n");
    printf("\t\t  O N L N E   S T A T I O N A R Y    S H O P \n\n");
    printf("                             LOGIN HERE !!\n\n");
    printf("    Enter username : ");
    gets(username);

    printf("    Enter password : ");
    gets(password);

    if (!strcmp(username, name) && !strcmp(pass, password))
    {
        return 1;
    }
    else
    {
        printf("Credentials mismatched");
        return 0;
    }
    printf("\n\n\n******************************************************************************\n");
}

void Register(char *name, char *pass)
{
    printf("\n\n\n******************************************************************************\n");
    printf("\t\t  O N L N E   S T A T I O N A R Y    S H O P \n\n");
    printf("                             REGISTER HERE !!\n\n");
    printf("    Enter username : ");
    gets(name);

    printf("    Enter Password : ");
    gets(pass);
    printf("\n\n\n******************************************************************************\n\n");
}

int main()
{
    char username[90];
    char password[90];
    int item_code[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int item_stock[10] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25};
    int user_item[k];
    int user_quantity[k];

    Register(username, password);
    system("cls");
    if (login(username, password))
    {
        MainFrame(item_code, item_stock, user_item, user_quantity, username);
    }
    getch();
    return 0;
}