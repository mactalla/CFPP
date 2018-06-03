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
 * @file        CFPP-URL.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFURLRef wrapper
 */

#include <CF++.hpp>

namespace CF
{
    URL URL::FileSystemURL( const std::string & path, bool isDir )
    {
        AutoPointer url;
        String     str;
        
        if( path.length() > 0 )
        {
            str = path;
            
            url = CFURLCreateWithFileSystemPath
            (
                static_cast< CFAllocatorRef >( NULL ),
                str,
                #ifdef _WIN32
                kCFURLWindowsPathStyle,
                #else
                kCFURLPOSIXPathStyle,
                #endif
                isDir
            );
            
            return url.As< CF::URL >();
        }
        
        return static_cast< CFURLRef >( NULL );
    }
    
    URL URL::FileSystemURL( const char * path, bool isDir )
    {
        String str;
        
        str = path;
        
        return URL::FileSystemURL( str.GetValue(), isDir );
    }
    
    URL URL::FileSystemURL( CFTypeRef path, bool isDir )
    {
        String str;
        
        str = path;
        
        return URL::FileSystemURL( str.GetValue(), isDir );
    }
    
    URL URL::FileSystemURL( CFStringRef path, bool isDir )
    {
        String str;
        
        str = path;
        
        return URL::FileSystemURL( str.GetValue(), isDir );
    }
    
    URL::URL( void ): _cfObject( NULL )
    {}
    
    URL::URL( const URL & value ): _cfObject( NULL )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value._cfObject ) );
        }
    }
    
    URL::URL( CFTypeRef value ): _cfObject( NULL )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
    }
    
    URL::URL( const AutoPointer & value ): _cfObject( NULL )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( const_cast< void * >( CFRetain( value ) ) );
        }
    }
    
    URL::URL( CFURLRef value ): _cfObject( NULL )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFURLRef >( CFRetain( value ) );
        }
    }
    
    URL::URL( CFStringRef value ): _cfObject( NULL )
    {
        String s;
        
        s = value;
        
        if( s.GetLength() > 0 )
        {
            this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), static_cast< CFStringRef >( s ), NULL );
        }
    }
    
    URL::URL( const std::string & value ): _cfObject( NULL )
    {
        String s;
        
        s = value;
        
        if( s.GetLength() > 0 )
        {
            this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), static_cast< CFStringRef >( s ), NULL );
        }
    }
    
    URL::URL( const char * value ): _cfObject( NULL )
    {
        String s;
        
        s = value;
        
        if( s.GetLength() > 0 )
        {
            this->_cfObject = CFURLCreateWithString( static_cast< CFAllocatorRef >( NULL ), static_cast< CFStringRef >( s ), NULL );
        }
    }
    
    URL::URL( URL && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    
    URL & URL::operator = ( URL value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    URL & URL::operator = ( const AutoPointer & value )
    {
        return operator =( URL( value ) );
    }
    
    URL & URL::operator = ( CFTypeRef value )
    {
        return operator =( URL( value ) );
    }
    
    URL & URL::operator = ( CFURLRef value )
    {
        return operator =( URL( value ) );
    }
    
    URL & URL::operator = ( CFStringRef value )
    {
        return operator =( URL( value ) );
    }
    
    URL & URL::operator = ( const std::string & value )
    {
        return operator =( URL( value ) );
    }
    
    URL & URL::operator = ( const char * value )
    {
        return operator =( URL( value ) );
    }
    
    std::string URL::operator [] ( Part part ) const
    {
        String s;
        
        switch( part )
        {
            case PartAll:               s = static_cast< std::string >( *( this ) );    break;
            case PartFileSystemPath:    s = this->GetFileSystemPath();                  break;
            case PartFragment:          s = this->GetFragment();                        break;
            case PartHostName:          s = this->GetHostName();                        break;
            case PartLastPathComponent: s = this->GetLastPathComponent();               break;
            case PartNetLocation:       s = this->GetNetLocation();                     break;
            case PartParameterString:   s = this->GetParameterString();                 break;
            case PartPassword:          s = this->GetPassword();                        break;
            case PartPath:              s = this->GetPath();                            break;
            case PartPathExtension:     s = this->GetPathExtension();                   break;
            case PartQueryString:       s = this->GetQueryString();                     break;
            case PartResourceSpecifier: s = this->GetResourceSpecifier();               break;
            case PartScheme:            s = this->GetScheme();                          break;
            case PartStrictPath:        s = this->GetStrictPath();                      break;
            case PartUserName:          s = this->GetUserName();                        break;
        }
        
        return s.GetValue();
    }
    
    bool URL::operator == ( const URL & value ) const
    {
        std::string url1;
        std::string url2;
        
        if( this->_cfObject == NULL || value._cfObject == NULL )
        {
            return false;
        }
        
        url1 = static_cast< std::string >( *( this ) );
        url2 = static_cast< std::string >( const_cast< URL & >( value ) );
        
        return url1 == url2;
    }
    
    bool URL::operator == ( CFTypeRef value ) const
    {
        return operator ==( URL( value ) );
    }
    
    bool URL::operator == ( CFURLRef value ) const
    {
        return operator ==( URL( value ) );
    }
    
    bool URL::operator == ( CFStringRef value ) const
    {
        return operator ==( URL( value ) );
    }
    
    bool URL::operator == ( const std::string & value ) const
    {
        return operator ==( URL( value ) );
    }
    
    bool URL::operator == ( const char * value ) const
    {
        return operator ==( URL( value ) );
    }
    
    bool URL::operator != ( const URL & value ) const
    {
        return !operator ==( value );
    }
    
    bool URL::operator != ( CFTypeRef value ) const
    {
        return !operator ==( value );
    }
    
    bool URL::operator != ( CFURLRef value ) const
    {
        return !operator ==( value );
    }
    
    bool URL::operator != ( CFStringRef value ) const
    {
        return !operator ==( value );
    }
    
    bool URL::operator != ( const std::string & value ) const
    {
        return !operator ==( value );
    }
    
    bool URL::operator != ( const char * value ) const
    {
        return !operator ==( value );
    }
    
    URL & URL::operator /= ( CFStringRef value )
    {
        this->AppendPathComponent( value );
        
        return *( this );
    }
    
    URL & URL::operator /= ( const std::string & value )
    {
        this->AppendPathComponent( value );
        
        return *( this );
    }
    
    URL & URL::operator /= ( const char * value )
    {
        this->AppendPathComponent( value );
        
        return *( this );
    }
    
    URL::operator std::string () const
    {
        String str;
        
        if( this->_cfObject == NULL )
        {
            return str.GetValue();
        }
        
        str = CFURLGetString( this->_cfObject );
        
        return str.GetValue();
    }
    
    CFTypeID URL::GetTypeID( void ) const
    {
        return CFURLGetTypeID();
    }
    
    CFTypeRef URL::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    String URL::GetFileSystemPath( PathStyle style ) const
    {
        AutoPointer    str;
        CFURLPathStyle cfPathStyle;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        cfPathStyle = ( style == PathStyleWindows ) ? kCFURLWindowsPathStyle : kCFURLPOSIXPathStyle;
        str         = CFURLCopyFileSystemPath( this->_cfObject, cfPathStyle );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetFragment( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyFragment( this->_cfObject, NULL );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetHostName( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyHostName( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetLastPathComponent( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyLastPathComponent( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetNetLocation( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyNetLocation( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetParameterString( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyParameterString( this->_cfObject, NULL );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetPassword( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyPassword( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetPath( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyPath( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetPathExtension( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyPathExtension( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetQueryString( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyQueryString( this->_cfObject, NULL );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetResourceSpecifier( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyResourceSpecifier( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetScheme( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyScheme( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetStrictPath( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyStrictPath( this->_cfObject, NULL );
        
        return str.As< CFStringRef >();
    }
    
    String URL::GetUserName( void ) const
    {
        AutoPointer str;
        
        if( this->_cfObject == NULL )
        {
            return str.As< CFStringRef >();
        }
        
        str = CFURLCopyUserName( this->_cfObject );
        
        return str.As< CFStringRef >();
    }
    
    Number URL::GetPortNumber( void ) const
    {
        Number n;
        
        if( this->_cfObject != NULL )
        {
            n.SetSignedIntValue( CFURLGetPortNumber( this->_cfObject ) );
        }
        
        return n;
    }
    
    bool URL::HasDirectoryPath( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return false;
        }
        
        return ( CFURLHasDirectoryPath( this->_cfObject ) ) ? true : false;
    }
    
    void URL::AppendPathComponent( CFStringRef component, bool isDirectory )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyAppendingPathComponent
        (
            static_cast< CFAllocatorRef >( NULL ),
            url,
            component,
            isDirectory
        );
        
        CFRelease( url );
    }
    
    void URL::AppendPathComponent( const std::string & component, bool isDirectory )
    {
        String s;
        
        s = component;
        
        this->AppendPathComponent( static_cast< CFStringRef >( s ), isDirectory );
    }
    
    void URL::AppendPathComponent( const char * component, bool isDirectory )
    {
        String s;
        
        s = component;
        
        this->AppendPathComponent( static_cast< CFStringRef >( s ), isDirectory );
    }
    
    void URL::AppendPathExtension( CFStringRef extension )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyAppendingPathExtension
        (
            static_cast< CFAllocatorRef >( NULL ),
            url,
            extension
        );
        
        CFRelease( url );
    }
    
    void URL::AppendPathExtension( const std::string & extension )
    {
        String s;
        
        s = extension;
        
        this->AppendPathExtension( static_cast< CFStringRef >( s ) );
    }
    
    void URL::AppendPathExtension( const char * extension )
    {
        String s;
        
        s = extension;
        
        this->AppendPathExtension( static_cast< CFStringRef >( s ) );
    }
    
    void URL::DeleteLastPathComponent( void )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyDeletingLastPathComponent
        (
            static_cast< CFAllocatorRef >( NULL ),
            url
        );
        
        CFRelease( url );
    }
    
    void URL::DeletePathExtension( void )
    {
        CFURLRef url;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        url             = this->_cfObject;
        this->_cfObject = CFURLCreateCopyDeletingPathExtension
        (
            static_cast< CFAllocatorRef >( NULL ),
            url
        );
        
        CFRelease( url );
    }
    
    void swap( URL & v1, URL & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
