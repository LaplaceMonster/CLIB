#ifndef MYLIB_H
#define MYLIB_H

#ifdef BUILDING_DLL
  #define DLL_EXPORT __declspec(dllexport)
#else
  #define DLL_EXPORT __declspec(dllimport)
#endif

// 函数声明
DLL_EXPORT int add(int a, int b);
DLL_EXPORT int subtract(int a, int b);

#endif // MYLIB_H
