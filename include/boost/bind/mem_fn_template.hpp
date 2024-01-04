//
// bind/mem_fn_template.hpp
//
// Do not include this header directly
//
// Copyright 2001, 2024 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/bind/mem_fn.html for documentation.
//

// mf

template<class R, class T, class... A> class BOOST_MEM_FN_NAME(mf)
{
public:

    typedef R result_type;

private:
    
    typedef R (BOOST_MEM_FN_CC T::*Pm) (A...);
    Pm pm_;

public:
    
    explicit BOOST_MEM_FN_NAME(mf)( Pm pm ): pm_( pm ) {}

    template<class U,
        class Ud = typename _mfi::remove_cvref<U>::type,
        class En = typename std::enable_if<
            std::is_same<T, Ud>::value || std::is_base_of<T, Ud>::value
        >::type
    >

    R operator()( U&& u, A... a ) const
    {
        return (std::forward<U>( u ).*pm_)( std::forward<A>( a )... );
    }

    template<class U,
        class Ud = typename _mfi::remove_cvref<U>::type,
        class E1 = void,
        class En = typename std::enable_if<
            !(std::is_same<T, Ud>::value || std::is_base_of<T, Ud>::value)
        >::type
    >

    R operator()( U&& u, A... a ) const
    {
        return (get_pointer( std::forward<U>( u ) )->*pm_)( std::forward<A>( a )... );
    }

    bool operator==( BOOST_MEM_FN_NAME(mf) const & rhs ) const
    {
        return pm_ == rhs.pm_;
    }

    bool operator!=( BOOST_MEM_FN_NAME(mf) const & rhs ) const
    {
        return pm_ != rhs.pm_;
    }
};

// cmf

template<class R, class T, class... A> class BOOST_MEM_FN_NAME(cmf)
{
public:

    typedef R result_type;

private:
    
    typedef R (BOOST_MEM_FN_CC T::*Pm) (A...) const;
    Pm pm_;

public:
    
    explicit BOOST_MEM_FN_NAME(cmf)( Pm pm ): pm_( pm ) {}

    template<class U,
        class Ud = typename _mfi::remove_cvref<U>::type,
        class En = typename std::enable_if<
            std::is_same<T, Ud>::value || std::is_base_of<T, Ud>::value
        >::type
    >

    R operator()( U&& u, A... a ) const
    {
        return (std::forward<U>( u ).*pm_)( std::forward<A>( a )... );
    }

    template<class U,
        class Ud = typename _mfi::remove_cvref<U>::type,
        class E1 = void,
        class En = typename std::enable_if<
            !(std::is_same<T, Ud>::value || std::is_base_of<T, Ud>::value)
        >::type
    >

    R operator()( U&& u, A... a ) const
    {
        return (get_pointer( std::forward<U>( u ) )->*pm_)( std::forward<A>( a )... );
    }

    bool operator==( BOOST_MEM_FN_NAME(cmf) const & rhs ) const
    {
        return pm_ == rhs.pm_;
    }

    bool operator!=( BOOST_MEM_FN_NAME(cmf) const & rhs ) const
    {
        return pm_ != rhs.pm_;
    }
};
