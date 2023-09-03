#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_folders>\n", argv[0]);
        return 1;
    }

    int numFolders = atoi(argv[1]);

    if (numFolders <= 0) {
        printf("Please provide a valid number of folders greater than 0.\n");
        return 1;
    }

    for (int i = 1; i <= numFolders; i++) {
        char folderName[50];
        snprintf(folderName, sizeof(folderName), "folder%d", i);

        if (mkdir(folderName, 0755) != 0) {
            perror("Error creating folder");
            return 1;
        }
    }

    printf("Created %d folders.\n", numFolders);

    return 0;
}

