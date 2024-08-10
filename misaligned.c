#include <stdio.h>
#include <assert.h>
#include <string.h>
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {

    char buffer[4096]; 
    FILE *stream = fmemopen(buffer, sizeof(buffer), "w");
    FILE *old_stdout = stdout;
    stdout = stream;

    fflush(stdout);
    stdout = old_stdout;
    fclose(stream);
    
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    char expectedOutput[4096];
    int expectedLength = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expectedLength += snprintf(expectedOutput + expectedLength, sizeof(expectedOutput) - expectedLength,
                "%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    int result = printColorMap();
    assert(strcmp(buffer, expectedOutput) == 0);
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
