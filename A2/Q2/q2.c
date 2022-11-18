// Ankush Gupta
// 2021232


SYSCALL_DEFINE4( kernel_2d_memcpy, float**, dst, float**, src, int, row, int, col){
    float temp[row][col];
    int first  = __copy_from_user(temp, src, sizeof(temp));
    if (first != 0){
        printk("fail (from): look at internal implementation under SYSCALL_DEFINE4 for more details\n");
        return -1;
    }
    int second = __copy_to_user(dst, temp, sizeof(temp));
    if (second){
        printk("failed (to): look at internal implementation under SYSCALL_DEFINE4 for more details\n");
        return -1;
    }
    printk(KERN_INFO "kernel_2d_memcpy syscall executed successfully !!");
    return 0;
}
