//StudybarCommentBegin
//整个前缀看不懂，没关系，这个前缀的功能是给您准备可以读的文件的，你就专注于你要完成的函数功能即可。
#include <stdio.h>
#include <windows.h>
#include <Urlmon.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
#pragma comment(lib, "urlmon.lib") 

class  CurlDownloadFile
{
private:
	char filename[1000];
	char url[1000];
	int res;
public:
	CurlDownloadFile(char *inurl,char *infilename){
		srand(time(0));
    	sprintf(filename,"%s",infilename);
		//printf(filename);
	    sprintf(url,"%s?id=%u",inurl,rand());	
		//printf(url);
		res = URLDownloadToFile(NULL, url  , filename, 0, NULL);
		if(res != S_OK) {
			printf("%s open and saveto %s error!",url,filename);
			exit(0);
		}

	}
	~CurlDownloadFile()
	{
		DeleteFile(filename);
	}
};

void file_read_dosomething(char *filename);  //编写该函数

int main()
{
	CurlDownloadFile  mydownloadfile("http://vm.cau.edu.cn/~zlh/test1.txt","data.txt");

	file_read_dosomething("data.txt");
        return 1;

}

//StudybarCommentEnd
void file_read_dosomething(char *filename) {
    ifstream in(filename);
    string line;
    int words = 0, lines = 0;
    while (getline(in, line)) {
        lines++;
        bool inWord = false;
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == ' ' || line[i] == '\t') {
                if (inWord) {
                    words++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) words++;
    }
    cout << words << "," << lines << endl;
}