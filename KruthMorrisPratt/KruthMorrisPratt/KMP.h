#ifndef KMP_H
#define KMP_H
#pragma warning(disable:4996)

#include <iostream>

int KMP(char* Text, int TextSize, int Start, char* Pattern, int PatternSize);

void Preprocess(char* Pattern, int PatternSize, int* Border);

#endif