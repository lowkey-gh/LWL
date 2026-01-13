/**
 *	PS = doesn't work with newer kernels
 */

#include <linux/module.h>

MODULE_LICENSE("GPL");

int 
init_module(void)
{
	printk(KERN_INFO"%s : Begin\n", __func__);
	return 0;
}

void
cleanup_module(void)
{
	printk(KERN_INFO"%s : End\n", __func__);
}
