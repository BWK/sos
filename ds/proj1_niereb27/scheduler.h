#ifndef scheduler_h
#define scheduler_h
#include <vector>
#include <string>
using namespace std;


class scheduler {
  private:

    //these are my job queues
    list<job> wait_queue, run_queue;

    //number of available processors
    int free_procs;

    //number of processors in use
    int used_procs;

    //keep track of used ids
    int next_id;

    //insert job takes 3 params, creates job object, puts in queue
    //checks that there are sufficient procs, and that ticks is non-zero
    void insert_job(string job_description, int n_procs, int n_ticks);

    //find shortest could return a job or the node position of a job
    //shortest means smallest number of ticks
    job find_del_short(job**);

    //check available will be called by insert_job
    int check_available ();

    //decrement timer
    void decrement_timer ();
    
    //release_procs will reassign used_procs to free_procs
    void release_procs()
    void tick ();
  public:  

    void start ();
    scheduler(
};
#endif
