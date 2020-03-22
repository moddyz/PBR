#include <hdPbr/renderBuffer.h>

PBR_NAMESPACE_BEGIN

PXR_NAMESPACE_USING_DIRECTIVE

HdPbrRenderBuffer::HdPbrRenderBuffer( const SdfPath& i_bprimId )
    : HdRenderBuffer( i_bprimId )
{
}

bool HdPbrRenderBuffer::Allocate( const GfVec3i& i_dimensions, HdFormat i_format, bool i_multiSampled )
{
    _Deallocate();

    // 2D buffer for now!
    TF_VERIFY( i_dimensions[ 2 ] == 1 );

    m_dimensions = i_dimensions;
    m_format     = i_format;
    m_buffer.resize( m_dimensions[ 0 ] * m_dimensions[ 1 ] * m_dimensions[ 2 ] * HdDataSizeOfFormat( i_format ) );

    printf( "Resizing buffer %s to %lu\n", GetId().GetText(), m_buffer.size() );

    return true;
}

unsigned int HdPbrRenderBuffer::GetWidth() const
{
    return m_dimensions[ 0 ];
}

unsigned int HdPbrRenderBuffer::GetHeight() const
{
    return m_dimensions[ 1 ];
}

unsigned int HdPbrRenderBuffer::GetDepth() const
{
    return m_dimensions[ 2 ];
}

HdFormat HdPbrRenderBuffer::GetFormat() const
{
    return m_format;
}

bool HdPbrRenderBuffer::IsMultiSampled() const
{
    return false;
}

void* HdPbrRenderBuffer::Map()
{
    m_mappers.fetch_add( 1 );
    return static_cast< void* >( m_buffer.data() );
}

void HdPbrRenderBuffer::Unmap()
{
    m_mappers.fetch_sub( 1 );
}

bool HdPbrRenderBuffer::IsMapped() const
{
    return m_mappers.load() > 0;
}

bool HdPbrRenderBuffer::IsConverged() const
{
    return m_converged.load();
}

void HdPbrRenderBuffer::SetConverged( bool i_converged )
{
    m_converged.store( i_converged );
}

void HdPbrRenderBuffer::Resolve()
{
    // Nothing to do, there is only a single internal buffer for read/write.
    return;
}

void HdPbrRenderBuffer::_Deallocate()
{
    TF_VERIFY( !IsMapped() );

    // Reset to default/empty values.
    m_dimensions = GfVec3i( 0, 0, 0 );
    m_format     = HdFormatInvalid;
    m_buffer.resize( 0 );
    m_mappers.store( 0 );
    m_converged.store( false );
}

PBR_NAMESPACE_END
