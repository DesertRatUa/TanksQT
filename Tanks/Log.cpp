/*
 * Log.cpp
 *
 *      Author: maximm
 */

#include "Log.h"
#include <stdexcept>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <QDebug>

std::string Log::m_logFile("");
std::mutex Log::m_messageMut;
std::mutex Log::m_logMut;
std::ofstream Log::m_log;
std::string Log::m_name;
bool Log::m_enable(false);

Log::~Log()
{
    Log::Close();
}

void Log::Init( std::string path ) throw ( std::exception )
{
	m_logFile = path.substr( 0, path.find_last_of( "\\" ) ) + "\\" + "Log.log";
    if ( !path.empty() )
    {
        m_log.open( m_logFile.c_str(), std::ios::app|std::ios::out );
        if ( m_log.fail() )
        {
            m_logFile = "";
            m_log.close();
            throw std::runtime_error( std::string("Fail open log: ") + m_logFile.c_str() );
        }
    }
    m_enable = true;
}

void Log::Close()
{
	m_log.close();
    m_enable = false;
}
void Log::Message( const std::string message )
{
    if (m_enable)
    {
        std::lock_guard<std::mutex> lock( m_messageMut );
        qDebug( "%s\t%s", PrintTime().c_str(), message.c_str() );
    }
}

void Log::LogToFile( const std::string log )
{
	if ( !m_log.is_open() ) return;
	std::lock_guard<std::mutex> lock( m_logMut );
	m_log << PrintTime() << "\t";
	if ( !m_name.empty() )
	{
		m_log << m_name.c_str() << ": ";
	}
	m_log << log << std::endl;
}

void Log::Add( const std::string log )
{
    Message( log );
    LogToFile( log );
}

void Log::Exception( const std::string name, const std::exception &exc )
{
    Add( name + " exception: " + exc.what() );
}

void Log::Warning( std::string log )
{
    if (m_enable)
    {
        std::lock_guard<std::mutex> lock( m_messageMut );
        log = "Warnning: " + log;
        LogToFile( log );

        qWarning( "%s\t%s", PrintTime().c_str(), log.c_str() );
     }
}

void Log::Error( std::string log )
{
    if (m_enable)
    {
        std::lock_guard<std::mutex> lock( m_messageMut );
        log = "Error: " + log;
        LogToFile( log );

        qCritical( "%s\t%s", PrintTime().c_str(), log.c_str() );
     }
}

std::string Log::PrintTime()
{
	time_t now = time(NULL);
	char buf[80];
	struct tm *tstruct;
	tstruct = localtime(&now);
	strftime(buf, sizeof(buf), "%X", tstruct);
	return buf;
}

std::string Log::IntToStr( const int value )
{
    char buff[100];
    sprintf(buff, "%d", value);
    return std::string(buff);
}

std::string Log::IntToStr( const unsigned value )
{
    char buff[100];
    sprintf(buff, "%u", value);
    return std::string(buff);
}

std::string Log::IntToStr( const unsigned long value )
{
    char buff[100];
    sprintf(buff, "%lu", value);
    return std::string(buff);
}

std::string Log::IntToStr( const size_t &value )
{
    char buff[100];
    sprintf(buff, "%u", value);
    return std::string(buff);
}

void Log::SetName( const std::string &name )
{
	m_name = name;
}

std::string Log::BoolToStr( const bool value )
{
	switch (value)
	{
	case true:
		return "true";
	case false:
		return "false";
	}
}

void Log::StrToBool( std::string value, bool &result )
{
	std::transform(value.begin(), value.end(), value.begin(), ::tolower);
	if ( value == "true" )
	{
		result = true;
	}
	else if ( value == "false" )
	{
		result = false;
	}
}
