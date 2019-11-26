#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Erno");

int hello_init(void) {
	printk(KERN_DEBUG "Hello World\n");
	return 0;
}

void hello_exit(void) {
	printk(KERN_DEBUG "Goodbye world\n");
}

module_init(hello_init);
module_exit(hello_exit);
