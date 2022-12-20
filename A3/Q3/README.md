the different states a process can be:

TASK_RUNNING: Process is either currently running or on a run-queue waiting to run

TASK_INTERRUPTIBLE: Process is sleeping/blocked. Can be runnable/awaken by a signal

TASK_UNINTERRUPTIBLE: Similar to TASK_INTERRUPTIBLE, but does not wakeup on a signal

__TASK_TRACED: Process is traced by a debugger e.g. ptrace

__TASK_STOPPED: Process execution has stopped. This happens when the task receives SIGSTOP, SIGTSTP, SIGTTIN or SIGTTOU signal or if it receives any signal while it is being debugged.

Let's start creating the module:

To do this the first thing we must do is to create our Kernel Module C code.
call.o has basic code for module which is self explaintory

To compile and use the module you have to do the following from the console:
Go to the directory: using cd
We compile with make and gcc: make
Install the module: using insmod
