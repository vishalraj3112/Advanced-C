 //used to examine and change a signal action, or get more information from the signal call.
 #include <signal.h>

int sigaction(int signum, const struct sigaction *act,
                     struct sigaction *oldact);//signum,new action,old action


 struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };

siginfo_t {
               int      si_signo;     /* Signal number */
               int      si_errno;     /* An errno value */
               int      si_code;      /* Signal code */
               int      si_trapno;    /* Trap number that caused
                                         hardware-generated signal
                                         (unused on most architectures) */
               pid_t    si_pid;       /* Sending process ID */
               uid_t    si_uid;       /* Real user ID of sending process */
               int      si_status;    /* Exit value or signal */
               clock_t  si_utime;     /* User time consumed */
               clock_t  si_stime;     /* System time consumed */
               sigval_t si_value;     /* Signal value */
               int      si_int;       /* POSIX.1b signal */
               void    *si_ptr;       /* POSIX.1b signal */
               int      si_overrun;   /* Timer overrun count;
                                         POSIX.1b timers */
               int      si_timerid;   /* Timer ID; POSIX.1b timers */
               void    *si_addr;      /* Memory location which caused fault */
               long     si_band;      /* Band event (was int in
                                         glibc 2.3.2 and earlier) */
               int      si_fd;        /* File descriptor */
               short    si_addr_lsb;  /* Least significant bit of address
                                         (since Linux 2.6.32) */
               void    *si_lower;     /* Lower bound when address violation
                                         occurred (since Linux 3.19) */
               void    *si_upper;     /* Upper bound when address violation
                                         occurred (since Linux 3.19) */
               int      si_pkey;      /* Protection key on PTE that caused
                                         fault (since Linux 4.6) */
               void    *si_call_addr; /* Address of system call instruction
                                         (since Linux 3.5) */
               int      si_syscall;   /* Number of attempted system call
                                         (since Linux 3.5) */
               unsigned int si_arch;  /* Architecture of attempted system call
                                         (since Linux 3.5) */
           }


//example for sa_handler:

void termination_handler(){
//some action
}


int main(void){


struct sigaction new_action,old_action;

new_action.sa_handler=termination_handler;//attaching our custom handler to sa_handler
sigemptyset(&new_action.sa_mask);//setting the masks
new_action.sa_flags=0;//setting the flags
sigaction (SIGNINT , NULL , &old_action);//first setting the old handler

if(old_action.sa_handler != SIG_IGN)
    sigaction(SIGINT,&new_action,NULL);//setting the new handler


}


// sa_sigaction

static void hdl(int sig, siginfo_t *signonfo,void *context){

printf("Sending PID:%ld,UID:%ld\n",signonfo->si_pid,signonfo->si_uid);

}

int main(){

struct sigaction adt;

act.sa_sigaction=&hdl;
//act.sa_sigaction=hdl; would also do

act.sa_flags=SA_SIGINFO;//used to tell sigaction to use sa_sigaction


if(sgiaction(SIGTERM, &act,NULL)<0){
    perror("sigaction");
    return 1;
}

}
