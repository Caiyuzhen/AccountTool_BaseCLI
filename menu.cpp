/* 绘制交互菜单界面 */
#include "common.h" // 统一引入所有的头文件

// 绘制主菜单
void showMainMenu() {

	system("cls"); // ⚡️每次刷新页面, system 为底层的命令
	cout << "————————————————————————————————————" << endl;
	cout << "|******* Welcome to Account *******|" << endl;
	cout << "|             1.🖊️记账              |" << endl;
	cout << "|             2.🔍 查询             |" << endl;
	cout << "|             3.🚪 退出             |" << endl;
	cout << "————————————————————————————————————" << endl;
	cout << "\n 请输入选项(1~3): ";
}

// 绘制记账菜单
void showAccountMenu() {
	cout << "————————————————————————————————————" << endl;
	cout << "|******* Select Account type ******|" << endl;
	cout << "|             1.收入                |" << endl;
	cout << "|             2.支出                |" << endl;
	cout << "|             3.返回主菜单           |" << endl;
	cout << "————————————————————————————————————" << endl;
	cout << "\n 请输入选项(1~3): ";
}

// 绘制查询菜单
void showQueryMenu() {
	cout << "————————————————————————————————————" << endl;
	cout << "|***** Select Query condition *****|" << endl;
	cout << "|           1.统计所有账目           |" << endl;
	cout << "|           2.统计所有收入           |" << endl;
	cout << "|           3.统计所有支出           |" << endl;
	cout << "|           4.返回主菜单             |" << endl;
	cout << "————————————————————————————————————" << endl;
	cout << "\n 请输入选项(1~4): ";
}