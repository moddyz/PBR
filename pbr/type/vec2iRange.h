#pragma once

#include <pbr/api.h>
#include <pbr/type/bounds2i.h>
#include <pbr/type/vec2i.h>

PBR_NAMESPACE_BEGIN

/// \class Vec2iRange
///
/// Can be used to iterate over range of vectors from \ref i_begin to \ref i_end.
/// The iterator does not visit components equal to those of \ref i_end.
///
/// Usage:
/// pbr::Bounds2i bounds( pbr::Vec2i( 0, 0 ), pbr::Vec2i( 10, 10 ) );
/// for ( const pbr::Vec2i& point : bounds )
/// {
///     ...do something with point...
/// }
///
class PBR_API Vec2iRange final
{
public:
    /// Range constructor.
    Vec2iRange( const Vec2i& i_begin, const Vec2i& i_end )
        : m_begin( i_begin )
        , m_end( i_end )
    {
    }

    class PBR_API iterator final
    {
    public:
        /// Iterator ctor.
        iterator( const Vec2i& i_current, const Vec2i& i_begin, const Vec2i& i_end )
            : m_begin( i_begin )
            , m_end( i_end )
            , m_current( i_current )
        {
        }

        bool operator!=( const iterator& i_other ) const
        {
            return m_current != i_other.m_current;
        }

        Vec2i operator*() const
        {
            return m_current;
        }

        const iterator& operator++()
        {
            if ( m_current[ 0 ] < m_end[ 0 ] || ( m_current[ 0 ] == m_end[ 0 ] && m_current[ 1 ] == m_end[ 1 ] ) )
            {
                m_current[ 0 ]++;
            }
            else
            {
                if ( m_current[ 1 ] < m_end[ 1 ] )
                {
                    m_current[ 1 ]++;
                    m_current[ 0 ] = m_begin[ 0 ];
                }
            }
            return *this;
        }

    private:
        Vec2i m_begin;
        Vec2i m_end;
        Vec2i m_current;
    };

    iterator begin()
    {
        return iterator( m_begin, m_begin, Vec2i( m_end[ 0 ] - 1, m_end[ 1 ] - 1 ) );
    }

    iterator end()
    {
        return iterator( Vec2i( m_end[ 0 ], m_end[ 1 ] - 1 ), m_begin, Vec2i( m_end[ 0 ] - 1, m_end[ 1 ] - 1 ) );
    }

private:
    Vec2i m_begin;
    Vec2i m_end;
};

PBR_NAMESPACE_END
