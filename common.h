/* 
	通用功能函数的声明位置  => 🌟 在这里统一进行声明的引入
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define INCOME "收入"// C 语言定义常量, 宏定义, 这些常量全局生效
#define EXPAND "支出"// C 语言定义常量, 宏定义, 这些常量全局生效
#define FILENAME "/Users/aic/Desktop/AccountTool_BaseCLI/data/accountData.txt" // C 语言定义常量, 宏定义, 这些常量全局生效

using namespace std;


// 👇 声明通用功能函数


// 绘制菜单的函数 => 都在 menu.cpp 内 ————————————————————————————————————————————————————————————————————————————————
void showMainMenu(); 	
void showAccountMenu();
void showQueryMenu();


// 读取键盘输入的函数, 都是返回 char 类型的值 => 都在 read_input.cpp 内 ————————————————————————————————————————————————————————————————————————————————
char readMenuSelected(int options); // 👀 校验用户输入的菜单选项, options 表示菜单的选项个数
char readQuitConfirm(); // 👀 校验用户输入的是否为 Y 或者 N
int readAmount(); // 👀 校验用户输入的账单金额