#include <stdio.h>
#include <string.h>

#include "headers\\config.h"

void beginConfig(int, double, Regions);
Regions strToEnumReg(char*);

void runProgram()
{

    char inp;
    FILE *file = fopen("doc\\instructions.txt", "r");

    if (file == NULL)
    {
        printf("Could not open file");
    }

    printf("File created.\n\n\n");

    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    printf("Use default configuration or custom configuration? (D/C): ");
    scanf("%c", &inp);

    printf("\n");

    switch (inp) {
        case 'D':
        case 'd':
            printf("Selected Default (D).\n\n");
            beginConfig(14, 1.5, BICEP); // these are the default settings
            break;
        case 'C':
        case 'c':
            printf("Selected Custom (C).\n\n");

            int dpr, comprate;
            char region[BUFFER_SIZE];

            printf("Enter DPR: ");
            scanf("%d", &dpr);

            printf("Enter Comprate: ");
            scanf("%d", &comprate);

            printf("Enter Region: ");
            scanf("%s", region);
            
            int reg = strToEnumReg(region);
            beginConfig(dpr, comprate, reg);
            // maybe i can put this all in one function?

            break;
        default:
            printf("Invalid option, please try again.\n\n");
    }

    fclose(file);
}

void beginConfig(int dprate, double comprate, Regions region) { // device pressure rate, compression rate, region, 
    // some fancy calculations here... ignore the whole function body
}

Regions strToEnumReg(char* reg) {
    if (strcmp(reg, "Bicep") == 0 || strcmp(reg, "bicep") == 0) {
        return BICEP;
    } else if (strcmp(reg, "Tricep") == 0 || strcmp(reg, "tricep") == 0) {
        return TRICEP;
    } else if (strcmp(reg, "Chest") == 0|| strcmp(reg, "chest") == 0) {
        return CHEST;
    } else if (strcmp(reg, "Shoulder") == 0 || strcmp(reg, "shoulder") == 0) {
        return SHOULDER;
    } else {
        return INVALID_REG;
    }

    // im assuming this is typically enough for converting strings to enums
    // gpt: do you advise anything else in these kind of converting functions
    // i feel like the whole strcmp thingy is a bit inefficient
}
