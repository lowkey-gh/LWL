#include <linux/kernel.h>

void func(void);

void 
func(void)
{
	printk(KERN_INFO"%s : Hello linux \n", __func__);
}
