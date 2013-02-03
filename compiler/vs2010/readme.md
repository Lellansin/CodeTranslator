<h1>Microsoft (R) C/C++ Compiler</h1>

Copyright (C) Microsoft Corporation

if you do not have installed this visual stdio, you may not use this compiler lawful.

<h1>Microsoft (R) C/C++ 编译器</h1>

<h2>配置</h2>

需将bin目录加入path环境变量，并添加新的环境变量INCLUDE和LIB。

可以查看根目录下的config.bat


<h2>使用</h2>

双击open可以自动配置运行环境, 并新建cmd窗口。此时可以输入 cl 然后回车看到其提示：

<pre>
用于 x64 的 Microsoft (R) C/C++ 优化编译器 16.00.40219.01 版
版权所有(C) Microsoft Corporation。保留所有权利。

用法: cl [ 选项... ] 文件名... [ /link 链接选项... ]
</pre>

<h2>测试</h2>

当前目录下有个test.c文件。

可以执行 cl test.c 对其进行编译连接

生成的obj和exe文件会直接出现在当前目录下


<h2>支持</h2>

尚未对当前编译器做详细检测，有可能出现LIB文件缺失，<font style="color">仅支持win7</font>。

如果发现问题请联系lellansin@gmail.com，以便补救。

粗略检测,支持的库包括:

<ul>
	<li>assert.h</li>
	<li>ctype.h</li>
	<li>errno.h</li>
	<li>float.h</li>
	<li>limits.h</li>
	<li>locale.h</li>
	<li>math.h</li>
	<li>setjmp.h</li>
	<li>signal.h</li>
	<li>stdarg.h</li>
	<li>stddef.h</li>
	<li>stdio.h</li>
	<li>stdlib.h</li>
	<li>string.h</li>
	<li>time.h</li>
	<li>conio.h</li>
	<li>dos.h</li>
	<li>fcntl.h</li>
	<li>io.h</li>
	<li>process.h</li>
	<li>share.h</li>
	<li>malloc.h</li>
</ul>

<li>不支持的库:</li>

<ul>
	<li>alloc.h</li>
	<li>bios.h</li>
	<li>dir.h</li>
	<li>erron.h</li>
	<li>graphics.h</li>
	<li>limit.h</li>
	<li>mem.h</li>
	<li>sys\stat</li>
	<li>sys\types</li>
	<li>sys\time</li>
	<li>value.h</li>
</ul>