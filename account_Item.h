/* 
	结构体的定义, Model 层操作函数的声明, 每条数据是一个 AccountItem 结构体, 保存在 Vectors 数组中
 */
#pragma once;
#include "common.h" //🔥在 common.h 中统一引入了所有的头文件, 所以这里不需要再次引入


// 1. 定义数据的结构体
struct AccountItem {
	string itemType; // 每条数据的类型
	int amount; // 金额总数
	string detail; //备注
};



// 2.针对账目数据 Model 进行操作的函数声明 （增删改查）
void loadDataFromFile(vector<AccountItem>& allItems); // 🚀🚀 注意, 需要定义为【引用类型的参数】 => 使用指针或者引用！