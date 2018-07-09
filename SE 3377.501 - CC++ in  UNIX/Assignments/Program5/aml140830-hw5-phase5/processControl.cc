//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"
#define DAEMON_POOL_SIZE 1
#define BUF_SIZE 100            /* Large enough to hold maximum PID as string */





using namespace std;
void daemonSpawner (std::string daemonFlag);
void daemonProcess ( int command_fd, int response_fd);
void parseConfigFile ();
int read_pid ();
int check_pid ();
int write_pid ();
void open_log();
void close_log();
void close_pid();
void signal_HUP_Handler( int signum );
void signal_INT_Handler( int signum );
void signal_TERM_Handler( int signum );
void initiateWatchAndReadBlock();

// wrapper method for this file
void processControl(){

	std::string configFilePath = myMap.find(CONFIGFILE)->second;
	std::string daemonFlag = myMap.find(DFLAG)->second;
	std::string logFilePath = myMap.find(LOGFILE)->second;
	std::string numVersions = myMap.find(NUMVERSIONS)->second;
	std::string verboseFlag = myMap.find(VERBOSE)->second;
	std::string password = myMap.find(PASSWORD)->second;
	std::string watchDirectoryPath = myMap.find(WATCHDIR)->second;

	daemonSpawner(daemonFlag);

}




// create pool of deamons, hehehee
// how evil
void daemonSpawner (std::string daemonFlag){
	
	
	pid_t daemons[DAEMON_POOL_SIZE];
	int mainToDaemon_pipes[DAEMON_POOL_SIZE][2];
	int daemonToMain_pipes[DAEMON_POOL_SIZE][2];
	

	if
		(daemonFlag == "true"){
		for (int i = 0; i < DAEMON_POOL_SIZE; i++){
			
			pipe(mainToDaemon_pipes[i]);
			pipe(daemonToMain_pipes[i]);
			// daemons[i] is the process id
			daemons[i] = fork();

				
			if (daemons[i] == 0){
				// this fork created a daemon
				// close the write pipe on mainToDaemon
				// close the read pipe on daemonToMain
				close(mainToDaemon_pipes[i][1]);
				close(daemonToMain_pipes[i][0]);
						
				// Close all open file descriptors
				int x;
				for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
				{
					close (x);
				}
				
				// write to pid file
				// in daemon mode, we will not write the pid for the spawner
				// only write pid of daemon
				write_pid();
				
				daemonProcess(mainToDaemon_pipes[i][0], daemonToMain_pipes[i][1]);
				
				exit(1);

			}else if (daemons[i] == -1){
				// this fork returned an error
			}else{
				// this fork returned the source process
				// this is the process who spawns daemons
				// close the read pipe on mainToDaemon
				// close the write pipe on daemonToMain
				
				close(mainToDaemon_pipes[i][0]);
				close(daemonToMain_pipes[i][1]);

				// daemon process is already fired up in the background
				// now we will exit the spawner
				// this function is analogous to a wizard daemon spawner
				// the wizard exits, leaving the daemon in the background
				// the user can only interact with the daemon by knowing information about it
				// like its process id, which was logged before the spawner exits
				// "pid" is found in the cs3377dirmond.pid
				// this would be one way to kill the daemon that this source process just spawned
				// example 
				// kill -SIGTERM "pid"
				exit(EXIT_SUCCESS);
				
			}


		}			
			
	}else{

		printf("\nRunning directly...");
		printf("\nCommand line will be responsive to kill command ctrl+C.");
		open_log();
		
		// write to pid file
		// write pid of this process
		write_pid();		
		
		initiateWatchAndReadBlock();		
	}

	

	
	

	
}

// method for daemonProcess to operate by:
// writing log file
// communication through its pipes
// responding to signals
// cleaning up after itself
void daemonProcess (int command_fd, int response_fd){
	open_log();
	printf("\nRunning as daemon...");
	initiateWatchAndReadBlock();

	

}


// read map, and close log file
void close_log(){
	
	std::string logFilePath = myMap.find(LOGFILE)->second;
	
	// open the standard out file with new value
	FILE * log_file = fopen( logFilePath.c_str(), "r+");
	if(log_file) {
		printf("\nLog ended.");
		// close files
		fclose(log_file);
	}
	
	

	
}

// read map, and open log file
// only used for the daemon, so this substitutes the log file for standard output with dup2
void open_log(){
	std::string logFilePath = myMap.find(LOGFILE)->second;
	
    struct stat buf;
    int status = stat(logFilePath.c_str(), &buf);
	
	// use file status to determine if the log already exists
	if (status != 0){
		// Log file does not exist yet
		// reopen the standard out file with new value
		FILE * log_file = fopen( logFilePath.c_str(), "w");
		if(log_file) {
			dup2(fileno(log_file), 1);
		}		
	}else if (status == 0){
		
		//Log file exists already
		// reopen the standard out file with new value, in append mode
		FILE * log_file = fopen( logFilePath.c_str(), "a");
		if(log_file) {
			dup2(fileno(log_file), 1);
		}
	}
	
}
void close_pid(){
	const char *pidfile = "cs3377dirmond.pid";
	// remove pid file
	std::remove(pidfile); // delete file

	// write to log that pid file is deleted
	printf("\nPid file deleted.");		
}

/* read_pid
 *
 * Reads the specified pidfile and returns the read pid.
 * 0 is returned if either there's no pidfile, it's empty
 * or no pid can be read.
 */
int read_pid (){
	const char *pidfile = "cs3377dirmond.pid";
	FILE *f;
	int pid;

	if (!(f=fopen(pidfile,"r")))
	return 0;
	fscanf(f,"%d", &pid);
	fclose(f);
	return pid;
}

/* check_pid
 *
 * Reads the pid using read_pid and looks up the pid in the process
 * table (using /proc) to determine if the process already exists. If
 * so 1 is returned, otherwise 0.
 */
int check_pid ()
{
	const char *pidfile = "cs3377dirmond.pid";
	int pid = read_pid();

	/* Amazing ! _I_ am already holding the pid file... */
	if ((!pid) || (pid == getpid ()))
	return 0;

	/*
	* The 'standard' method of doing this is to try and do a 'fake' kill
	* of the process.  If an ESRCH error is returned the process cannot
	* be found -- GW
	*/
	/* But... errno is usually changed only on error.. */
	if (kill(pid, 0) && errno == ESRCH)
	  return(0);

	return pid;
}

/* write_pid
 *
 * Writes the pid to the specified file. If that fails 0 is
 * returned, otherwise the pid.
 */
int write_pid ()
{
	const char *pidfile = "cs3377dirmond.pid";
	int fd;
	char buf[BUF_SIZE];
	
	fd = open(pidfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1){
		printf("\nCould not open PID file.");
		return -1;
	}
	else{
	// write pid to log and to pid file	
	snprintf(buf, BUF_SIZE, "%ld\n", (long) getpid());
	
	// if statement write to pid file
	if (write(fd, buf, strlen(buf)) != strlen(buf))
		// write error to log
        printf("\nError writing to PID file");
	else{
		// write sucess to log
		printf("\nCreated pid file successfully.");
	}

	}
  
    
  // close pid
  close(fd);

  return fd;
}
