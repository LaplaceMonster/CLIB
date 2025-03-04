#include <stdio.h>
#include "log.h"
 int main()
 {
    /*
    该库虽然提供了6个日志函数，但是只有一个log_log函数，6个函数都是log_log的宏定义，
    只是level参数不同
    该库提供了一个结构体log_Event，用于存储日志信息，该结构体包含了日志信息的各种属性
    va_list ap;：可变参数列表，用于存储传递给日志函数的可变参数。
    const char *fmt;：格式化字符串，定义日志消息的格式。
    const char *file;：源文件名，指示产生日志的源代码文件。
    struct tm *time;：时间结构体，表示日志记录的时间。
    void *udata;：用户数据指针，可用于传递用户自定义的数据。
    int line;：行号，指示产生日志的源代码行号。
    int level;：日志级别，表示日志的严重程度或类型。
    */
    
    //1 设置日志级别
     //log_set_level(LOG_INFO);
    //2 设置日志回调函数，每当日志记录时会调用这个回调函数
    //log_add_callback(file_callback, stdout, LOG_INFO);
    //3 设置日志锁 保证线程安全，防止多个线程同时写日志
    //log_set_lock(lock_callback, NULL);
    //4 设置日志是否静默 若为真则不会输出到标准输出上（一般为控制台）
    //log_set_quiet(false);
    //5 打印日志
    //log_trace("This is a trace message");
   //  log_debug("This is a debug message");
   printf("hello world\n");
   log_debug("This is a debug message");
   log_info("This is a info message");
   log_warn("This is a warn message");
   log_error("This is a error message");
   log_fatal("This is a fatal message");
   log_info("This is a info message");
   log_warn("This is a warn message");
    return 0;
 }