/*
 * Arithmetic calculations and utilities for big numbers (larger than %lld)
 * with char array.
 * Support positive integer only.
 *
 * 极大数（比 long long 大）算术计算及工具，使用字符数组。
 *
 *
 * file:   bignumber.h
 * Author: Bruce Frank Wang
 * Date:   Oct 29, 2016
 */
 
#ifndef _BIGNUMBER_H_
#define _BIGNUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 加法
char *bnAdd(const char *a, const char *b);

// 减法
// char *bnSubtract(const char *a, const char *b);

// 乘法
char *bnMultiply(const char *a, const char *b);

// 除法（整除）
// char *bnDivide(const char *a, const char *b);

// 取模（余数）
// char *bnModulo(const char *a, const char *b);

// 阶乘
char *bnFactorial(long long n);

// 指数
// 对数


// Utilities

// 取得一个整数的位数
size_t getDigit(long long n);

// 转换整数为字符串
char *bnFromInteger(long long n);

// 打印大数
void bnPrint(const char *bn, const int printPrefixZero);

// 移除前导零
char *bnRemovePrefixZero(const char *bn);

#endif /* _BIGNUMBER_H_ */
