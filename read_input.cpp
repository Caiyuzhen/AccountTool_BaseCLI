/* 读取用户输入的函数, 读取输入的金额、读取确认退出的信息、校验输入的合法性、返回正确的值 */
#include "common.h"// 统一引入所有的头文件



// 【主菜单选择】读取并校验用户输入的函数, 返回字符串类型的数字 ————————————————————————————————————————————————
char readMenuSelected(int options) {
	//保存用户输入的所有信息
	string str;

	while (true) {
		// 表示读取【命令行】的用户输入信息, 并保存在 【str】中
		getline(cin, str); 

		// 1. //校验合法性, 判断用户输入的是否为数字, 避免用户输入一堆信息, 🚀 str.size() != 1 表示只能输入一位数
		if(str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options) { // 本质是用 ASCII 阿斯特码来判断,  str[0] - '0' <= 0 表示输入的数字小于 0, str[0] - '0' > options 表示输入的数字大于 options 
			cout << "\n 输入有误, 请重新输入: ";
		} else {
			break; //输入合法, 退出循环 
		}
	};

	// 2. 返回用户输入的合法数字
	return str[0];
}



// 【退出菜单的选择】读取并校验用户输入的函数, 返回字符串类型的数字 ————————————————————————————————————————————————
char readQuitConfirm() { // 确认退出的功能
	//保存用户输入的所有信息
	string str;

	while (true) {
		// 表示读取【命令行】的用户输入信息, 并保存在 【str】中
		getline(cin, str); 

		// 1. //校验合法性, 判断用户输入的是否为数字, 避免用户输入一堆信息, 🚀 str.size() != 1 表示只能输入一位数
		if(str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') { // ⚡️⚡️判断是否是 Y 或者 N, 🔥🔥 toupper 表示转换为大写字母, 让用户可以随意输入大小写！
			cout << "\n 输入有误, 请重新输入 (Y/N): ";
		} else {
			break; //输入合法, 退出循环 
		}
	};

	// 2. 返回用户输入的合法数字
	return toupper(str[0]); // 🚀🚀 返回大小写 Y 或 N
}



// 【校验用户输入的账单金额】, 然后返回输入的金额 ————————————————————————————————————————————————
int readAmount() {
	// 保存用户输入的金额
	int amount; 
	string str; //还是先保存用户输入的字符串

	while (true) {
		// 表示读取【命令行】的用户输入信息, 并保存在 【str】中
		getline(cin, str);  // 🚀🚀 cin 表示获得用户的输入, 并保存在 str 内！

		// 1. //校验合法性, 把用户输入的内容都转为整数类型
		try { // stoi 的会报错不影响程序运行, 只会抛出错误
			amount = stoi(str); // 🚀🚀 stoi 表示把字符串转为整数, 如果转换失败, 则返回 0 => string to int
			break; // 输入合法, 退出循环
		} 
		catch(invalid_argument error) { // ❌ invalid_argument 为参数异常的类型
			cout << "\n 输入有误, 请输入正确的数字: ";	
		}
	};

	// 2. 返回用户输入的合法数字
	return amount; // 🚀🚀 返回大小写 Y 或 N
}
