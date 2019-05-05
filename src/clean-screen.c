// Created by: WestleyR
// email: westleyr@nym.hush.com
// Date: May 4, 2019
// https://github.com/WestleyR/clean-screen
// version-1.0.1
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

#define VERSION "version-1.0.1, May 4, 2019"

int main(int argc, char** argv) {

    // If theres any arguments, print the usage
    if (argc > 1) {
        printf("Usage: %s\n", argv[0]);
        printf("\n  Clear the terminal screen.\n");
        printf("\nhttps://github.com/WestleyR/clean-screen\n");
        printf("This software is licensed under a Clear BSD License.\n");
        printf("\n%s\n", VERSION);
        return(1);
    }

    // The actral function that clears the terminal
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    return(0);
}

//
// End clean-screen.c
//
