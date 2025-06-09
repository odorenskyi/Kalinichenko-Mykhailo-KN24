#ifndef MODULESKALINICHENKO_H_INCLUDED
#define MODULESKALINICHENKO_H_INCLUDED

#include <fstream>
#include <string>

double s_calculation(double x, double y, double z);

int CountCharactersInFile(std::ifstream& file);

bool isContainsWord(std::ifstream& file, const std::string& target);

std::string IntToBinaryString(unsigned int n);

void task10_1();
void task10_2();
void task10_3();

#endif
