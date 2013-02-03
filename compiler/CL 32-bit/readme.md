<h1>Microsoft (R) 32-bit C/C++ Optimizing Compiler</h1>

Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168 for 80x86

Copyright (C) Microsoft Corp 1984-1998. All rights reserved.

This is just for study, and do not for commercial use, if you like this soft please buy the genuine.

<h2>Config</h2>

You should config the environment variables.

Add the bin directory to the path environment variable, and include directory path to a new environment variable named INCLUDE, and the same for lin directory the varibale named LIB.

See the config.bat file for detail.

<h2>Use</h2>

Double-click the open.bat, it will config the environment variables automatically.

Then you can type "CL" and press Enter to see the prompt:

<pre>
Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168 for 80x86
Copyright (C) Microsoft Corp 1984-1998. All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
</pre>


<h2>Test</h2>

There is a test.c file at the current directory, and you can do:

<pre>
D:\Compiler> cl test.c
D:\Compiler> test.exe
</pre>

To compile the tset.c, and run the test.exe to see the result.


<h1>Microsoft (R) 32位 C/C++ 编译器</h1>


<h2>配置</h2>

需将bin目录加入path环境变量, 并添加新的环境变量INCLUDE和LIB

可以查看根目录下的config.bat


<h2>使用</h2>

双击open.bat可以自动配置运行环境。

此时可以输入 cl 然后回车看到其提示：

<pre>
Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168 for 80x86
Copyright (C) Microsoft Corp 1984-1998. All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
</pre>


<h2>测试</h2>

当前目录下有个test.c文件。

<pre>
D:\Compiler> cl test.c
D:\Compiler> test.exe
</pre>

可以执行 cl test.c 对其进行编译连接
生成的obj和exe文件会直接出现在当前目录下，直接test.exe运行该文件即可看到效果


<h2>支持</h2>

尚未对当前编译器做详细检测，如果发现头文件中有定义，但是编译时却提示找不到符号，则可能是LIB文件缺失。

如果有发现这类，或其他问题，请联系 lellansin@gmail.com ，以便修补。


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

不支持的库:

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
