// Copyright 2017 Patrick Muldoon
#ifndef INTOUCH_HPP_
#define INTOUCH_HPP_

#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <vector>

const std::string ServerStart =
  "(\\d{4})\\-(\\d{2})\\-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2}): \\(log.c.166\\) server started\\s*";

const std::string StartupSucceeded =
  "(\\d{4})\\-(\\d{2})\\-(\\d{2}) (\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3}).*oejs.AbstractConnector:Started"
  " SelectChannelConnector.*";  

const std::string ServiceStarted = 
  "^Starting Service.\\s\\s(\\w+)\\s(1\\.[0-9]|1\\.[0-9]\\.[0-9]).*";

const std::string SoftloadStart = 
 "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*SOFTLOADSERVICE;Install started.*";

const std::string SoftloadComplete = 
 "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).* ExitValue from install command : 0.*";

const std::string ServiceSucceeded =
 "^Service started successfully.\\s\\s(\\w+)\\s(1\\.[0-9]|1\\.[0-9]\\.[0-9])\\s\\((\\d+)\\s(\\w+)\\).*";

const std::string OriginalVersion = "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*intouch-"
"platform-base-(\\d)\\.(\\d)\\.(\\d)\\-(\\w+\\.\\d{2}|\\d{1,3})\\.armv6jel_vfp.rpm.*rpm to rollback list";

const std::string NewVersion = "^([A-Z?][a-z]{2})\\s(\\d{2})\\s(\\d{2}):(\\d{2}):(\\d{2}).*intouch-platform"
"-base-(\\d)\\.(\\d)\\.(\\d)\\-(\\w+\\.\\d{2}|\\d{1,3}).*armv6jel_vfp.rpm\\s\\.\\.\\.";

const boost::regex StartRegex(ServerStart);
const boost::regex SucceededRegex(StartupSucceeded);
const boost::regex ServiceStart(ServiceStarted);
const boost::regex ServiceSuccess(ServiceSucceeded);
const boost::regex SoftLoadBegin(SoftloadStart);
const boost::regex SoftLoadEnd(SoftloadComplete);
const boost::regex Original(OriginalVersion);
const boost::regex New(NewVersion);

class Services {
public:
	Services(std::string start_line, std::string _filename, unsigned int line_number);
	void ServiceBoot(std::string successful_line, unsigned int line_number);
	friend std::ostream& operator<<(std::ostream &out, const Services &service);
	std::string getServiceName() {return service_name;};
	bool getSuccess() {return success;};
private:
	std::string filename, service_name, boot_time;
	bool success;
	unsigned int start_line_number, end_line_number;
};

class Intouch{
 public:
	Intouch(std::string start_line, std::string _filename, unsigned int line_number);
	void BootSuccess(std::string successful_line, unsigned int line_number);
	friend std::ostream& operator<< (std::ostream &out, const Intouch &it);
	std::vector<Services> a;
	
	bool getSuccess() {return success;};
	unsigned int getStartLine() {return start_line_number;};
	unsigned int getEndLine() {return end_line_number;};
 private:
	unsigned int Time_Elapsed();
	std::string filename, start_time, end_time;
	bool success;
	unsigned int start_line_number, end_line_number, boot_time;
};

class Softload {
public:
	Softload(std::string start_line, std::string _filename, unsigned int line_number);
	void Originalver(std::string successful_line);
	void Newver(std::string successful_line);
	void SoftloadSuccess(std::string successful_line, unsigned int line_number);
	unsigned int getStartLine() {return start_line_number;};
	unsigned int getEndLine() {return end_line_number;};
	std::string getStartTime() {return start_time_soft;};
	std::string getEndTime() {return end_time_soft;};
	std::string getFileName() {return filename;};
	std::string getOriginal() {return oldSoftLoad;};
	std::string getNew() {return newSoftLoad;};
	std::string getBegin() {return begin;};
	std::string getStop() {return stop;};
	bool getSuccess() {return success;};
private:
	unsigned int Time();
	std::string filename, start_time_soft, end_time_soft;
	std::string begin, stop;
	std::string oldSoftLoad, newSoftLoad;
	bool success;
	unsigned int start_line_number, end_line_number, boot_time;
}; 

#endif
