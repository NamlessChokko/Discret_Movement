#pragma once
#ifndef CONSTANTS
#define CONSTANTS


// Directions:
constexpr int RIGHT = 0;
constexpr int UP = 1;
constexpr int LEFT = 2;
constexpr int DOWN = 3;

// Reset terminal color:
constexpr char rst[] = "\033[0m"; // Reset 

// Font colors:
constexpr char bk[] = "\033[30m"; // Black
constexpr char rd[] = "\033[31m"; // Red
constexpr char gn[] = "\033[32m"; // Green
constexpr char yl[] = "\033[33m"; // Yellow
constexpr char bl[] = "\033[34m"; // Blue 
constexpr char mg[] = "\033[35m"; // Magenta
constexpr char cn[] = "\033[36m"; // Cyan
constexpr char wt[] = "\033[37m"; // White

// Background colors:
constexpr char bg_bk[] = "\033[40m"; // Black
constexpr char bg_rd[] = "\033[41m"; // Red 
constexpr char bg_gn[] = "\033[42m"; // Green
constexpr char bg_yl[] = "\033[43m"; // Yellow
constexpr char bg_bl[] = "\033[44m"; // Blue 
constexpr char bf_mg[] = "\033[45m"; // Magenta
constexpr char bf_cn[] = "\033[46m"; // Cyan 
constexpr char bg_wt[] = "\033[47m"; // White


#endif // CONSTANTS
