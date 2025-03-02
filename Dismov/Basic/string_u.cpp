#include "../inc/Basic.hpp"
#include "../inc/constants.hpp"

#include <unordered_map>
using namespace std;

unordered_map<string, string> colors = {
    {"*rs", rst},
    {"^bk", bk},
    {"^rd", rd},
    {"^gn", gn},
    {"^yl", yl},
    {"^bl", bl},
    {"^mg", mg},
    {"^cn", cn},
    {"^wt", wt},
    {"#bk", bg_bk},
    {"#rd", bg_rd},
    {"#gn", bg_gn},
    {"#yl", bg_yl},
    {"#bl", bg_bl},
    {"#mg", bf_mg},
    {"#cn", bf_cn},
    {"#wt", bg_wt}
};

string format(string input) {
    string formatted = "";
    int key_length = 3;

    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        if ((input[i] == '^' || input[i] == '#' || input[i] == '*') && (i == 0 || input[i - 1] != '\\')) {
            if (i + key_length <= static_cast<int>(input.length())) {
                string key = input.substr(i, key_length);
                if (colors.find(key) != colors.end()) {
                    formatted += colors[key];
                    i += key_length - 1;
                    continue;
                }
            }
        }
        formatted += input[i];
    }

    return formatted;
}

vector<string> adj_to_width(
    string input, 
    size_t width, 
    bool fill, 
    char empty_space
) {
    vector<string> lines;
    string line;
    size_t input_length = input.length();
    
    if (input_length <= width) {
        string empty_spaces(width - input_length, empty_space);
        line = (!fill)? input : input + empty_spaces;  
        lines.push_back(line);
        return lines;
    }

    size_t start = 0;
    
    while (start < input_length) {
        size_t end = start + width;

        if (end >= input_length) {
            string empty_spaces(width - (input_length - start), empty_space);
            line = (!fill) ? input.substr(start) : input.substr(start) + empty_spaces;
            lines.push_back(line);
            break;
        }

        size_t last_space = input.rfind(' ', end);
        
        if (last_space == string::npos || last_space < start) {
            last_space = end;
        }

        string empty_spaces(width - (last_space - start), empty_space); 
        line = (!fill)? input.substr(start, last_space - start) : input.substr(start, last_space - start) + empty_spaces;
        lines.push_back(line);

        start = last_space + 1;
    }

    return lines;
}

string rep_char(int times, char character) {
    return string (times, character);
}

string cutLine(string input, int width){
    string line;
    
    if (static_cast<int>(input.size()) < width){
        string empty_spaces(width - input.size(), ' ');
        line = input + empty_spaces;
        return line;
    } else {
        line = input.substr(0, width - 3);
        line = line + "...";
        return line;
    }

}


