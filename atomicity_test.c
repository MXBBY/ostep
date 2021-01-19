
// 作者：mxbbylin
// 创建时间：2021-01-13 15:59
// 最后修改时间：2021-01-13 15:59
// 文件名：test_yzx.c
// 说明： 证明了多线程的原子性。
 
#include<threads.h>

long sum=0;

void do_sum(){
	for(int i=1;i<1000000;i++){
		sum++;;
	}
}

void print(){
	printf("sum=%ld",sum);
}

int main(){
	create(do_sum);
	create(do_sum);
	join(print);
	return 0;
}
