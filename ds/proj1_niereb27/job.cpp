using namespace std;

class job {
  public:

    // vars that job consists of
    const int n_procs;
    const int n_ticks;
    const int id;
    const string description;

    //constructors
    job(string job_description, int procs, int ticks, int job_id):
      description(job_description), n_procs(procs), n_ticks(ticks), id(job_id)

    {
    };
    
    //tick function that returns a bool
    bool tick() {
      if (--ticks_left <= 0)
        return (bool) (ticks_left = 0);
      return true;
    }

  private:
    int ticks_left;
}
