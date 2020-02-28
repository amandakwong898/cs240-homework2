/*
 *
 * project: hw2
 * name: Amanda Kwong
 * account: akwong
 * date: 02/18/2020
 * file: conversion.c
 * notes:
 *
    
 *   
 */

#include <stdio.h>
#include <string.h>
#include <math.h>


/* this function can print out an q_string s[]*/
void print(char s[], int q){

    printf(" %2d-string: ", q);
    for (int i=0;s[i]; i++){
        if (!((i)%4)&&i!=0) printf("|");
        printf("%c", s[i]);
    }
    printf("\n");
}

/* Read bits into a char array 
*  from memory of a 32-bit data type
*/
void bin_char(unsigned n, char s[]) 
{ 
    
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        s[j++] = (n & i)?  '1' : '0';
    }
    s[j] = 0;
}

/* this function converts the integer num into a q_based string */
void num2q(int num, char num_q[], int q) {
    char temp[100];
    for (int i = 0; num_q[i]; i++) {
	num_q[i] = '\0';
    } 
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
    int i = 0;
    while (num > 0) {
        int remain = num % q;
        num = num / q;
        temp[i++] = digits[remain];
    }
    int k = 0;
    for (int j = i-1;  j  >= 0; j --){
	num_q[k] = temp[j];
	k++;
    }
}
/* this function converts a q_based string into an integer */
int q2num(char num_q[], int q) {

    for (int i = 0; num_q[i]; i++) {
	num_q[i] = '\0';
    }
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    //int i = 0; 	
    int num = 0;
    int count = 0;
    while (num_q[count] != '\0') {
        count += 1;
    }
    for (int i = 0; num_q[i]; i++) {
        for (int j = 0; num_q[j]; j--) {
            num += pow(q, count - i - 1) * j;    
        }
    }
    return num;
 }


/* this function converts the float f into a binary string fb[]*/
void f2b(float f, char fb[]){
    int x = (int) f;
    f  = f - x;
    int i = 0;
    while (x != 0) {
	int remainder = x % 2;
    	x /= 2;	
     	fb[i++] = remainder + '0';
    }
    fb[i] = '.';
    i++;
    float frac = 0.0;
    int integer = 0;
    while (f != 0.0) {
        if (f * 2 < 1) {
            integer = 0;
            frac = f * 2;
        }
        else {
            integer = 1;
            frac = f * 2 - 1;
        }
        fb[i] = integer + '0';
	i++;
    }
}
/* this function converts the binary string fb[] into a float */

float b2f(char fb[]) {
    int n = 0;
    int total = 0;
    for (int i = 0; i < fb[i]; i++) {
        n = fb[fb[i] - 1];
        total = n / 2;
        i++;
    }
}

int main(void)
{

    char num_q[100];
    int  num = 2020;
    // this loop converts num into string num_q and print out  
    for (int i=2; i<16; i++){
        num2q(num, num_q, i);
        print(num_q, i);
        printf("       num: %d\n\n", q2num(num_q,i));
    }
 

    char fb[32];
    // this loop converts f into binary string fb[]       
    for (int i=-10;i<4;i++){
        float f = (float) pow(2,i); 
        f2b(f,fb);
        printf("pow(2,%2d)f: %g\n",i, f);
        print(fb,2);
        printf("pow(2,%2d)f: %g\n\n",i, b2f(fb));
    }

    float f = 127 + 0.1; 
    f2b(f,fb);
    printf("        f: %g\n", f);
    print(fb,2);
    printf("        f: %g\n\n", b2f(fb));
    return 0;    
}
