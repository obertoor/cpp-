// hint.c

///#include "tools/color.h"
#include "hint.h"
#include <stdio.h>

// all kinds of visual hints
static const char* BANNER = "\
\t__          ___           _          __  __            _        _       _\n\
\t\\ \\        / / |         | |        |  \\/  |          | |      | |     | |\n\
\t \\ \\  /\\  / /| |__   __ _| | ___    | \\  / | __ _ _ __| | _____| |_    | |\n\
\t  \\ \\/  \\/ / | '_ \\ / _` | |/ _ \\   | |\\/| |/ _` | '__| |/ / _ \\ __|   | |\n\
\t   \\  /\\  /  | | | | (_| | |  __/   | |  | | (_| | |  |   <  __/ |_    |_|\n\
\t    \\/  \\/   |_| |_|\\__,_|_|\\___|   |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|   (_)\n\
";

static const char* SUCCESS = "\t\t*** Operation Successful! ***";
static const char* FAILURE = "\t\t*** Operation Failed! ***";
static const char* ILLEGAL = "\t\t*** Illegal Input! ***";
static const char* LOADING = "\t\t*** Loading ... ***";
static const char* EXITING = "\t\t*** Exiting ... ***";

static const char* INVALID = "\
\t  _____                           _   _       _   _\n\
\t |_   _|                         | | (_)     | | | |\n\
\t   | |    _ __   __   __   __ _  | |  _    __| | | |\n\
\t   | |   | '_ \\  \\ \\ / /  / _` | | | | |  / _` | | |\n\
\t  _| |_  | | | |  \\ V /  | (_| | | | | | | (_| | |_|\n\
\t |_____| |_| |_|   \\_/    \\__,_| |_| |_|  \\__,_| (_)\n\
";

void welcomeMessage() {
    printf("\nWelcome to\n");
    printf("%s\n",BANNER);
    printf("This is WinterCode Project for C-Beginners.\n\n");
}

void successMessage() { printf("\n%s\n\n", SUCCESS); }
void failureMessage() { printf("\n%s\a\n\n", FAILURE); }
void illegalMessage() { printf("\n%s\a\n\n",  ILLEGAL); }
void loadingMessage() { printf("\n%s\n\n", LOADING); }
void exitingMessage() { printf("\n%s\n\n",  EXITING); }
void invalidMessage() {
    printf("\n%ss\n\n",  INVALID);
    printf("\nThis Function is Waiting For you to Implement ...\n\n");
}
