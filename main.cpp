/* 
	核心功能:
		记账功能
			1.读取键盘输入的信息
			2.把信息保存在 AccountItem 对象中, 并添加到 Vectors 数组中, 同时写入文件

		查询功能
			1.for 循环遍历整个 Vectors
			2.通过条件筛选打印账单数据, 并统计总和

		退出功能
			1.提示用户确认退出
			2.用户确认后,更改标志位, 退出循环

	实现步骤:
		实现整体架构
			在【头文件】account_item.h 中定义好结构体
			在【头文件】 common.h 中定义通用配置
			在主入口函数中 main.cpp 中, 实现主流程

		实现具体功能
			在 menu.cpp 中实现菜单功能, 并在 common.h 中进行声明
			在 read_input.cpp 中实现读取用户输入的功能(读取输入的金额、读取确认退出的信息、校验输入的合法性、返回正确的值), 并在 common.h 中进行声明
			在 operation.cpp 中定义从文件中加载数据, 写入记账数据, 查询记账数据的函数

*/
#include "account_Item.h"
#include "common.h"

//	主入口函数 
int main() {
	//第 1 步: 加载文件中的账目数据
	vector<AccountItem> allItems;
	vector<AccountItem>& allItemsRef = allItems; // 定义引用类型的参数！

	loadDataFromFile(allItemsRef); //🔥【每次登录程序都需要加载文件数据】 在 account_Item.h 内进行声明, 在 operations.cpp 内进行实现 , 因为定义的是引用类型的参数, 所以这里也要传入引用的参数

	// 是否退出程序的主循环标志位
	bool quit = false;
	while(!quit) {
		//第 2 步: 显示主菜单
		showMainMenu();

		//第 3 步: 读取键盘输入的信息, 并做合法性的校验
		char keyboardInfo = readMenuSelected(3); // 3 是因为主菜单有 3 个选项

		switch(keyboardInfo) {
			case '1': //1 为记账功能
				showAccountMenu(); //【显示记账菜单】 => 具体的功能函数
				editAccountAction(allItemsRef); // 进行记账, 追加账单数据 (修改)
				break;
			case '2':
				showQueryMenu(); //【显示查询菜单】 => 具体的功能函数
				// queryAccount(allItemsRef); // 进行查询
				break;
			case '3': // 【显示退出程序菜单】
				cout << "\n 确认退出记账本？(Y/N): ";
				if(readQuitConfirm() == 'Y') { //在【read_input.cpp】内实现 => 用户输入 Y 后, 则确认退出
					quit = true;
				};
				break;
			default: //如果输入的不是 1、2、3, 则留在主菜单
				break;
		}

		cout << endl; //每次输出的菜单换个行
	}
}