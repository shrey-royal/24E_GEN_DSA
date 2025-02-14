#include<stdio.h>
#include<string.h>

typedef struct Icecream ic;

struct Icecream {
    char name[20];
    char flavor[20];
    char brand[20];
    double price;
};

ic scan() {
    ic obj;

    // strcpy(obj.brand, "Havmore");
    printf("Enter brand: ");
    gets(obj.brand);
    strcpy(obj.name, "Brownie");
    strcpy(obj.flavor, "Chocolate");
    obj.price = 100;

    return obj;
}

void print(ic obj) {
    printf("\nBrand: %s", obj.brand);
    printf("\nName: %s", obj.name);
    printf("\nFlavor: %s", obj.flavor);
    printf("\nPrice: Rs.%.2lf", obj.price);
}

int main() {
    ic obj;

    obj = scan();
    print(obj);

    return 0;
}