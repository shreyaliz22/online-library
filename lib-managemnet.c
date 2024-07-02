#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int id[10], rack[10], quantity[10], price[10], pubyear[10], studyid[10];
char category[10][20], bkname[10][20], author[10][20], pubname[10][20], issue[10][10], retrn[10][10], due[10][10];
int count = 0;

int main() {
    int i, d;
    char c;
    time_t t;
    time(&t);

    do {
        printf("\n\n\n\n\t\t********** Library Management System **********\n\n");
        // Main Menu
        printf("\t\t********************* Menu ********************\n\n");
        printf("\t\t1. Add Books\n");
        printf("\t\t2. Delete Books\n");
        printf("\t\t3. Search Books\n");
        printf("\t\t4. Issue Books\n");
        printf("\t\t5. View Book List\n");
        printf("\t\t6. Edit Book's Record\n");
        printf("\t\t7. Return Books\n");
        printf("\t\t8. Close Application\n\n");
        printf("\t\t***********************************************\n\n");
        printf("\t\tDate and time: %s", ctime(&t));
        printf("\t\tEnter your choice: ");
        scanf(" %c", &c); 

        switch(c) {
            case '1':    // Add Books
                printf("\n\n\n\n\t\t**************ADD BOOKS**************\n\n");
                printf("\t\tEnter the Information Below\n\n");
                printf("\t\tCategory: ");
                scanf("%s", category[count]);
                printf("\t\tBook ID: ");
                scanf("%d", &id[count]);
                printf("\t\tBook Name: ");
                scanf("%s", bkname[count]);
                printf("\t\tAuthor: ");
                scanf("%s", author[count]);
                printf("\t\tQuantity: ");
                scanf("%d", &quantity[count]);
                printf("\t\tPrice: ");
                scanf("%d", &price[count]);
                printf("\t\tRack No: ");
                scanf("%d", &rack[count]);
                printf("\n\t\tThe record is successfully saved\n");
                printf("\t\tSave any more?(Y/N): ");
                scanf(" %c", &c); 
                if(c == 'Y' || c == 'y') {
                    count++;
                    continue;
                }
                break;

            case '2':    // Delete Books
                printf("\n\n\n\n\t\t**************DELETE BOOKS**************\n\n");
                printf("\t\tEnter the Book ID to delete: ");
                int del_id;
                scanf("%d", &del_id);
                for(i = 0; i < count; i++) {
                    if(id[i] == del_id) {
                        for(int j = i; j < count - 1; j++) {
                            id[j] = id[j + 1];
                            quantity[j] = quantity[j + 1];
                            price[j] = price[j + 1];
                            rack[j] = rack[j + 1];
                            pubyear[j] = pubyear[j + 1];
                            studyid[j] = studyid[j + 1];
                            strcpy(category[j], category[j + 1]);
                            strcpy(bkname[j], bkname[j + 1]);
                            strcpy(author[j], author[j + 1]);
                            strcpy(pubname[j], pubname[j + 1]);
                            strcpy(issue[j], issue[j + 1]);
                            strcpy(due[j], due[j + 1]);
                            strcpy(retrn[j], retrn[j + 1]);
                        }
                        count--;
                        printf("\n\t\tBook record deleted successfully.\n");
                        break;
                    }
                }
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '3':    // Search Books
                printf("\n\n\n\n\t\t**************SEARCH BOOKS**************\n\n");
                char search_bkname[20];
                printf("\t\tEnter a Book Name to search: ");
                scanf("%s", search_bkname);
                int found = 0;
                for(i = 0; i < count; i++) {
                    if(strcmp(bkname[i], search_bkname) == 0) {
                        printf("\n\t\tBook ID: %d", id[i]);
                        printf("\n\t\tCategory: %s", category[i]);
                        printf("\n\t\tBook Name: %s", bkname[i]);
                        printf("\n\t\tAuthor: %s", author[i]);
                        printf("\n\t\tQuantity: %d", quantity[i]);
                        printf("\n\t\tPrice: %d", price[i]);
                        printf("\n\t\tRack No: %d\n", rack[i]);
                        found = 1;
                    }
                }
                if(!found) {
                    printf("\n\t\tNot found\n\n");
                }
                printf("\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '4':    // Issue Books
                printf("\n\n\n\n\t\t**************ISSUE BOOKS**************\n\n");
                int issue_id, stud_id;
                char issue_date[10], due_date[10];
                printf("\t\tBook ID: ");
                scanf("%d", &issue_id);
                printf("\n\t\tStudent ID: ");
                scanf("%d", &stud_id);
                printf("\n\t\tIssue Date: ");
                scanf("%s", issue_date);
                printf("\n\t\tDue Date: ");
                scanf("%s", due_date);
                for(i = 0; i < count; i++) {
                    if(id[i] == issue_id) {
                        studyid[i] = stud_id;
                        strcpy(issue[i], issue_date);
                        strcpy(due[i], due_date);
                        printf("\n\t\tBook issued successfully.\n");
                        break;
                    }
                }
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '5':    // View Book List
                printf("\n\n\n\n\t\t**************VIEW BOOK LIST**************\n");
                for(i = 0; i < count; i++) {
                    printf("\nBook count = %d\n\n", i + 1);
                    printf("Book id = %d\n", id[i]);
                    printf("Book name = %s\n", bkname[i]);
                    printf("Book author = %s\n", author[i]);
                    printf("Book issue date (day/month/year) = %s\n", issue[i]);
                }
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '6':    // Edit Book's Record
                printf("\n\n\n\n\t\t**************EDIT BOOK'S RECORD**************\n\n");
                printf("\t\tEnter the Book ID to edit: ");
                int edit_id;
                scanf("%d", &edit_id);
                for(i = 0; i < count; i++) {
                    if(id[i] == edit_id) {
                        printf("\t\tBook ID: %d\n", id[i]);
                        printf("\t\tBook Name: ");
                        scanf("%s", bkname[i]);
                        printf("\t\tBook Publisher Name: ");
                        scanf("%s", pubname[i]);
                        printf("\t\tBook Publisher Year: ");
                        scanf("%d", &pubyear[i]);
                        printf("\t\tBook Price: ");
                        scanf("%d", &price[i]);
                        printf("\t\tBook Quantity: ");
                        scanf("%d", &quantity[i]);
                        break;
                    }
                }
                printf("\n\t\tRecord edited successfully.\n");
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '7':    // Return Books
                printf("\n\n\n\n\t\t***************RETURN BOOKS***************\n\n");
                int return_id;
                printf("\t\tEnter the Book ID to return: ");
                scanf("%d", &return_id);
                for(i = 0; i < count; i++) {
                    if(id[i] == return_id) {
                        printf("\n\t\tBook ID: %d", id[i]);
                        printf("\t\tStudent ID: %d", studyid[i]);
                        printf("\t\tIssue Date: %s", issue[i]);
                        printf("\t\tReturn Date: ");
                        scanf("%s", retrn[i]);
                        printf("\n\t\tBook returned successfully.\n");
                        break;
                    }
                }
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;

            case '8':    // Close Application
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   THANK YOU\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                printf("\n\t\tPress any key to go to main menu...\n");
                getchar();
                getchar();
                break;
        }
    } while(c != '8');

    return 0;
}
