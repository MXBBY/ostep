
// 作者：mxbbylin
// 创建时间：2021-01-12 15:59
// 最后修改时间：2021-01-12 16:08
// 文件名：test_1000t.c
// 说明：证明了线程共用内存。 
 
#include<threads.h>

int y=0;
void f(){
	static int x=0;
	printf("你好，我是线程：#%d\n",y++);
	while(1);
}

int main(){
	for(int i=0;i<8;i++){
		create(f);
	}
	join(NULL);
}
