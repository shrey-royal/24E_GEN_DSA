#include<stdio.h>
#include<string.h>

typedef struct Icecream ic;

struct Icecream {
    char name[20];
    char flavor[20];
    char brand[20];
    double price;
};

int main() {
    ic obj;

    // strcpy(obj.brand, "Havmore");
    printf("Enter brand: ");
    gets(obj.brand);
    strcpy(obj.name, "Brownie");
    strcpy(obj.flavor, "Chocolate");
    obj.price = 100;

    printf("\nBrand: %s", obj.brand);
    printf("\nName: %s", obj.name);
    printf("\nFlavor: %s", obj.flavor);
    printf("\nPrice: Rs.%.2lf", obj.price);

    return 0;
}