/**********************************************************************
 *  readme.txt template                                                   
 *  PS7b: Kronos log parsing
 **********************************************************************/

Name: Patrick Muldoon


Hours to complete assignment (optional):12 hours
/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I mostly completed the assignment, I am missing the elapsed time and did not print out every service when the device did not boot. 


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

  "(\\d{4})\\-(\\d{2})\\-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2}): \\(log.c.166\\) server started\\s*";
This one finds where a server starts

  "(\\d{4})\\-(\\d{2})\\-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3}).*oejs.AbstractConnector:Started SelectChannelConnector.*";  
This one determines when the boot up has completed

  "^Starting Service.\\s\\s(\\w+)\\s(1\\.[0-9]|1\\.[0-9]\\.[0-9]).*";
This one locates the start of a service

 "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*SOFTLOADSERVICE;Install started.*";
This one finds the start of a softload install

 "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).* ExitValue from install command : 0.*";
This one finds when a soft load has completed

 "^Service started successfully.\\s\\s(\\w+)\\s(1\\.[0-9]|1\\.[0-9]\\.[0-9])\\s\\((\\d+)\\s(\\w+)\\).*";
This one determines when a service has completed itself

"^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*intouch-platform-base-(\\d)\\.(\\d)\\.(\\d)\\-(\\w+\\.\\d{2}|\\d{1,3})\\.armv6jel_vfp.rpm.*rpm to rollback list"
This one finds the original version of the soft load that was already on the platform

"^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*intouch-platform-base-(\\d)\\.(\\d)\\.(\\d)\\-(\\w+\\.\\d{2}|\\d{1,3}).*armv6jel_vfp.rpm\\s\\.\\.\\.";
This one finds the new version of the soft load that has now been installed on the platform

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

My approach was the create three classes, one for the boot ups, one for the services, and one for the softwoods. The Bootups hold it’s own vector of services to be placed in after reading through the log. The program reads through the log, finds a boot up and then tries to read through all the services. If another boot up is found before a service is started, the previous boot is deemed imcomplete. This means no services were started or updated. After a bootup has completed the program will run through line by line till it hits a softload update or another bootup. The process then repeats itself till the end of the file.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

Many problems, says it still won’t compile but it compiles on my computer and I have the logs to prove it. This happened with my previous two assignments and I literally do not know why bottlenose does not like my files. I also could not solve the elapsed time or the services. If a bootup does not complete my program just says no services were updated. I could have created an individual class for every single service, but that would have been tedious and I am tight on time. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Please help me with this non compiling, I need to pass this class to graduate and I have done the work and gotten the desired outputs and I still do not know why it will not compile on bottlenose. 
/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7b complete
 **********************************************************************/

Name:
CS Login:


Hours to complete assignment (optional):


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/



/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/



/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/