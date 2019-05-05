// Created by: WestleyR
// email: westleyr@nym.hush.com
// Date: May 4, 2019
// https://github.com/WestleyR/clean-screen
// version-1.0.0
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

int main(int argc, char** argv) {
    if (argc > 1) {
        printf("Usage: %s\n", argv[0]);
        printf("\n  Clear the terminal screen.\n");
        printf("\nhttps://github.com/WestleyR/clean-screen\n");
        printf("This software is licensed under a Clear BSD License.\n");
        printf("\nversion-1.0.0, May 4, 2019\n");
        return(1);
    }

    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    return(0);
}

//
// End clean-screen.c
//
