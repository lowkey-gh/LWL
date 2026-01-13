#include <linux/kernel.h>
#include <linux/module.h>


MODULE_LICENSE("GPL");
static int hello_init(void)
{
	printk(KERN_INFO"%s: Begin.\n",__func__);
	return 0;
}

module_init(hello_init);
