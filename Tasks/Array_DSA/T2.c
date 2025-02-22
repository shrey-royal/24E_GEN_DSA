#include <stdio.h>

void printNames() {
    const char *names[] = {
        "Aarav", "Gaurav", "Saurav", "Bhav",
        "Rohan", "Mohan", "Sohan", "Karan",
        "Neel", "Anil", "Sunil", "Rahul",
        "Ritika", "Nitika", "Kritika", "Monika",
        "Kavya", "Navya", "Divya", "Revya",
        "Aryan", "Kalyan", "Vivaan", "Bhavan",
        "Pranav", "Sharav", "Arnav", "Yugav",
        "Meera", "Veera", "Neera", "Sameera",
        "Rekha", "Lekha", "Sneha", "Esha",
        "Varun", "Tarun", "Arun", "Harun",
        "Rakesh", "Suresh", "Dinesh", "Ganesh",
        "Nikhil", "Akil", "Sakil", "Manil"
    };
    
    int size = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }
}

int main() {
    printNames();
    return 0;
}