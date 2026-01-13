#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

// Default values  
char * name = "Embedded";
int loop_count = 0;

module_param(name, charp, S_IRUGO);
module_param(loop_count, int, S_IRUGO);

static int
test_arguments_init(void)
{
	printk(KERN_INFO"%s : In init\n", __func__);
	printk(KERN_INFO"%s : Loop count:%d\n", __func__, loop_count);

	for(int i = 0 ; i < loop_count; i++)
	{
		printk(KERN_INFO"%s : Hi %s\n", __func__, name);
	}

	return 0;
}


static void
test_arguments_exit(void)
{
	printk(KERN_INFO"%s : In exit\n", __func__);
}

module_init(test_arguments_init);
module_exit(test_arguments_exit);
