
// 作者：mxbbylin
// 创建时间：2021-01-11 16:07
// 最后修改时间：2021-01-11 16:46
// 文件名：threads.h
// 说明： 
 
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<pthread.h>

struct thread{
	int id;									//线程号
	pthread_t thread;				//pthread 线程
	void(*entry)(int);			//入口地址
	struct thread *next;		//链表
};

struct thread *threads;
void (*join_fn)();

static inline void *entry_all(void *arg){
	struct thread *thread=(struct thread *)arg;
	thread->entry(thread->id);
	return NULL;
}

static inline void create(void *fn){
	struct thread *cur=(struct thread *)malloc(sizeof(struct thread));
	assert(cur);
	cur->id=threads ? threads->id+1:1;
	cur->next=threads;
	cur->entry=(void(*)(int))fn;
	threads=cur;
	pthread_create(&cur->thread,NULL,entry_all,cur);
}

static inline void join(void (*fn)()){
	join_fn=fn;
}

__attribute__((destructor)) static void join_all(){
	for(struct thread *next; threads; threads=next){
		pthread_join(threads->thread,NULL);
		next=threads->next;
		free(threads);
	}
	join_fn ? join_fn():(void)0;
}



