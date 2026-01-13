#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void
func(void);

static int 
test_hello1_init(void)
{
	printk(KERN_INFO"%s: in init\n", __func__);
	return 0; // check for another reutrn code
}

static void 
test_hello1_exit(void)
{
	printk(KERN_INFO"%s: in exit\n", __func__);
}

module_init(test_hello1_init);
module_exit(test_hello1_exit);

