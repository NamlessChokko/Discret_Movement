#include "../inc/Basic.hpp"
#include <iostream>
using namespace std;

const int ESC = 033;
const int SQR_BRCKT = 91;


char get_arrow(){
    if (getch() != ESC){ 
        return ' ';
    }

    if (getch() != SQR_BRCKT){
        return ' ';
    }

    char arrow = getch(); 
    
    if (arrow == 'A'){
        return 'w';
    } else if (arrow == 'B'){
        return 's';
    } else if (arrow == 'C'){
        return 'd';
    } else if (arrow == 'D'){
        return 'a';
    } else {
        cin.ignore(); 
        cin.ignore();
        cin.ignore();
        return ' '; 
    }

}

int getKey() {
    char code[5] = {'\0'};

    code[1] = getch();
    if (code[1] != 27) { 
        return code[1];
    }

    code[2] = getch();

    if (code[2] == '[') {
        code[3] = getch();

        switch (code[3]) {
            case 'A': return 128; // Up
            case 'B': return 129; // Down
            case 'C': return 130; // Right 
            case 'D': return 131; // Left

            case 'H': return 140; // Home
            case 'F': return 141; // End

            case '2':
                code[4] = getch();
                if (code[4] == '~') return 142; // Insert
                break;

            case '3':
                code[4] = getch();
                if (code[4] == '~') return 143; // Delete
                break;

            case '5':
                code[4] = getch();
                if (code[4] == '~') return 136; // Page Up
                break;

            case '6':
                code[4] = getch();
                if (code[4] == '~') return 137; // Page Down
                break;

            case '1':
                code[4] = getch();
                if (code[4] == ';') {
                    char modifier = getch(); 
                    if (modifier == '5') { // Ctrl + ...
                        char ctrlKey = getch();
                        switch (ctrlKey) {
                            case 'A': return 132; // Ctrl + Up
                            case 'B': return 133; // Ctrl + Down
                            case 'C': return 134; // Ctrl + Right
                            case 'D': return 135; // Ctrl + Left
                            case 'H': return 138; // Ctrl + Home
                            case 'F': return 139; // Ctrl + End
                        }
                    } else if (modifier == '2'){  // Shift + ...
                        char shftKey = getch();
                        switch (shftKey) {
                            case 'A': return 156; // Shift + Up
                            case 'B': return 157; // Shift + Down
                            case 'C': return 158; // Shift + Right 
                            case 'D': return 159; // Shift + Left 
                            case 'H': return 160; // Shift + Home
                            case 'F': return 161; // Shift + End
                        }
                    }
                }
                break;
        }
    } else if (code[2] == 'O') { 
        code[3] = getch();
        switch (code[3]) {
            case 'P': return 144; // F1
            case 'Q': return 145; // F2
            case 'R': return 146; // F3
            case 'S': return 147; // F4
            default:
                if (code[3] >= 't' && code[3] <= 'v') {
                    return 148 + (code[3] - 't'); // F5-F7
                } else if (code[3] >= 'w' && code[3] <= 'y') {
                    return 151 + (code[3] - 'w'); // F8-F10
                }
                break;
        }
    } else if (code[2] == '1') { // F11 & F12
        code[3] = getch();
        if (code[3] == '1') {
            code[4] = getch();
            if (code[4] == '~') return 154; // F11
        } else if (code[3] == '2') {
            code[4] = getch();
            if (code[4] == '~') return 155; // F12
        }
    }

    return -1; // Invalid Key
}



