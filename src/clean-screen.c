// Created by: WestleyR
// email: westleyr@nym.hush.com
// Date: Jul 6, 2019
// https://github.com/WestleyR/clean-screen
// version-1.0.3
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define VERSION "version-1.0.3 Jul 6, 2019"

void help_menu(char* script_name) {
    printf("Usage: %s [option]\n", script_name);
    printf("\n  Clear the terminal screen.\n");
    printf("\n");
    printf("Options:\n");
    printf("  -b  clean the terminal, leaving the prompt below.\n");
    printf("\n");
    printf("https://github.com/WestleyR/clean-screen\n");
    printf("This software is licensed under a Clear BSD License.\n");
    printf("\n%s\n", VERSION);
}

int main(int argc, char** argv) {
    int bottom_mode = 0;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-b") == 0) {
                bottom_mode = 1;
            } else if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0)) {
                help_menu(argv[0]);
                return(0);
            }
        }
    }

    if (bottom_mode != 0) {
        struct winsize w;
        int rows;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != 0) {
            perror("ioctl");
            rows = 256;
        } else {
            rows = w.ws_row;
        }

        for (int l = 0; l < rows; l++) {
            printf("\n");
        }
    } else {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
    }

    return(0);
}

//
// End clean-screen.c
//
