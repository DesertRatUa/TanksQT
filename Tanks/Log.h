/*
 * Log.h
 *
 *      Author: maximm
 */

#ifndef LOG_H_
#define LOG_H_

#include <fstream>
#include <mutex>

class Log
{
public:
    virtual ~Log();

    static void Init( std::string path ) throw ( std::exception );
	static void Close();
	static void SetName( const std::string &name );

    static void Message( const std::string message );
    static void LogToFile( const std::string log );
    static void Add( const std::string log );
    static void Exception( const std::string name, const std::exception &exc );
    static void Warning( std::string log );
    static void Error( std::string log );

	static std::string IntToStr( const int value );
	static std::string IntToStr( const unsigned value );
	static std::string IntToStr( const size_t &value );
	static std::string IntToStr( const unsigned long value );
    static std::string FloatToStr( const float value );
	static std::string BoolToStr( const bool value );
	static void StrToBool( std::string value, bool &result );

protected:
	static std::string PrintTime();

	static std::string m_logFile;
	static std::mutex m_messageMut;
	static std::mutex m_logMut;

	static std::ofstream m_log;
	static std::string m_name;
    static bool m_enable;
};

#endif /* LOG_H_ */
