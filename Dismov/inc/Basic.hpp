#pragma once
#ifndef BASIC
#define BASIC

#include <string>
#include <vector>


char getch();

int getTerminalWidth();

void pressEnter();

void prtLL(std::string input, std::string color, int width, int number_lines, bool has_border);

void printL(std::string input, std::string color, size_t width, bool has_border);

void printC(std::string input, std::string color, size_t width, bool has_border);

char get_arrow();

int getKey();

std::string format(std::string input);

std::vector<std::string> adj_to_width (
    std::string input, 
    size_t width,
    bool fill,
    char empty_space
);

std::string rep_char (int times, char character);

std::string cutLine (std::string input, int width);


#endif // BASIC