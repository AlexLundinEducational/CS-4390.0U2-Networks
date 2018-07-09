//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program5.h"

using namespace rude;
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

const char * file_path = "/home/013/a/am/aml140830/testdir";

 
void initiateWatchAndReadBlock() 
{
  int length, i;
  int fd;
  int wd;
  char buffer[BUF_LEN];

  fd = inotify_init();

  if ( fd < 0 ) {
    perror( "inotify_init" );
  }

  wd = inotify_add_watch(fd,
			 file_path,
			 IN_ALL_EVENTS);

  while(1)
  {
	  length = read( fd, buffer, BUF_LEN );

	  if ( length < 0 ) {
		  perror( "read" );
	  }
          i = 0;
	  while ( i < length ) {
		  struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];

		  if ( event->len ) {
			  if ( event->mask & IN_CREATE ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was created.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was created.\n", event->name );
				  }
			  }
			  else if ( event->mask & IN_DELETE ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was deleted.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was deleted.\n", event->name );
				  }
			  }
			  else if ( event->mask & IN_MODIFY ) {
				  if ( event->mask & IN_ISDIR ) {
					  printf( "\nThe directory %s was modified.\n", event->name );
				  }
				  else {
					  printf( "\nThe file %s was modified.\n", event->name );
				  }
			  }
		  }
		  i += EVENT_SIZE + event->len;
	  }
  }

  ( void ) inotify_rm_watch( fd, wd );
  ( void ) close( fd );
 
}