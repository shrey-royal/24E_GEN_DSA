#include <stdio.h>

#define NUM_BREEDS 50

// Define the structure
typedef struct {
    char name[50];
    int danger_level;
} DogBreed;

// Initialize an array of structures
DogBreed dogBreeds[NUM_BREEDS] = {
    {"Pit Bull Terrier", 95},
    {"Rottweiler", 90},
    {"Doberman Pinscher", 85},
    {"German Shepherd", 80},
    {"American Bulldog", 78},
    {"Bullmastiff", 75},
    {"Husky", 70},
    {"Alaskan Malamute", 68},
    {"Akita Inu", 67},
    {"Wolf Hybrid", 99},
    {"Boxer", 65},
    {"Chow Chow", 83},
    {"Dalmatian", 60},
    {"Cane Corso", 88},
    {"Great Dane", 55},
    {"Saint Bernard", 50},
    {"Presa Canario", 92},
    {"Dogo Argentino", 87},
    {"Staffordshire Terrier", 82},
    {"Belgian Malinois", 85},
    {"Kangal", 97},
    {"Tosa Inu", 94},
    {"Caucasian Shepherd", 98},
    {"Tibetan Mastiff", 89},
    {"Shar Pei", 58},
    {"Jack Russell Terrier", 40},
    {"Border Collie", 35},
    {"Labrador Retriever", 20},
    {"Golden Retriever", 15},
    {"Pug", 5},
    {"Beagle", 10},
    {"Pomeranian", 8},
    {"Shih Tzu", 7},
    {"Yorkshire Terrier", 6},
    {"Chihuahua", 30},
    {"Dachshund", 25},
    {"Cocker Spaniel", 18},
    {"English Bulldog", 22},
    {"Whippet", 12},
    {"Samoyed", 14},
    {"Bernese Mountain Dog", 17},
    {"Bichon Frise", 4},
    {"Australian Shepherd", 50},
    {"Irish Setter", 38},
    {"Newfoundland", 28},
    {"Weimaraner", 45},
    {"Great Pyrenees", 42},
    {"Vizsla", 30},
    {"Cavalier King Charles Spaniel", 5},
    {"Basenji", 55}
};

// Function to print the dog breed data
void printDogBreeds() {
    printf("%-30s | Danger Level\n", "Dog Breed");
    printf("------------------------------------\n");
    for (int i = 0; i < NUM_BREEDS; i++) {
        printf("%-30s | %d\n", dogBreeds[i].name, dogBreeds[i].danger_level);
    }
}

int main() {
    printDogBreeds();
    return 0;
}