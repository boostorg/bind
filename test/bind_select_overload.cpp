//  bind_select_overload_test.cpp
//
//  Copyright (c) 2014 Sergey Ivanov and New Cloud Tech Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

#include <boost/bind.hpp>
#include <boost/bind/select_overload.hpp>

struct X {
    char f( int ) { return 'i'; }
    char f( float ) { return 'f'; }
};

char f( int ) { return 'i'; }
char f( float ) { return 'f'; }

int main() {
    BOOST_TEST( boost::bind( boost::select_overload<void(int)>  ( &f ), _1 )() == 'i' );
    BOOST_TEST( boost::bind( boost::select_overload<void(float)>( &f ), _1 )() == 'f' );

    X x;
    BOOST_TEST( boost::bind( boost::select_overload<void(int)>  ( &X::f ), x, _1 )() == 'i' );
    BOOST_TEST( boost::bind( boost::select_overload<void(float)>( &X::f ), x, _1 )() == 'f' );
}