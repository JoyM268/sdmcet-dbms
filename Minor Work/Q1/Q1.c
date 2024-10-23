#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int createFile(const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("Error occurred while creating and opening the file");
        exit(EXIT_FAILURE);
    }
    printf("\nFile '%s' created and opened successfully.\n\n", filename);
    return fd;
}

void closeFile(int fd) {
    if (close(fd) == -1) {
        perror("An error occurred while closing the file");
        exit(EXIT_FAILURE);
    }
    printf("The file was closed successfully.\n\n");
}

void writeFile(int fd, const char *text) {
    ssize_t bytesWrite = write(fd, text, strlen(text));
    if (bytesWrite == -1) {
        perror("An error occurred while writing to file");
        closeFile(fd);
        exit(EXIT_FAILURE);
    }
    printf("%zd bytes written into the file.\n\n", bytesWrite);
}

void readFile(int fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    lseek(fd, 0, SEEK_SET);
    
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1) {
        perror("An error occurred while reading from file");
        closeFile(fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%zd bytes read from the file:\n%s\n", bytesRead, buffer);
}

int openFileForAppend(const char *filename) {
    int fd = open(filename, O_APPEND | O_RDWR);
    if (fd == -1) {
        perror("An error occurred while opening file for appending");
        exit(EXIT_FAILURE);
    }
    printf("File '%s' opened for appending successfully.\n", filename);
    return fd;
}

void appendToFile(int fd, const char *newText) {
    ssize_t bytesWrite = write(fd, newText, strlen(newText));
    if (bytesWrite == -1) {
        perror("An error occurred while appending to file");
        closeFile(fd);
        exit(EXIT_FAILURE);
    }
    printf("%zd bytes appended to the file.\n\n", bytesWrite);
}

int main() {
    int fd;
    char FILENAME[100];

    printf("Enter the file name: ");
    scanf("%s", FILENAME);

    // Create and open the specified file
    fd = createFile(FILENAME);

    // Write a string to the specified file
    const char *text = "Hello, my name is Joy.\nI am a student of CSE A.\n";
    writeFile(fd, text);

    // Read from the specified file
    readFile(fd);
    closeFile(fd);

    // Appending string into a specified file
    fd = openFileForAppend(FILENAME);
    const char *newText = "I am studying in 3rd year at SDMCET.\n";
    appendToFile(fd, newText);

    closeFile(fd);
    return 0;
}
