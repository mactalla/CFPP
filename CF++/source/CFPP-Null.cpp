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
 * @file        CFPP-Null.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFNullRef wrapper
 */

#include <CF++.hpp>

#ifdef _WIN32

#include <Windows.h>

static bool      __hasCFNull = false;
static CFNullRef __cfNull    = NULL;

static void __loadCFNull( void )
{
    HMODULE cfModule;

    if( __hasCFNull == true )
    {
        return;
    }

    cfModule = GetModuleHandle( L"CoreFoundation.dll" );

    if( cfModule != NULL )
    {
        __hasCFNull = true;
        __cfNull    = *( ( CFNullRef * )GetProcAddress( cfModule, "kCFNull" ) );
    }
}

#endif

namespace CF
{
    Null::Null( void ): _cfObject( NULL )
    {
        #ifdef _WIN32
        
        __loadCFNull();
        
        this->_cfObject = __cfNull;
        
        #else
        
        this->_cfObject = kCFNull;
        
        #endif
    }
    
    Null::Null( const Null & value ): _cfObject( value._cfObject )
    {}
    
    Null::Null( CFTypeRef value ): _cfObject( NULL )
    {
        if( value != NULL && CFGetTypeID( value ) == this->GetTypeID() )
        {
            _cfObject = static_cast< CFNullRef >( value );
        }
    }
    
    Null::Null( Null && value ) noexcept
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    
    Null::~Null( void )
    {}
    
    Null & Null::operator = ( Null value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    Null & Null::operator = ( CFTypeRef value )
    {
        return operator =( Null( value ) );
    }
    
    CFTypeID Null::GetTypeID( void ) const
    {
        return CFNullGetTypeID();
    }
    
    CFTypeRef Null::GetCFObject( void ) const
    {
        return this->_cfObject;
    }
    
    void swap( Null & v1, Null & v2 ) noexcept
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
