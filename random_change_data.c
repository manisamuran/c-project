#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    long file_size;
    char *buffer;
    size_t result;

    srand(time(NULL)); // Seed the random number generator

    // Open the file for binary read/write mode
    file = fopen("example.txt", "rb+");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Obtain the file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory to store the entire file content
    buffer = (char *)malloc(file_size);
    
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    // Read the entire file into the buffer
    result = fread(buffer, 1, file_size, file);

    if (result != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    // Modify the data in the buffer randomly
    for (long i = 0; i < file_size; i++) {
        buffer[i] = (char)(rand() % 256); // Modify each byte randomly
    }

    // Move the file pointer to the beginning and write the modified data back
    rewind(file);
    result = fwrite(buffer, 1, file_size, file);

    if (result != file_size) {
        perror("Error writing to file");
        free(buffer);
        fclose(file);
        return 1;
    }

    // Cleanup and close the file
    free(buffer);
    fclose(file);

    printf("File content has been modified randomly.\n");

    return 0;
}
