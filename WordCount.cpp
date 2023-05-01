#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string type;
    string filename;
    cout << "请输入统计类型：";
    getline(cin, type); // 从控制台读入统计类型
    cout << "请输入文件名：";
    getline(cin, filename); // 从控制台读入文件名

    ifstream file(filename); // 打开文件
    if (!file.is_open()) { // 检查文件是否成功打开
        cout << "文件打开失败！" << endl;
        return 1;
    }

    int charCount = 0; // 统计字符
    int wordCount = 0; // 统计单词
    string line;

    while (getline(file, line)) { // 按行读取文件内容
        charCount += line.length(); // 统计字符数
        wordCount += count_if(line.begin(), line.end(), ::isspace); // 统计单词数
    }
    if(type == "-w")
       cout << "字符数：" << charCount << endl; // 显示字符数
    if(type == "-c")
       cout << "单词数：" << wordCount << endl; // 显示单词数
    file.close(); // 关闭文件

    return 0;
}
