/* 账目的操作:加载数据、操作数据、查询数据 */
#include "common.h"// 统一引入所有的头文件
#include "account_Item.h" // 引入数据结构体, 才能拿到 AccountItem 类型的数据


// 加载账单数据的功能
void loadDataFromFile(vector<AccountItem>& allItems) {
	ifstream input(FILENAME); //拿到文件数据

	AccountItem item; // 逐行读取每条账目, 并放入 AccountItem

	while(input >> item.itemType >> item.amount >> item.detail) { // 🔥🔥逐词读取, 这样更好拆分 类型、总数、备注
		allItems.push_back(item); // push_back 为 vector 的方法, 用于向数组中添加元素
	}
}



// 进行记账的功能
void accounting() {

}



// 进行账单查询的功能
void queryAccount() {

}