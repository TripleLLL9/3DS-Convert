#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input;
int output;
char formattedOutput[60];

int main(int argc, char **argv) {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

	printf("Welcome to 3DS-Convert v0.1!");

    printf("\n\nChoose the type of conversion you want to perform.");

    printf("\n\nX - Fahrenheit to Celsius");
    printf("\nY - Celsius to Fahrenheit");

    printf("\n\nNOTE: This beta release might not include much.");
    printf("\nMore units and features will be added soon!");

    while(aptMainLoop()) {
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
        hidScanInput();

        bool didit = false;
        static SwkbdState swkbd;
        SwkbdButton button = SWKBD_BUTTON_NONE;

        if(hidKeysDown() & KEY_START) {
            break;
        }

        if(hidKeysDown() & KEY_X) {
            didit = true;
            swkbdInit(&swkbd, SWKBD_TYPE_NUMPAD, 1, 8);
			swkbdSetValidation(&swkbd, SWKBD_ANYTHING, 0, 0);
			swkbdSetFeatures(&swkbd, SWKBD_FIXED_WIDTH);
            button = swkbdInputText(&swkbd, input, sizeof(input));

            output = input - 32;
            output = output * 5/9;

            itoa(output, formattedOutput, 60);

            printf("\nThe converted temperature is %s", formattedOutput);
            printf("\nPress START to exit.");
        }

        if(hidKeysDown() & KEY_Y) {
            didit = true;
            swkbdInit(&swkbd, SWKBD_TYPE_NUMPAD, 1, 8);
			swkbdSetValidation(&swkbd, SWKBD_ANYTHING, 0, 0);
			swkbdSetFeatures(&swkbd, SWKBD_FIXED_WIDTH);
            button = swkbdInputText(&swkbd, input, sizeof(input));

            output = input * 9/5;
            output = output + 32;

            itoa(output, formattedOutput, 60);

            printf("\nThe converted temperature is %s", formattedOutput);
            printf("\nPress START to exit.");
        }

    }
    gfxExit();
    return 0;
}
