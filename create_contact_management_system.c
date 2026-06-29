#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

int main()
{
    struct Contact contacts[100];
    int total = 0;
    int choice;
    
    while(1)
    {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        if(choice == 1)
        {
            if(total < 100)
            {
                printf("Enter Name: ");
                fgets(contacts[total].name, 50, stdin);
                contacts[total].name[strcspn(contacts[total].name, "\n")] = 0;
                
                printf("Enter Phone: ");
                fgets(contacts[total].phone, 15, stdin);
                contacts[total].phone[strcspn(contacts[total].phone, "\n")] = 0;
                
                printf("Enter Email: ");
                fgets(contacts[total].email, 50, stdin);
                contacts[total].email[strcspn(contacts[total].email, "\n")] = 0;
                
                total++;
                printf("Contact added successfully!\n");
            }
            else
            {
                printf("Contact list is full!\n");
            }
        }
        
        else if(choice == 2)
        {
            if(total == 0)
            {
                printf("No contacts available.\n");
            }
            else
            {
                printf("\n--- All Contacts ---\n");
                for(int i = 0; i < total; i++)
                {
                    printf("\nContact %d:\n", i+1);
                    printf("Name: %s\n", contacts[i].name);
                    printf("Phone: %s\n", contacts[i].phone);
                    printf("Email: %s\n", contacts[i].email);
                }
            }
        }
        
        else if(choice == 3)
        {
            char search[50];
            int found = 0;
            
            printf("Enter name to search: ");
            fgets(search, 50, stdin);
            search[strcspn(search, "\n")] = 0;
            
            for(int i = 0; i < total; i++)
            {
                if(strcmp(contacts[i].name, search) == 0)
                {
                    printf("\n--- Contact Found ---\n");
                    printf("Name: %s\n", contacts[i].name);
                    printf("Phone: %s\n", contacts[i].phone);
                    printf("Email: %s\n", contacts[i].email);
                    found = 1;
                    break;
                }
            }
            
            if(found == 0)
            {
                printf("Contact not found!\n");
            }
        }
        
        else if(choice == 4)
        {
            char delete_name[50];
            int found = 0;
            
            printf("Enter name to delete: ");
            fgets(delete_name, 50, stdin);
            delete_name[strcspn(delete_name, "\n")] = 0;
            
            for(int i = 0; i < total; i++)
            {
                if(strcmp(contacts[i].name, delete_name) == 0)
                {
                    for(int j = i; j < total-1; j++)
                    {
                        contacts[j] = contacts[j+1];
                    }
                    total--;
                    printf("Contact deleted successfully!\n");
                    found = 1;
                    break;
                }
            }
            
            if(found == 0)
            {
                printf("Contact not found!\n");
            }
        }
        
        else if(choice == 5)
        {
            printf("Thank you for using Contact Management System!\n");
            break;
        }
        
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
