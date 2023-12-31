/* 
	结构体的定义, Model 层操作函数的声明, 每条数据是一个 AccountItem 结构体, 保存在 Vectors 数组中

	具体功能函数 => 对 Model 层的操作
 */
#pragma once
#include "common.h" //🔥在 common.h 中统一引入了所有的头文件, 所以这里不需要再次引入



// 1. 🔥定义数据的结构体 ————————————————————————————————————————————————————————————————————————————————————————————————————————————
struct AccountItem {
	string itemType; // 每条数据的类型
	int amount; // 金额总数
	string detail; //备注
};



// 👇 Model 层的操作 ————————————————————————————————————————————————————————————————————————————————————————————————————————————
// 2.加载账单
void loadDataFromFile(vector<AccountItem>& allItems); // 🚀🚀 注意, 需要定义为【引用类型的参数】 => 使用指针或者引用！

// 3. 编辑账单
void editAccountAction(vector<AccountItem>& allItems); // 🚀🚀 注意, 需要定义为【引用类型的参数】 => 使用指针或者引用！

// 4. 记录支出
void addInCome(vector<AccountItem>& allItems); //重载, 在 operations.cpp 内具体实现

// 4. 记录收入
void expand(vector<AccountItem>& allItems); //重载, 在 operations.cpp 内具体实现

// 5. 写入文件
void insertIntoFile(const AccountItem& allItems); //重载, 在 operations.cpp 内具体实现

// 6. 查询过滤账单
void queryAccountAction(const vector<AccountItem>& allItems); // 🚀🚀 （查询不改变引用内容, 所以只是引用！！）注意, 需要定义为【引用类型的参数】 => 使用指针或者引用！
void queryItems(const vector<AccountItem>& allItems);
void queryItems(const vector<AccountItem>& allItems, const string type);
void printItem(const AccountItem& item);
