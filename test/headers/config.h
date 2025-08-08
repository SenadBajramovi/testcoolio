#ifndef CONFIG_H
#define CONFIG_H

#define ERR_FILE_NOT_OPENED -

#define BUFFER_SIZE 257

typedef enum Regions {
    BICEP,
    TRICEP,
    CHEST,
    SHOULDER,
    INVALID_REG
} Regions;

void runProgram();

void beginConfig(int, double, Regions);

#endif // CONFIG_H