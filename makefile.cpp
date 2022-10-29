# Python header include: Put the path to Python.h here
includes = -I c:\Python310\include

# Numpy include: Put the path to numpy/arrayobject.h
includes +=  -I c:\python310\lib\site-packages\numpy\core\include

# Python libraries include: Add the path to the directory containing libpython*.a here
includes += -L C:\Python310\libs

# Link your Python version
linkings = -lpython310

# Compiler instructions
g++ main.cpp -I c:\Python310\include -I c:\python310\lib\site-packages\numpy\core\include -L C:\Python310\libs -lpython310