/* 账目的操作:加载数据、操作数据、查询数据 */
#include "common.h"// 统一引入所有的头文件
#include "account_Item.h" // 引入数据结构体, 才能拿到 AccountItem 类型的数据



// 加载账单数据的功能 ————————————————————————————————————————————————————————————————————————
void loadDataFromFile(vector<AccountItem>& allItems) {
	ifstream input(FILENAME); //拿到文件数据 => 在 common.h 中定义了全局变量

	AccountItem item; // 逐行读取每条账目, 并放入 AccountItem

	while(input >> item.itemType >> item.amount >> item.detail) { // 🔥🔥逐词读取, 这样更好拆分 类型、总数、备注
		allItems.push_back(item); // push_back 为 vector 的方法, 用于向数组中添加元素
	}
}



// 进行记账的功能(收入或支出) ————————————————————————————————————————————————————————————————————————
void editAccountAction(vector<AccountItem>& allItems) {
	//1.读取用户的输入信息 (账单、类型、备注)
	char keyboardInfo = readMenuSelected(3); // 3 是因为记账菜单有 3 个选项

	switch(keyboardInfo) {
		case '1': // 【收入】
		addInCome(allItems); // 传入整个账单, 记录收入
		break;

		case '2': // 【支出】
		expand(allItems); // 传入整个账单, 记录支出
		break;

		case '3': // 【退出到主菜单】
			break;
		default: 
			break;
	}
}


// 🌟 记录一笔收入的功能 (👆上面 editAccountAction 的子集)
void addInCome(vector<AccountItem>& allItems) {
	// 1.定义一条账目数据
	AccountItem item;

	// 2.类型 -> 收入
	item.itemType = INCOME; // 🔥🔥 INCOME 为常量, 在 common.h 中进行了宏定义

	// 3.与用户交互, 提示用户输入金额
	cout << "\n 输入本次收入金额: "; //用户输入就在后面, 所以不用 endl 换行

	// 🔥4.读取用户输入的金额, 并校验合法性（ => 在 read_input 内实现）, 然后存到 item.amount 中
	item.amount = readAmount(); // 存入 item.amount

	// 5.保存用户输入的备注
	cout << "\n 备注: ";
	getline(cin, item.detail); // 👈👈 cin 表示获得用户的输入, 并保存在 item.detail 内！

	// 6. 把这条账目 item, 添加到 allItems 数组中
	allItems.push_back(item);

	// 🔥7.持久化保存到文件中
	insertIntoFile(item);

	// 8. 显示成功信息
	cout << "\n ———————————— 🎉 记账成功！ ———————————— \n" << endl;
	cout << "\n 请按回车键返回主菜单..." << endl;

	// 9. 用户回车事件
	string line;
	getline(cin, line); //不做任何处理, 相当于直接丢弃获得的 line, 然后 return 回到 main 函数的 while 循环处, 这里刚好到 break 了, 所以毁回到【主菜单】
}


// 🌟 记录一笔支出的功能 (👆上面 editAccountAction 的子集)
void expand(vector<AccountItem>& allItems) {
	// 1.定义一条账目数据
	AccountItem item;

	// 2.类型 -> 支出
	item.itemType = EXPAND; // 🔥🔥 INCOME 为常量, 在 common.h 中进行了宏定义

	// 3.与用户交互, 提示用户输入金额
	cout << "\n 输入本次支出金额: "; //用户输入就在后面, 所以不用 endl 换行

	// 🔥4.读取用户输入的金额, 并校验合法性,（ => 在 read_input 内实现） 然后存到 item.amount 中
	item.amount = - readAmount(); // 存入 item.amount => ⚡️⚡️ 支出, 取负数！

	// 5.保存用户输入的备注
	cout << "\n 备注: ";
	getline(cin, item.detail); // 👈👈 cin 表示获得用户的输入, 并保存在 item.detail 内！

	// 6. 把这条账目 item, 添加到 allItems 数组中
	allItems.push_back(item);

	// 🔥7.持久化保存到文件中
	insertIntoFile(item);

	// 8. 显示成功信息
	cout << "\n ———————————— 🎉 记账成功！ ———————————— \n" << endl;
	cout << "\n 请按回车键返回主菜单..." << endl;

	// 9. 用户回车事件
	string line;
	getline(cin, line); //不做任何处理, 相当于直接丢弃获得的 line, 然后 return 回到 main 函数的 while 循环处, 这里刚好到 break 了, 所以毁回到【主菜单】
}


// ✏️ 将单条账单写入到文件中
void insertIntoFile(const AccountItem& item) { // 👈 allItems 本身不做更改, 而是新增
	// 创建一个 ofstream 对象 => 写入文件 => 直接写是覆盖, 🚀🚀 所以要用【追加】的方式写入
	ofstream outputFile(FILENAME, ios::out | ios::app); // 🚀🚀 ios::app 表示以追加(append)的方式进行文件的【写入】
	outputFile << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;//把 item.itemType、 item.amount、 item.detail 写入到文件中
	outputFile.close(); //停止写入流
}



// 进行账单查询的功能 ————————————————————————————————————————————————————————————————————————
void queryAccount() {

}