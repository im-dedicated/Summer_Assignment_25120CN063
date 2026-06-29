#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[100];
int itemCount = 0;

void addItem() {
    if (itemCount >= 100) {
        printf("Inventory full!\n");
        return;
    }
    
    printf("Enter item ID: ");
    scanf("%d", &inventory[itemCount].id);
    
    printf("Enter item name: ");
    scanf("%s", inventory[itemCount].name);
    
    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);
    
    printf("Enter price: ");
    scanf("%f", &inventory[itemCount].price);
    
    itemCount++;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\n--- Inventory List ---\n");
    printf("ID\tName\t\tQty\tPrice\n");
    printf("------------------------------------\n");
    
    int i;
    for (i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", inventory[i].id, inventory[i].name, 
               inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void searchItem() {
    int id;
    printf("Enter item ID to search: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("\nItem found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            printf("\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void updateQuantity() {
    int id, newQty;
    printf("Enter item ID: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &newQty);
            inventory[i].quantity = newQty;
            printf("Quantity updated!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem() {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    int i, j;
    for (i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Item\n");
        printf("2. View All Items\n");
        printf("3. Search Item\n");
        printf("4. Update Quantity\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateQuantity();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("Thank you!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
