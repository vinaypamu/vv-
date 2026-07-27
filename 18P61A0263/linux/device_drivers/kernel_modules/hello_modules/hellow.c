#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/printk.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>


struct my_pcd{
	dev_t device_number;
	struct cdev pcd_cdev;
	struct file_operations fops;
	struct class * class_ptr;
	struct device * device_ptr;
};

struct my_pcd pcd;
#undef pr_fmt
#define pr_fmt(fmt) "%s: " fmt,__func__

static int __init pcd_entry(void)
{
	alloc_chrdev_region(&(pcd.device_number),0,1,"pcd_device");
	pr_info("major and minor numbers <major>:<minor> %d:%d\n",MAJOR(pcd.device_number),MINOR(pcd.device_number));
	cdev_init(&(pcd.pcd_cdev), &(pcd.fops));

	pcd.pcd_cdev.owner=THIS_MODULE;

	cdev_add(&(pcd.pcd_cdev),pcd.device_number,1);

	pcd.class_ptr=class_create(THIS_MODULE,"class_pcd");

	pcd.device_ptr=device_create(pcd.class_ptr,NULL,pcd.device_number,NULL,"pcd_device");

	printk(KERN_INFO "module is loaded\n");
	return 0;

}

static void __exit pcd_cleanup(void)
{
	device_destroy((pcd.class_ptr),pcd.device_number);
	pr_info("device is destroyed mean device is removed\n");
	class_destroy((pcd.class_ptr));
	pr_info("class is destroyed\n");
	cdev_del(&(pcd.pcd_cdev));
	pr_info("removing cdev registratin from vfs by using cdev_del\n");
	unregister_chrdev_region(pcd.device_number,1);
	pr_info("unregistering device number which is major and minor number");
	pr_info("modile unloading\n");
	
}

module_init(pcd_entry);
module_exit(pcd_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vinay");
MODULE_DESCRIPTION("My First Kernel Module");

