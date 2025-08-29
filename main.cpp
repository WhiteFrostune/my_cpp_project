#include<iostream>
#include <stdlib.h> // 需要包含这个头文件来使用 system() 命令
using namespace std;
int main() {
    system("chcp 65001"); // 设置控制台为 UTF-8 编码
    cout << "启动！！！" << endl;
    return 0;
}
