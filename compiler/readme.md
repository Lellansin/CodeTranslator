<h1>Microsoft (R) C/C++ 编译器</h1>

<h2>配置</h2>

需讲bin目录加入path环境变量
并添加新的环境变量INCLUDE和LIB

可以查看根目录下的config.bat


<h2>使用</h2>

双击open可以自动配置运行环境, 并新建cmd窗口。
此时可以输入 cl 然后回车看到其提示：


用于 x64 的 Microsoft (R) C/C++ 优化编译器 16.00.40219.01 版
版权所有(C) Microsoft Corporation。保留所有权利。

用法: cl [ 选项... ] 文件名... [ /link 链接选项... ]


<h2>测试</h2>

当前目录下有个test.c文件。

可以执行 cl test.c 对其进行编译连接

生成的obj和exe文件会直接出现在当前目录下


<h2>支持</h2>

尚未对当前编译器做详细检测，有可能出现LIB文件缺失。
如果发现问题请联系lellansin@gmail.com，以便补救。

粗略检测,支持的库包括:

assert.h
ctype.h
errno.h
float.h
limits.h
locale.h
math.h
setjmp.h
signal.h
stdarg.h
stddef.h
stdio.h
stdlib.h
string.h
time.h

conio.h
dos.h
fcntl.h
io.h
process.h
share.h
malloc.h


不支持的库:

alloc.h
bios.h
dir.h
erron.h
graphics.h
limit.h
mem.h
sys\stat
sys\types
sys\time
value.h