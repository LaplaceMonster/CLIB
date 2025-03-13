#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utarray.h"
#include "utstring.h"
#include "uthash.h"
typedef struct {
  int id;
  char name[10];
  UT_hash_handle hh;
} User;

void Array_demo();//Array的用法模板
void string_demo();//字符串的用法模板
void hash_demo();//哈希表的用法模板
void addUser(User **users,int id,char *name);//hash表的添加元素
User *findUser(User **users,int id);//hash表的查找元素
int main() {
  
    
    //Array_demo();
    //string_demo();
    hash_demo();
  return 0;
}

/*

*/
void Array_demo()
{
  UT_array *nums;//定义一个指针用于指向动态数组和管理它
  int i, *p;

  /*
  utarray_new这个函数用于创建一个新的动态数组 nums。
  第二个参数是一个指向元素类型描述符的指针。
  这里使用的是 ut_int_icd，它是一个内置的描述符，用于描述数组中的元素类型是 int（整数）。
  具体来说，ut_int_icd 是一个 UT_icd 结构体，
  描述了元素的类型、大小、比较函数等。utarray_new 会根据这个描述符初始化数组。
  */
  utarray_new(nums,&ut_int_icd);

  for(i=0; i < 10; i++) 
  utarray_push_back(nums,&i);//向数组中添加10个元素


  /*
  tarray_front(nums): 返回数组的第一个元素的指针。
  返回的是 void* 类型的指针，通常需要强制转换为合适的类型。
  这里将它转换为 int*，因为数组中的元素类型是 int。
  utarray_next(nums, p): 返回下一个元素的指针。
  p 是当前元素的指针，utarray_next 函数根据 p 获取下一个元素的地址。
  如果没有更多的元素，utarray_next 会返回 NULL，循环结束。
  */
  for(p=(int*)utarray_front(nums);p!=NULL;p=(int*)utarray_next(nums,p)) {
    //此循环条件可以实现遍历该数组
    printf("%d\n",*p);
  }

  utarray_free(nums);//释放内存

  /*
  字符串数组的用法
  */
   UT_array *strs;
  char *s, **pStr;

  utarray_new(strs,&ut_str_icd);

  s = "hello";
  utarray_push_back(strs, &s);
  s = "world"; 
  utarray_push_back(strs, &s);

  pStr = NULL;
  while ( (pStr=(char**)utarray_next(strs,pStr))) {
    //遍历该数组
    printf("%s\n",*pStr);
  }

  utarray_free(strs);


  /*
  其他数据类型如：double
  */
  UT_icd UT_double={sizeof(double),NULL,NULL,NULL};//我们已经将double类型的数据与UT_icd结构体耦合
  UT_array *doubles;
  double d, *pD;

  utarray_new(doubles,&UT_double);//创建一个新的动态数组 并通过我们定义的指针doubles来管理这个数组

  d = 1.1;
  utarray_push_back(doubles, &d);
  d = 2.2;
  utarray_push_back(doubles, &d);

  pD = NULL;
  while ( (pD=(double*)utarray_next(doubles,pD))) {
    //utarray_next函数将返回下一个指针 我们需要的是double类型的指针
    printf("%.2f\n",*pD);
  }

  utarray_free(doubles);

}

void string_demo()
{
    UT_string *s;//定义一个指针用于指向字符串和管理它
    utstring_new(s);//创建一个新的字符串 初始化和内存分配
    
    utstring_printf(s,"hello %s","world");//将字符串格式化输出到s中
    
    printf("%s\n",utstring_body(s));//输出字符串
    
    utstring_free(s);//释放内存
}


void hash_demo()
{

  User *users =NULL;//定义一个指针用于指向哈希表和管理它
  addUser(&users,1,"tom");
  addUser(&users,2,"jerry");
  User *user_temp=findUser(&users,1);
  printf("user_temp:%s\n",user_temp->name);

}

void addUser(User **users,int id,char *name)
{

  User *user = (User*)malloc(sizeof(User));
  user->id = id;
  strcpy(user->name,name);
  HASH_ADD_INT(*users,id,user);
}
User *findUser(User **users,int id)
{
  User *user;
  HASH_FIND_INT(*users,&id,user);
  return user;
}