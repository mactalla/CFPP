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
 * @file        Test-CFPP-Array.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Array
 */

#include <CF++.h>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Array, CTOR )
{
    CF::Array a;
    
    ASSERT_TRUE( a.IsValid() );
    ASSERT_EQ( a.GetCount(), 0 );
}

TEST( CFPP_Array, CTOR_CFType )
{}

TEST( CFPP_Array, CTOR_CFArray )
{}

TEST( CFPP_Array, CCTOR )
{
    CF::Array a1;
    
    a1 << "hello";
    a1 << "world";
    
    ASSERT_TRUE( a1.IsValid() );
    ASSERT_EQ( a1.GetCount(), 2 );
    
    {
        CF::Array a2( a1 );
        
        ASSERT_TRUE( a1.IsValid() );
        ASSERT_TRUE( a2.IsValid() );
        ASSERT_EQ( a1.GetCount(), 2 );
        ASSERT_EQ( a2.GetCount(), 2 );
    }
}

TEST( CFPP_Array, MCTOR )
{
    CF::Array a1;
    
    a1 << "hello";
    a1 << "world";
    
    ASSERT_TRUE( a1.IsValid() );
    ASSERT_EQ( a1.GetCount(), 2 );
    
    {
        CF::Array a2( std::move( a1 ) );
        
        ASSERT_FALSE( a1.IsValid() );
        ASSERT_TRUE(  a2.IsValid() );
        ASSERT_EQ( a2.GetCount(), 2 );
    }
}

TEST( CFPP_Array, OperatorAssignArray )
{}

TEST( CFPP_Array, OperatorAssignCFType )
{}

TEST( CFPP_Array, OperatorAssignCFArray )
{}

TEST( CFPP_Array, OperatorPlusEqualArray )
{}

TEST( CFPP_Array, OperatorPlusEqualCFType )
{}

TEST( CFPP_Array, OperatorPlusEqualCFArray )
{}

TEST( CFPP_Array, OperatorLeftShiftCFType )
{}

TEST( CFPP_Array, OperatorLeftShiftCChar )
{}

TEST( CFPP_Array, OperatorLeftShiftString )
{}

TEST( CFPP_Array, OperatorLeftShiftNumber )
{}

TEST( CFPP_Array, OperatorSubscript )
{}

TEST( CFPP_Array, GetTypeID )
{
    CF::Array a;
    
    ASSERT_EQ( a.GetTypeID(), CFArrayGetTypeID() );
}

TEST( CFPP_Array, GetCFObject )
{
    CF::Array a1;
    CF::Array a2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE( a1.GetCFObject() != NULL );
    ASSERT_TRUE( a2.GetCFObject() == NULL );
    ASSERT_EQ( CFGetTypeID( a1.GetCFObject() ), CFArrayGetTypeID() );
}

TEST( CFPP_Array, GetCount )
{}

TEST( CFPP_Array, ContainsValue )
{}

TEST( CFPP_Array, RemoveAllValues )
{}

TEST( CFPP_Array, GetValueAtIndex )
{}

TEST( CFPP_Array, SetValueAtIndex )
{}

TEST( CFPP_Array, InsertValueAtIndex )
{}

TEST( CFPP_Array, AppendValue )
{}

TEST( CFPP_Array, RemoveValueAtIndex )
{}

TEST( CFPP_Array, AppendArray )
{}

TEST( CFPP_Array, ExchangeValuesAtIndices )
{}

TEST( CFPP_Array, GetValues )
{}

TEST( CFPP_Array, Swap )
{
    CF::Array a1;
    CF::Array a2;
    
    a1 << "hello";
    a1 << "world";
    
    ASSERT_EQ( a1.GetCount(), 2 );
    ASSERT_EQ( a2.GetCount(), 0 );
    
    swap( a1, a2 );
    
    ASSERT_EQ( a1.GetCount(), 0 );
    ASSERT_EQ( a2.GetCount(), 2 );
}
