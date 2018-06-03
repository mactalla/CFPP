/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-WriteStream.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFWriteStreamRef wrapper
 */

#ifndef CFPP_WRITE_STREAM_H
#define CFPP_WRITE_STREAM_H

namespace CF
{
    class CFPP_EXPORT WriteStream: public Type
    {
        public:
            
            WriteStream( void );
            WriteStream( const std::string & path );
            WriteStream( const char * path );
            WriteStream( URL url );
            WriteStream( const WriteStream & value );
            WriteStream( const AutoPointer & value );
            WriteStream( CFTypeRef value );
            WriteStream( CFWriteStreamRef value );
            WriteStream( WriteStream && value );
            
            virtual ~WriteStream( void );
            
            WriteStream & operator = ( WriteStream value );
            WriteStream & operator = ( const AutoPointer & value );
            WriteStream & operator = ( CFTypeRef value );
            WriteStream & operator = ( CFWriteStreamRef value );
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool               Open( void ) const;
            bool               Open( const std::string & path );
            bool               Open( const char * path );
            bool               Open( const URL & url );
            void               Close( void ) const;
            bool               CanAcceptBytes( void ) const;
            CFStreamStatus     GetStatus( void ) const;
            Error              GetError( void ) const;
            CFIndex            Write( const Data::Byte * buffer, CFIndex length ) const;
            CFIndex            Write( const Data & data ) const;
            bool               WriteAll( const Data::Byte * buffer, CFIndex length ) const;
            bool               WriteAll( const Data & data ) const;
            AutoPointer        GetProperty( const String & name );
            bool               SetProperty( const String & name, CFTypeRef value );
            bool               SetClient( CFOptionFlags events, CFWriteStreamClientCallBack callback, CFStreamClientContext * context );
            void               ScheduleWithRunLoop( CFRunLoopRef runLoop, CF::String mode );
            void               UnscheduleFromRunLoop( CFRunLoopRef runLoop, CF::String mode );
            
            friend void swap( WriteStream & v1, WriteStream & v2 );
            
        private:
            
            CFWriteStreamRef _cfObject;
    };
}

#endif /* CFPP_WRITE_STREAM_H */
