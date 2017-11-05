//
// bind_noexecpt_test.cpp - monolithic test for bind.hpp
//
// Copyright 2017 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/config.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/core/lightweight_test.hpp>

#if defined(BOOST_NO_CXX11_NOEXCEPT)

int main()
{
}

#else

//

long f_0() noexcept
{
    return 17041L;
}

long f_1(long a) noexcept
{
    return a;
}

long f_2(long a, long b) noexcept
{
    return a + 10 * b;
}

long f_3(long a, long b, long c) noexcept
{
    return a + 10 * b + 100 * c;
}

long f_4(long a, long b, long c, long d) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d;
}

long f_5(long a, long b, long c, long d, long e) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e;
}

long f_6(long a, long b, long c, long d, long e, long f) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f;
}

long f_7(long a, long b, long c, long d, long e, long f, long g) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g;
}

long f_8(long a, long b, long c, long d, long e, long f, long g, long h) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g + 10000000 * h;
}

long f_9(long a, long b, long c, long d, long e, long f, long g, long h, long i) noexcept
{
    return a + 10 * b + 100 * c + 1000 * d + 10000 * e + 100000 * f + 1000000 * g + 10000000 * h + 100000000 * i;
}

void function_test()
{
    int const i = 1;

    BOOST_TEST( boost::bind(f_0)(i) == 17041L );
    BOOST_TEST( boost::bind(f_1, _1)(i) == 1L );
    BOOST_TEST( boost::bind(f_2, _1, 2)(i) == 21L );
    BOOST_TEST( boost::bind(f_3, _1, 2, 3)(i) == 321L );
    BOOST_TEST( boost::bind(f_4, _1, 2, 3, 4)(i) == 4321L );
    BOOST_TEST( boost::bind(f_5, _1, 2, 3, 4, 5)(i) == 54321L );
    BOOST_TEST( boost::bind(f_6, _1, 2, 3, 4, 5, 6)(i) == 654321L );
    BOOST_TEST( boost::bind(f_7, _1, 2, 3, 4, 5, 6, 7)(i) == 7654321L );
    BOOST_TEST( boost::bind(f_8, _1, 2, 3, 4, 5, 6, 7, 8)(i) == 87654321L );
    BOOST_TEST( boost::bind(f_9, _1, 2, 3, 4, 5, 6, 7, 8, 9)(i) == 987654321L );
}

struct X
{
    mutable unsigned int hash;

    X(): hash(0) {}

    int f0() noexcept { f1(17); return 0; }
    int g0() const noexcept { g1(17); return 0; }

    int f1(int a1) noexcept { hash = (hash * 17041 + a1) % 32768; return 0; }
    int g1(int a1) const noexcept { hash = (hash * 17041 + a1 * 2) % 32768; return 0; }

    int f2(int a1, int a2) noexcept { f1(a1); f1(a2); return 0; }
    int g2(int a1, int a2) const noexcept { g1(a1); g1(a2); return 0; }

    int f3(int a1, int a2, int a3) noexcept { f2(a1, a2); f1(a3); return 0; }
    int g3(int a1, int a2, int a3) const noexcept { g2(a1, a2); g1(a3); return 0; }

    int f4(int a1, int a2, int a3, int a4) noexcept { f3(a1, a2, a3); f1(a4); return 0; }
    int g4(int a1, int a2, int a3, int a4) const noexcept { g3(a1, a2, a3); g1(a4); return 0; }

    int f5(int a1, int a2, int a3, int a4, int a5) noexcept { f4(a1, a2, a3, a4); f1(a5); return 0; }
    int g5(int a1, int a2, int a3, int a4, int a5) const noexcept { g4(a1, a2, a3, a4); g1(a5); return 0; }

    int f6(int a1, int a2, int a3, int a4, int a5, int a6) noexcept { f5(a1, a2, a3, a4, a5); f1(a6); return 0; }
    int g6(int a1, int a2, int a3, int a4, int a5, int a6) const noexcept { g5(a1, a2, a3, a4, a5); g1(a6); return 0; }

    int f7(int a1, int a2, int a3, int a4, int a5, int a6, int a7) noexcept { f6(a1, a2, a3, a4, a5, a6); f1(a7); return 0; }
    int g7(int a1, int a2, int a3, int a4, int a5, int a6, int a7) const noexcept { g6(a1, a2, a3, a4, a5, a6); g1(a7); return 0; }

    int f8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) noexcept { f7(a1, a2, a3, a4, a5, a6, a7); f1(a8); return 0; }
    int g8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) const noexcept { g7(a1, a2, a3, a4, a5, a6, a7); g1(a8); return 0; }
};

void member_function_test()
{
    X x;

    // 0

    boost::bind(&X::f0, &x)();
    boost::bind(&X::f0, boost::ref(x))();

    boost::bind(&X::g0, &x)();
    boost::bind(&X::g0, x)();
    boost::bind(&X::g0, boost::ref(x))();

    // 1

    boost::bind(&X::f1, &x, 1)();
    boost::bind(&X::f1, boost::ref(x), 1)();

    boost::bind(&X::g1, &x, 1)();
    boost::bind(&X::g1, x, 1)();
    boost::bind(&X::g1, boost::ref(x), 1)();

    // 2

    boost::bind(&X::f2, &x, 1, 2)();
    boost::bind(&X::f2, boost::ref(x), 1, 2)();

    boost::bind(&X::g2, &x, 1, 2)();
    boost::bind(&X::g2, x, 1, 2)();
    boost::bind(&X::g2, boost::ref(x), 1, 2)();

    // 3

    boost::bind(&X::f3, &x, 1, 2, 3)();
    boost::bind(&X::f3, boost::ref(x), 1, 2, 3)();

    boost::bind(&X::g3, &x, 1, 2, 3)();
    boost::bind(&X::g3, x, 1, 2, 3)();
    boost::bind(&X::g3, boost::ref(x), 1, 2, 3)();

    // 4

    boost::bind(&X::f4, &x, 1, 2, 3, 4)();
    boost::bind(&X::f4, boost::ref(x), 1, 2, 3, 4)();

    boost::bind(&X::g4, &x, 1, 2, 3, 4)();
    boost::bind(&X::g4, x, 1, 2, 3, 4)();
    boost::bind(&X::g4, boost::ref(x), 1, 2, 3, 4)();

    // 5

    boost::bind(&X::f5, &x, 1, 2, 3, 4, 5)();
    boost::bind(&X::f5, boost::ref(x), 1, 2, 3, 4, 5)();

    boost::bind(&X::g5, &x, 1, 2, 3, 4, 5)();
    boost::bind(&X::g5, x, 1, 2, 3, 4, 5)();
    boost::bind(&X::g5, boost::ref(x), 1, 2, 3, 4, 5)();

    // 6

    boost::bind(&X::f6, &x, 1, 2, 3, 4, 5, 6)();
    boost::bind(&X::f6, boost::ref(x), 1, 2, 3, 4, 5, 6)();

    boost::bind(&X::g6, &x, 1, 2, 3, 4, 5, 6)();
    boost::bind(&X::g6, x, 1, 2, 3, 4, 5, 6)();
    boost::bind(&X::g6, boost::ref(x), 1, 2, 3, 4, 5, 6)();

    // 7

    boost::bind(&X::f7, &x, 1, 2, 3, 4, 5, 6, 7)();
    boost::bind(&X::f7, boost::ref(x), 1, 2, 3, 4, 5, 6, 7)();

    boost::bind(&X::g7, &x, 1, 2, 3, 4, 5, 6, 7)();
    boost::bind(&X::g7, x, 1, 2, 3, 4, 5, 6, 7)();
    boost::bind(&X::g7, boost::ref(x), 1, 2, 3, 4, 5, 6, 7)();

    // 8

    boost::bind(&X::f8, &x, 1, 2, 3, 4, 5, 6, 7, 8)();
    boost::bind(&X::f8, boost::ref(x), 1, 2, 3, 4, 5, 6, 7, 8)();

    boost::bind(&X::g8, &x, 1, 2, 3, 4, 5, 6, 7, 8)();
    boost::bind(&X::g8, x, 1, 2, 3, 4, 5, 6, 7, 8)();
    boost::bind(&X::g8, boost::ref(x), 1, 2, 3, 4, 5, 6, 7, 8)();

    BOOST_TEST( x.hash == 23558 );
}

int main()
{
    function_test();
    member_function_test();

    return boost::report_errors();
}

#endif
