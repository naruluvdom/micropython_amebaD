
.PHONY: all

OS := $(shell uname)

all:
ifeq ($(findstring CYGWIN, $(OS)), CYGWIN)
	mkdir -p cygwin
	tar -jxvf ameba_d_toolchain_windows-1.0.1.tar.bz2 -C cygwin/
else
	mkdir -p linux
	tar -jxvf ameba_d_toolchain_linux_64-1.0.1.tar.bz2 -C linux/
endif
