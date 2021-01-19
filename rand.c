
// 作者：mxbbylin
// 创建时间：2021-01-15 16:25
// 最后修改时间：2021-01-15 16:25
// 文件名：rand.c
// 说明： 
 
#include <stdio.h>
#include <stdint.h>

int main(){
	uint64_t val;
	asm volatile ("rdrand %0":"=r"(val));
	printf("rdrand returns %016lx\n",val);
}
