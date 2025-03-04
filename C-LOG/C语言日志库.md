# C语言日志库

* 源码地址：https://github.com/rxi/log.c

## 使用方法

该日志库只有log.h和log.c两个文件，因此引入该库的方法很简单，只需要将两个文件放入个人工作文件夹参与编译即可。





该库提供了 6 个用于日志记录的函数式宏：

```
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
```

6个宏函数的底层只有一个函数：

```
#define log_trace(...) log_log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...)  log_log(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...)  log_log(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)
```



每个函数都采用 printf 格式字符串，后跟附加参数：

```
log_trace("Hello %s", "world")
```



导致具有给定格式的行打印到 stderr：

```
20:18:26 TRACE src/main.c:11: Hello world
```



#### log_set_quiet（布尔启用）



可以通过传递`true`给`log_set_quiet()`函数来启用安静模式。启用此模式时，库不会向输出任何内容`stderr`，但会继续写入文件和回调（如果已设置）。

#### log_set_level(int 级别)



可以使用函数设置当前日志记录级别`log_set_level()`。低于给定级别的所有日志都不会写入`stderr`。默认情况下级别为`LOG_TRACE`，这样就不会忽略任何内容。

#### log_add_fp(FILE *fp，int 级别)



可以使用该函数向库提供一个或多个将写入日志的文件指针`log_add_fp()`。写入文件输出的数据具有以下格式：

```
2047-03-11 20:18:26 TRACE src/main.c:11: Hello world
```



任何低于给定值的消息`level`都会被忽略。如果库无法添加文件指针，则返回小于零的值。

#### log_add_callback（log_LogFn fn，void *udata，int level）



可以使用函数向库提供一个或多个使用日志数据调用的回调函数`log_add_callback()`。回调函数传递一个`log_Event`包含`line`数字 `filename`、`fmt`字符串、`va`printf va_list`level`和给定的结构`udata`。

#### log_set_lock（log_LockFn fn，void *udata）



如果要从多个线程写入日志，则可以设置锁定函数。`true`如果要获取锁定或 `false`释放锁定，则向该函数传递布尔值以及给定`udata`值。

#### const char* log_level_string(int level)



以字符串形式返回给定日志级别的名称。