#ifndef BOOST_BIND_SELECT_OVERLOAD_HPP_INCLUDED
#define BOOST_BIND_SELECT_OVERLOAD_HPP_INCLUDED

//
//  select_overload.hpp
//
//  Copyright (c) 2014 Sergey Ivanov and New Cloud Tech Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/config.hpp>

namespace boost
{

template <typename Sig, typename Class>
BOOST_CONSTEXPR Sig Class::* select_overload( Sig( Class::*fn ) ) BOOST_NOEXCEPT
{
  return fn;
}

template <typename Sig>
BOOST_CONSTEXPR Sig* select_overload( Sig( *fn ) ) BOOST_NOEXCEPT
{
  return fn;
}

} // namespace boost

#endif // #ifndef BOOST_BIND_SELECT_OVERLOAD_HPP_INCLUDED