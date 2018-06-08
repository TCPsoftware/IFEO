#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void end(bool);
void read();
void add(string str);
	ifstream fin;
	string s;
int main(){
	string ss="使用前请检查是否已管理员权限运行，否则一个都无法导入！\n\n请关闭所有杀毒软件及其后台进程，否则会拒绝访问！\n\n运行时请点击每一次的确定按钮并查看提示框，是否成功导入\n\n请确认此程序是以管理员权限执行的，如果不是，请点“否”结束执行\n并以管理员权限重新运行\n\n\n\n"; 
	int re = MessageBox(NULL,ss.c_str(),"提示", MB_ICONINFORMATION|MB_YESNO);
	if(re == 7){
		end(false);
		exit(0);
	}
//	system("del gmon.out /s /q");
	fin.open("ifeo.txt");
	if( (bool)(fin>>s) == false){
		string sss="检测到你没有编写IFEO.txt\n\n请将要映像劫持的程序名字写到该目录下IFEO.txt中\n\n每行一个，不要多余空格或换行！\n\n然后再运行此程序\n\n被写进去的这些程序将不能运行\n\n警告，请正确写入文件名，误写文件名可能会造成系统问题！！！\n\n";
		MessageBox(NULL,sss.c_str(),"未找到IFEO.txt", MB_ICONSTOP);
		fin.close();
		end(false);
	}
	else{
		add(s);
		read();
		fin.close();
		end(true);
	}
	return 0;
}
void read(){
	while( (bool)(fin>>s) != false){
		add(s);
	}
};
void add(string str){
	ofstream fout;
	string comm = "IFEO-"+str+".reg";
	fout.open(comm.c_str());
	fout<<"Windows Registry Editor Version 5.00"<<endl;
	fout<<endl;
	fout<<"[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\"+str+"]"<<endl;
	fout<<"@=\"\""<<endl;
	fout<<"\"Debugger\"=\"cmd /c exit\""<<endl<<endl;
	fout.close();
	string comm1;
	comm1 = "regedit "+comm;
	system(comm1.c_str());
	string comm2;
	comm2 = "del "+comm+" /s /q";
	system(comm2.c_str());
};
void end(bool flag){
	ofstream fout;
	if(flag){
		cout<<"\n\n\n所有操作已经完成！\n\n";
		system("pause");
	}
	else{
		cout<<"\n\n\n操作失败\n\n"; 
		system("pause");
	}
	fout.open("TEMP_RUN.bat");
	fout<<"timeout 3 & del gmon.out /q /s & del TEMP_RUN.bat & exit /q /s"<<endl;
//	fout<<"del TEMP_RUN.bat /q /s"<<endl;
//	fout<<"exit"<<endl;
	fout.close();

	system("cmd /c start TEMP_RUN.bat");
//	system("del gmon.out /s /q");
};
