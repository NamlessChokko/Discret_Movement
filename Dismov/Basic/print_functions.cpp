#include "../inc/Basic.hpp"
#include "../inc/constants.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void pressEnter(){
    cout << cn << "Press "<< yl << "'ENTER' " << cn << "to continue..." << rst;
}

void prtLL(string input, string color, int width, int number_lines, bool has_border){
    if (input != ""){
        cout << color;
        string border = (has_border)? "|" : "";
        string line = cutLine(input, width - 2 * (border.length()));

        for (int i = 0; i < number_lines; i++){            
            cout << cn << border << color << line << cn << border;
        }


        cout << rst;
    }
}

void printL(string input, string color, size_t width, bool has_border){
    if (input != ""){
        cout << color;
        string border = (has_border)? "|" : ""; 
        vector<string> lines = adj_to_width(input, width - 2 * (border.length()), true, ' ');
        int i = 0;
        if (lines.size() > 1){
            do {
                cout << cn << border << color << lines[i] << cn << border << endl;
                i ++;
            } while (i < static_cast<int>(lines.size()) - 1);
        }

        cout << cn << border << color << lines[i] << cn << border;
        cout << rst;
    }
};

void printC(string input, string color, size_t width, bool has_border){
    if (input != ""){ 
        int empty_spaces = width - input.length();
        empty_spaces = empty_spaces / 2;
        string border = (has_border)? "|" : "";
        string left(empty_spaces, ' ');
        string right(width - left.length() - input.length() - 2 * (border.length()), ' '); 

        cout << cn << border;
        cout << color << left << input << right << rst; 
        cout << cn << border << rst << endl;
    }
};
