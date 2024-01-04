//
// bind/mem_fn_cc.hpp - support for different calling conventions
//
// Do not include this header directly.
//
// Copyright 2001, 2024 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/bind/mem_fn.html for documentation.
//

template<class R, class T, class... A> _mfi::BOOST_MEM_FN_NAME(mf)<R, T, A...> mem_fn(R (BOOST_MEM_FN_CC T::*f) (A...) BOOST_MEM_FN_NOEXCEPT)
{
    return _mfi::BOOST_MEM_FN_NAME(mf)<R, T, A...>(f);
}

template<class R, class T, class... A> _mfi::BOOST_MEM_FN_NAME(cmf)<R, T, A...> mem_fn(R (BOOST_MEM_FN_CC T::*f) (A...) const BOOST_MEM_FN_NOEXCEPT)
{
    return _mfi::BOOST_MEM_FN_NAME(cmf)<R, T, A...>(f);
}
