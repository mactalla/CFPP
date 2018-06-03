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
 * @file        CFPP-String-Iterator.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Iterator class for CF::String
 */

#include <CF++.hpp>

namespace CF
{
    String::Iterator::Iterator( void ):
        _cfObject( NULL ),
        _length( 0 ),
        _pos( 0 ),
        _cp( NULL )
    {}
    
    String::Iterator::Iterator( const Iterator & value ):
        _cfObject( value._cfObject ),
        _length( value._length ),
        _pos( value._pos ),
        _cp( value._cp )
    {
        if( this->_cfObject != NULL )
        {
            CFRetain( this->_cfObject );
        }
    }
    
    String::Iterator::Iterator( CFStringRef string, CFStringEncoding encoding, CFIndex length, CFIndex pos ):
        _cfObject( string ),
        _length( length ),
        _pos( pos ),
        _cp( NULL )
    {
        if( this->_cfObject != NULL )
        {
            CFRetain( this->_cfObject );
            
            {
                std::size_t size;
                
                size = static_cast< std::size_t >( CFStringGetMaximumSizeForEncoding( CFStringGetLength( this->_cfObject ), encoding ) );
                
                this->_cp = std::shared_ptr< char >( new char[ size + 1 ] );
                
                if( this->_cp != nullptr )
                {
                    memset( this->_cp.get(), 0, size + 1 );
                    CFStringGetCString( this->_cfObject, this->_cp.get(), static_cast< CFIndex >( length + 1 ), encoding );
                }
            }
        }
    }
    
    String::Iterator::Iterator( Iterator && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
        this->_length   = value._length;
        value._length   = 0;
        this->_pos      = value._pos;
        value._pos      = 0;
        this->_cp       = value._cp;
        value._cp       = nullptr;
    }
    
    String::Iterator::~Iterator( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
    }
    
    String::Iterator & String::Iterator::operator = ( Iterator value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    String::Iterator & String::Iterator::operator ++( void )
    {
        this->_pos++;
        
        return *( this );
    }
    
    String::Iterator String::Iterator::operator ++( int )
    {
        Iterator it( *( this ) );
        
        operator++();
        
        return it;
    }
    
    String::Iterator & String::Iterator::operator --( void )
    {
        this->_pos--;
        
        return *( this );
    }
    
    String::Iterator String::Iterator::operator --( int )
    {
        Iterator it( *( this ) );
        
        operator--();
        
        return it;
    }
    
    String::Iterator & String::Iterator::operator += ( CFIndex value )
    {
        this->_pos += value;
        
        return *( this );
    }
    
    String::Iterator & String::Iterator::operator -= ( CFIndex value )
    {
        this->_pos -= value;
        
        return *( this );
    }
    
    String::Iterator String::Iterator::operator + ( CFIndex value )
    {
        Iterator i;
        
        i = *( this );
        
        return i += value;
    }
    
    String::Iterator String::Iterator::operator - ( CFIndex value )
    {
        Iterator i;
        
        i = *( this );
        
        return i -= value;
    }
    
    bool String::Iterator::operator == ( const Iterator & value ) const
    {
        if( this->_cfObject != value._cfObject )
        {
            return false;
        }
        
        if( this->_length != value._length )
        {
            return false;
        }
        
        if( this->_pos != value._pos )
        {
            return false;
        }
        
        return true;
    }
    
    bool String::Iterator::operator != ( const Iterator & value ) const
    {
        return !( *( this ) == value );
    }
    
    char String::Iterator::operator * ( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return 0;
        }
        
        if( this->_cp == NULL )
        {
            return 0;
        }
        
        if( this->_pos < 0 )
        {
            return 0;
        }
        
        if( this->_pos >= this->_length )
        {
            return 0;
        }
        
        return this->_cp.get()[ this->_pos ];
    }
    
    String::Iterator::operator char () const
    {
        return operator*();
    }
    
    void swap( String::Iterator & v1, String::Iterator & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
        swap( v1._length,   v2._length );
        swap( v1._pos,      v2._pos );
        swap( v1._cp,       v2._cp );
    }
}
