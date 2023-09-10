# AccountTool_BaseCLI
Simple account tool, base on cli~

# 编译 - 只需要编译具体实现 (.cpp), 不需要编译头文件(.h)
-[旧编译方式] g++ main.cpp menu.cpp read_input.cpp operations.cpp -o account
-[新编译方式 C++11 以上] g++ -std=c++11 main.cpp menu.cpp read_input.cpp operations.cpp -o account

# 运行
- ./account
