/* 
	File Name: pollution.h
	Author: Yago Romano
	Date: November 19, 2019
	Purpose: Pollution Program
*/

#ifndef POLLUTION_H
#define POLLUTION_H


#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<vector>

using namespace std;

// Number of factories
const int SIZE = 3;
// 5 ppm per hour
const float CO_MAX_LIMIT = 35;
// 100 ppb per hour
const float NO2_MAX_LIMIT = 100;
// 0.070 ppm per 8 hours
const float O3_MAX_LIMIT = 0.070;


void enterFactoryNames(string*);
float* makeArray(int);
void enterCOData(float*, int);
void enterNO2Data(float*, int);
void enterO3Data(float*, int);
void printOverLimit(string*, float**, int, const float);
void getLargest(string*, float**, int, int&, float&, string&);


#endif