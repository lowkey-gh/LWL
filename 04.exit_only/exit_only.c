#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static void __exit test_exit(void)
{
	printk(KERN_INFO"%s : In exit\n", __func__);
}

module_exit(test_exit);
