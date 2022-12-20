# include <linux/kernel.h>
# include <linux/module.h>
# include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ankush_Gupta");
MODULE_DESCRIPTION("Print Module");

# define size 300
# define state1 "TASK_RUNNING"
# define state2 "TASK_INTERRUPTIBLE"
# define state3 "TASK_UNINTERRUPTIBLE"
# define state4 "__TASK_STOPPED"
# define state5 "__TASK_TRACED"

char buffer[size];

char * get_task(long state){
  if (state == TASK_RUNNING){
    return state1;
  }
  if (state == TASK_INTERRUPTIBLE){
    return state2;
  }
  if (state == TASK_UNINTERRUPTIBLE){
    return state3;
  }
  if (state == __TASK_STOPPED){
    return state4;
  }
  if (state ==  __TASK_TRACED){
    return state5;
  }
  sprintf(buffer,"Unknown Type:%ld\n",state);
  return buffer;
}

static int test_tasks_init(void){
    struct task_struct *task_list;
    unsigned int count = 0;
    printk("%s: In init\n", __func__);
    for_each_process(task_list) {
        printk("Process: %s\t PID:[%d]\t State:%s\n", task_list->comm, task_list->pid, get_task_state(task_list->state));
        count++;    
    }
    printk("Number of processes:%u\n", count);
    return 0;
}

static void test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}
module_init(test_tasks_init);
module_exit(test_tasks_exit);
