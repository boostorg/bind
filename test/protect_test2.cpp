// protect_test2.cpp
//
// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/bind/protect.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <boost/core/is_same.hpp>

template<class T, class F> void test( F )
{
    BOOST_TEST_TRAIT_TRUE((boost::core::is_same<typename T::result_type, typename F::result_type>));
}

struct X
{
    struct result_type {};
};

int main()
{
    test<X>( boost::protect( X() ) );

    return boost::report_errors();
}
