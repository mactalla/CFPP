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
 * @header      CFPP-Number.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFNumberRef wrapper
 */

#ifndef CFPP_NUMBER_H
#define CFPP_NUMBER_H

#include <stdint.h>

namespace CF
{
    class CFPP_EXPORT Number: public PropertyListType< Number >
    {
        public:
            
            #ifdef _WIN32
        
            typedef          __int32 SInt32;
            typedef unsigned __int32 UInt32;
            typedef          __int64 SInt64;
            typedef unsigned __int64 UInt64;
            
            #else
        
            typedef int32_t  SInt32;
            typedef uint32_t UInt32;
            typedef int64_t  SInt64;
            typedef uint64_t UInt64;
            
            #endif
            
            Number( void );
            Number( const AutoPointer & value );
            Number( CFTypeRef cfObject );
            Number( CFNumberRef cfObject );
            Number( const AutoPointer & value, signed char defaultValueIfNULL );
            Number( const AutoPointer & value, signed short defaultValueIfNULL );
            Number( const AutoPointer & value, SInt32 defaultValueIfNULL );
            Number( const AutoPointer & value, SInt64 defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned char defaultValueIfNULL );
            Number( const AutoPointer & value, unsigned short defaultValueIfNULL );
            Number( const AutoPointer & value, UInt32 defaultValueIfNULL );
            Number( const AutoPointer & value, UInt64 defaultValueIfNULL );
            Number( const AutoPointer & value, float defaultValueIfNULL );
            Number( const AutoPointer & value, double defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed char defaultValueIfNULL );
            Number( CFTypeRef cfObject, signed short defaultValueIfNULL );
            Number( CFTypeRef cfObject, SInt32 defaultValueIfNULL );
            Number( CFTypeRef cfObject, SInt64 defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned char defaultValueIfNULL );
            Number( CFTypeRef cfObject, unsigned short defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt32 defaultValueIfNULL );
            Number( CFTypeRef cfObject, UInt64 defaultValueIfNULL );
            Number( CFTypeRef cfObject, float defaultValueIfNULL );
            Number( CFTypeRef cfObject, double defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed char defaultValueIfNULL );
            Number( CFNumberRef cfObject, signed short defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt32 defaultValueIfNULL );
            Number( CFNumberRef cfObject, SInt64 defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned char defaultValueIfNULL );
            Number( CFNumberRef cfObject, unsigned short defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt32 defaultValueIfNULL );
            Number( CFNumberRef cfObject, UInt64 defaultValueIfNULL );
            Number( CFNumberRef cfObject, float defaultValueIfNULL );
            Number( CFNumberRef cfObject, double defaultValueIfNULL );
            Number( const Number & value );
            Number( signed char value );
            Number( signed short value );
            Number( SInt32 value );
            Number( SInt64 value );
            Number( unsigned char value );
            Number( unsigned short value );
            Number( UInt32 value );
            Number( UInt64 value );
            Number( float value );
            Number( double value );
            
            #ifdef CFPP_HAS_CPP11
            Number( Number && value );
            #endif
            
            virtual ~Number( void );
            
            Number & operator = ( Number value );
            Number & operator = ( const AutoPointer & value );
            Number & operator = ( CFTypeRef value );
            Number & operator = ( CFNumberRef value );
            Number & operator = ( signed char value );
            Number & operator = ( signed short value );
            Number & operator = ( SInt32 value );
            Number & operator = ( SInt64 value );
            Number & operator = ( unsigned char value );
            Number & operator = ( unsigned short value );
            Number & operator = ( UInt32 value );
            Number & operator = ( UInt64 value );
            Number & operator = ( float value );
            Number & operator = ( double value );
            
            bool operator == ( const Number & value ) const;
            bool operator == ( CFTypeRef value ) const;
            bool operator == ( CFNumberRef value ) const;
            bool operator == ( signed char value ) const;
            bool operator == ( signed short value ) const;
            bool operator == ( SInt32 value ) const;
            bool operator == ( SInt64 value ) const;
            bool operator == ( unsigned char value ) const;
            bool operator == ( unsigned short value ) const;
            bool operator == ( UInt32 value ) const;
            bool operator == ( UInt64 value ) const;
            bool operator == ( float value ) const;
            bool operator == ( double value ) const;
            
            bool operator != ( const Number & value ) const;
            bool operator != ( CFTypeRef value ) const;
            bool operator != ( CFNumberRef value ) const;
            bool operator != ( signed char value ) const;
            bool operator != ( signed short value ) const;
            bool operator != ( SInt32 value ) const;
            bool operator != ( SInt64 value ) const;
            bool operator != ( unsigned char value ) const;
            bool operator != ( unsigned short value ) const;
            bool operator != ( UInt32 value ) const;
            bool operator != ( UInt64 value ) const;
            bool operator != ( float value ) const;
            bool operator != ( double value ) const;
            
            bool operator >= ( const Number & value ) const;
            bool operator >= ( CFTypeRef value ) const;
            bool operator >= ( CFNumberRef value ) const;
            bool operator >= ( signed char value ) const;
            bool operator >= ( signed short value ) const;
            bool operator >= ( SInt32 value ) const;
            bool operator >= ( SInt64 value ) const;
            bool operator >= ( unsigned char value ) const;
            bool operator >= ( unsigned short value ) const;
            bool operator >= ( UInt32 value ) const;
            bool operator >= ( UInt64 value ) const;
            bool operator >= ( float value ) const;
            bool operator >= ( double value ) const;
            
            bool operator <= ( const Number & value ) const;
            bool operator <= ( CFTypeRef value ) const;
            bool operator <= ( CFNumberRef value ) const;
            bool operator <= ( signed char value ) const;
            bool operator <= ( signed short value ) const;
            bool operator <= ( SInt32 value ) const;
            bool operator <= ( SInt64 value ) const;
            bool operator <= ( unsigned char value ) const;
            bool operator <= ( unsigned short value ) const;
            bool operator <= ( UInt32 value ) const;
            bool operator <= ( UInt64 value ) const;
            bool operator <= ( float value ) const;
            bool operator <= ( double value ) const;
            
            bool operator > ( const Number & value ) const;
            bool operator > ( CFTypeRef value ) const;
            bool operator > ( CFNumberRef value ) const;
            bool operator > ( signed char value ) const;
            bool operator > ( signed short value ) const;
            bool operator > ( SInt32 value ) const;
            bool operator > ( SInt64 value ) const;
            bool operator > ( unsigned char value ) const;
            bool operator > ( unsigned short value ) const;
            bool operator > ( UInt32 value ) const;
            bool operator > ( UInt64 value ) const;
            bool operator > ( float value ) const;
            bool operator > ( double value ) const;
            
            bool operator < ( const Number & value ) const;
            bool operator < ( CFTypeRef value ) const;
            bool operator < ( CFNumberRef value ) const;
            bool operator < ( signed char value ) const;
            bool operator < ( signed short value ) const;
            bool operator < ( SInt32 value ) const;
            bool operator < ( SInt64 value ) const;
            bool operator < ( unsigned char value ) const;
            bool operator < ( unsigned short value ) const;
            bool operator < ( UInt32 value ) const;
            bool operator < ( UInt64 value ) const;
            bool operator < ( float value ) const;
            bool operator < ( double value ) const;
            
            bool operator && ( const Number & value ) const;
            bool operator && ( CFTypeRef value ) const;
            bool operator && ( CFNumberRef value ) const;
            bool operator && ( signed char value ) const;
            bool operator && ( signed short value ) const;
            bool operator && ( SInt32 value ) const;
            bool operator && ( SInt64 value ) const;
            bool operator && ( unsigned char value ) const;
            bool operator && ( unsigned short value ) const;
            bool operator && ( UInt32 value ) const;
            bool operator && ( UInt64 value ) const;
            bool operator && ( float value ) const;
            bool operator && ( double value ) const;
            
            bool operator || ( const Number & value ) const;
            bool operator || ( CFTypeRef value ) const;
            bool operator || ( CFNumberRef value ) const;
            bool operator || ( signed char value ) const;
            bool operator || ( signed short value ) const;
            bool operator || ( SInt32 value ) const;
            bool operator || ( SInt64 value ) const;
            bool operator || ( unsigned char value ) const;
            bool operator || ( unsigned short value ) const;
            bool operator || ( UInt32 value ) const;
            bool operator || ( UInt64 value ) const;
            bool operator || ( float value ) const;
            bool operator || ( double value ) const;
            
            Number & operator ~ ( void );
            Number & operator ! ( void );
            Number & operator ++ ( void );
            Number   operator ++ ( int );
            Number & operator -- ( void );
            Number   operator -- ( int );
            
            Number & operator += ( const Number & value );
            Number & operator += ( CFNumberRef value );
            Number & operator += ( signed char value );
            Number & operator += ( signed short value );
            Number & operator += ( SInt32 value );
            Number & operator += ( SInt64 value );
            Number & operator += ( unsigned char value );
            Number & operator += ( unsigned short value );
            Number & operator += ( UInt32 value );
            Number & operator += ( UInt64 value );
            Number & operator += ( float value );
            Number & operator += ( double value );
            
            Number & operator -= ( const Number & value );
            Number & operator -= ( CFNumberRef value );
            Number & operator -= ( signed char value );
            Number & operator -= ( signed short value );
            Number & operator -= ( SInt32 value );
            Number & operator -= ( SInt64 value );
            Number & operator -= ( unsigned char value );
            Number & operator -= ( unsigned short value );
            Number & operator -= ( UInt32 value );
            Number & operator -= ( UInt64 value );
            Number & operator -= ( float value );
            Number & operator -= ( double value );
            
            Number & operator *= ( const Number & value );
            Number & operator *= ( CFNumberRef value );
            Number & operator *= ( signed char value );
            Number & operator *= ( signed short value );
            Number & operator *= ( SInt32 value );
            Number & operator *= ( SInt64 value );
            Number & operator *= ( unsigned char value );
            Number & operator *= ( unsigned short value );
            Number & operator *= ( UInt32 value );
            Number & operator *= ( UInt64 value );
            Number & operator *= ( float value );
            Number & operator *= ( double value );
            
            Number & operator /= ( const Number & value );
            Number & operator /= ( CFNumberRef value );
            Number & operator /= ( signed char value );
            Number & operator /= ( signed short value );
            Number & operator /= ( SInt32 value );
            Number & operator /= ( SInt64 value );
            Number & operator /= ( unsigned char value );
            Number & operator /= ( unsigned short value );
            Number & operator /= ( UInt32 value );
            Number & operator /= ( UInt64 value );
            Number & operator /= ( float value );
            Number & operator /= ( double value );
            
            Number & operator |= ( const Number & value );
            Number & operator |= ( CFNumberRef value );
            Number & operator |= ( signed char value );
            Number & operator |= ( signed short value );
            Number & operator |= ( SInt32 value );
            Number & operator |= ( SInt64 value );
            Number & operator |= ( unsigned char value );
            Number & operator |= ( unsigned short value );
            Number & operator |= ( UInt32 value );
            Number & operator |= ( UInt64 value );
            
            Number & operator &= ( const Number & value );
            Number & operator &= ( CFNumberRef value );
            Number & operator &= ( signed char value );
            Number & operator &= ( signed short value );
            Number & operator &= ( SInt32 value );
            Number & operator &= ( SInt64 value );
            Number & operator &= ( unsigned char value );
            Number & operator &= ( unsigned short value );
            Number & operator &= ( UInt32 value );
            Number & operator &= ( UInt64 value );
            
            Number & operator %= ( const Number & value );
            Number & operator %= ( CFNumberRef value );
            Number & operator %= ( signed char value );
            Number & operator %= ( signed short value );
            Number & operator %= ( SInt32 value );
            Number & operator %= ( SInt64 value );
            Number & operator %= ( unsigned char value );
            Number & operator %= ( unsigned short value );
            Number & operator %= ( UInt32 value );
            Number & operator %= ( UInt64 value );
            
            Number & operator ^= ( const Number & value );
            Number & operator ^= ( CFNumberRef value );
            Number & operator ^= ( signed char value );
            Number & operator ^= ( signed short value );
            Number & operator ^= ( SInt32 value );
            Number & operator ^= ( SInt64 value );
            Number & operator ^= ( unsigned char value );
            Number & operator ^= ( unsigned short value );
            Number & operator ^= ( UInt32 value );
            Number & operator ^= ( UInt64 value );
            
            Number & operator <<= ( const Number & value );
            Number & operator <<= ( CFNumberRef value );
            Number & operator <<= ( signed char value );
            Number & operator <<= ( signed short value );
            Number & operator <<= ( SInt32 value );
            Number & operator <<= ( SInt64 value );
            Number & operator <<= ( unsigned char value );
            Number & operator <<= ( unsigned short value );
            Number & operator <<= ( UInt32 value );
            Number & operator <<= ( UInt64 value );
            
            Number & operator >>= ( const Number & value );
            Number & operator >>= ( CFNumberRef value );
            Number & operator >>= ( signed char value );
            Number & operator >>= ( signed short value );
            Number & operator >>= ( SInt32 value );
            Number & operator >>= ( SInt64 value );
            Number & operator >>= ( unsigned char value );
            Number & operator >>= ( unsigned short value );
            Number & operator >>= ( UInt32 value );
            Number & operator >>= ( UInt64 value );
            
            Number operator + ( const Number & value );
            Number operator + ( CFNumberRef value );
            Number operator + ( signed char value );
            Number operator + ( signed short value );
            Number operator + ( SInt32 value );
            Number operator + ( SInt64 value );
            Number operator + ( unsigned char value );
            Number operator + ( unsigned short value );
            Number operator + ( UInt32 value );
            Number operator + ( UInt64 value );
            Number operator + ( float value );
            Number operator + ( double value );
            
            Number operator - ( const Number & value );
            Number operator - ( CFNumberRef value );
            Number operator - ( signed char value );
            Number operator - ( signed short value );
            Number operator - ( SInt32 value );
            Number operator - ( SInt64 value );
            Number operator - ( unsigned char value );
            Number operator - ( unsigned short value );
            Number operator - ( UInt32 value );
            Number operator - ( UInt64 value );
            Number operator - ( float value );
            Number operator - ( double value );
            
            Number operator * ( const Number & value );
            Number operator * ( CFNumberRef value );
            Number operator * ( signed char value );
            Number operator * ( signed short value );
            Number operator * ( SInt32 value );
            Number operator * ( SInt64 value );
            Number operator * ( unsigned char value );
            Number operator * ( unsigned short value );
            Number operator * ( UInt32 value );
            Number operator * ( UInt64 value );
            Number operator * ( float value );
            Number operator * ( double value );
            
            Number operator / ( const Number & value );
            Number operator / ( CFNumberRef value );
            Number operator / ( signed char value );
            Number operator / ( signed short value );
            Number operator / ( SInt32 value );
            Number operator / ( SInt64 value );
            Number operator / ( unsigned char value );
            Number operator / ( unsigned short value );
            Number operator / ( UInt32 value );
            Number operator / ( UInt64 value );
            Number operator / ( float value );
            Number operator / ( double value );
            
            Number operator % ( const Number & value );
            Number operator % ( CFNumberRef value );
            Number operator % ( signed char value );
            Number operator % ( signed short value );
            Number operator % ( SInt32 value );
            Number operator % ( SInt64 value );
            Number operator % ( unsigned char value );
            Number operator % ( unsigned short value );
            Number operator % ( UInt32 value );
            Number operator % ( UInt64 value );
            
            Number operator & ( const Number & value );
            Number operator & ( CFNumberRef value );
            Number operator & ( signed char value );
            Number operator & ( signed short value );
            Number operator & ( SInt32 value );
            Number operator & ( SInt64 value );
            Number operator & ( unsigned char value );
            Number operator & ( unsigned short value );
            Number operator & ( UInt32 value );
            Number operator & ( UInt64 value );
            
            Number operator | ( const Number & value );
            Number operator | ( CFNumberRef value );
            Number operator | ( signed char value );
            Number operator | ( signed short value );
            Number operator | ( SInt32 value );
            Number operator | ( SInt64 value );
            Number operator | ( unsigned char value );
            Number operator | ( unsigned short value );
            Number operator | ( UInt32 value );
            Number operator | ( UInt64 value );
            
            Number operator ^ ( const Number & value );
            Number operator ^ ( CFNumberRef value );
            Number operator ^ ( signed char value );
            Number operator ^ ( signed short value );
            Number operator ^ ( SInt32 value );
            Number operator ^ ( SInt64 value );
            Number operator ^ ( unsigned char value );
            Number operator ^ ( unsigned short value );
            Number operator ^ ( UInt32 value );
            Number operator ^ ( UInt64 value );
            
            Number operator << ( const Number & value );
            Number operator << ( CFNumberRef value );
            Number operator << ( signed char value );
            Number operator << ( signed short value );
            Number operator << ( SInt32 value );
            Number operator << ( SInt64 value );
            Number operator << ( unsigned char value );
            Number operator << ( unsigned short value );
            Number operator << ( UInt32 value );
            Number operator << ( UInt64 value );
            
            Number operator >> ( const Number & value );
            Number operator >> ( CFNumberRef value );
            Number operator >> ( signed char value );
            Number operator >> ( signed short value );
            Number operator >> ( SInt32 value );
            Number operator >> ( SInt64 value );
            Number operator >> ( unsigned char value );
            Number operator >> ( unsigned short value );
            Number operator >> ( UInt32 value );
            Number operator >> ( UInt64 value );
            
            operator signed char   () const;
            operator signed short  () const;
            operator SInt32  () const;
            operator SInt64  () const;
            operator unsigned char   () const;
            operator unsigned short  () const;
            operator UInt32  () const;
            operator UInt64  () const;
            operator float () const;
            operator double () const;
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool IsFloatType( void ) const;
            
            signed char   GetSignedCharValue( void ) const;
            signed short  GetSignedShortValue( void ) const;
            SInt32  GetSInt32Value( void ) const;
            SInt64  GetSInt64Value( void ) const;
            unsigned char   GetUnsignedCharValue( void ) const;
            unsigned short  GetUnsignedShortValue( void ) const;
            UInt32  GetUInt32Value( void ) const;
            UInt64  GetUInt64Value( void ) const;
            float GetFloatValue( void ) const;
            double GetDoubleValue( void ) const;
            void    SetSignedCharValue( signed char value );
            void    SetSignedShortValue( signed short value );
            void    SetSInt32Value( SInt32 value );
            void    SetSInt64Value( SInt64 value );
            void    SetUnsignedCharValue( unsigned char value );
            void    SetUnsignedShortValue( unsigned short value );
            void    SetUInt32Value( UInt32 value );
            void    SetUInt64Value( UInt64 value );
            void    SetFloatValue( float value );
            void    SetDoubleValue( double value );
            
            friend void swap( Number & v1, Number & v2 );
            
        private:
            
            CFNumberRef _cfObject;
    };
}

#endif /* CFPP_NUMBER_H */
