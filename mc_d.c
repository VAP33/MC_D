#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string price;
    int price_value; // Added to store the numeric value for calculations
} Item;

typedef struct
{
    string name;
    string price;
    int price_value; // Added to store the numeric value for calculations
} Beverage;

int main(void)
{
    Item menu[] = {
        {"Burger", "₹100", 100},
        {"Fries", "₹50", 50},
        {"Salad", "₹80", 80}
    };

    Beverage beverages[] = {
        {"Coke", "₹50", 50},
        {"Sprite", "₹67", 67},
        {"Water", "₹20", 20}
    };

    printf("Welcome to McDonald's! Check out our menu:\n");
    int num_items = sizeof(menu) / sizeof(menu[0]);

    for (int i = 0; i < num_items; i++)
    {
        printf("%s - %s\n", menu[i].name, menu[i].price);
    }

    string order = get_string("Please enter the order to be placed: ");
    bool item_found = false;
    int total_price = 0; // Initialize total price

    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(menu[i].name, order) == 0)
        {
            item_found = true;
            printf("Item Available!\n");
            printf("Price: %s\n", menu[i].price);
            total_price += menu[i].price_value; // Add food item price to total

            if (get_string("Do you want to have a beverage? (y/n): ")[0] == 'y')
            {
                printf("Available beverages:\n");

                int num_beverages = sizeof(beverages) / sizeof(beverages[0]);

                for (int j = 0; j < num_beverages; j++)
                {
                    printf("%s - %s\n", beverages[j].name, beverages[j].price);
                }

                string beverage_order = get_string("Please enter a beverage: ");
                bool beverage_found = false;

                for (int j = 0; j < num_beverages; j++)
                {
                    if (strcmp(beverages[j].name, beverage_order) == 0)
                    {
                        beverage_found = true;
                        printf("Item Found!\n");
                        printf("Price: %s\n", beverages[j].price);
                        total_price += beverages[j].price_value; // Add beverage price to total
                        printf("Thank You for Ordering with McDonald's!\n");
                        break;
                    }
                }

                if (!beverage_found)
                {
                    printf("Sorry, the beverage is not available!\n");
                }
            }
            else
            {
                printf("Okay, thanks for ordering with McDonald's!\n");
            }
            break;
        }
    }

    if (!item_found)
    {
        printf("The item is NOT available!\n");
    }

    // Print the final bill if an item was found
    if (item_found)
    {
        printf("Your total bill is: ₹%d\n", total_price);
    }

    return 0;
}
