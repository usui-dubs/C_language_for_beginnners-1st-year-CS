#include <stdio.h>
#include <errno.h>

int main() {
    FILE *fileptr;
    fileptr = fopen("nothere.txt", "r");
    if (fileptr == NULL) {
        perror("[-]");	//perror("open");
    }
    fclose(fileptr);
    return 0;
}
