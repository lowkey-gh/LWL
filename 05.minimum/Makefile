obj-m := hello.o

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean
