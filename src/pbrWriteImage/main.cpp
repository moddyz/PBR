// Physically based ray tracing program.

#include <cxxopts.hpp>

#include <pbr/core/imageBuffer.h>
#include <pbr/core/writeImage.h>
#include <pbr/utils/log.h>

/// \struct Program options
///
/// Describes the inputs to the renderer program.
struct ProgramOptions
{
    int         m_width  = 0;
    int         m_height = 0;
    std::string m_outputFile; //< The output image file to write.
};

/// Parse command line arguments into renderer program options.
ProgramOptions ParseCommandLineArguments( int i_argc, char** i_argv )
{
    // Parse command line arguments.
    cxxopts::Options parser( "pbrProgram", "Physically based ray tracing program." );

    parser.add_options()          // Command line parser.
        ( "help", "Print usage" ) // Print help message.
        ( "w,width", "Width of the output file", cxxopts::value< int >()->default_value( "640" ) )   // Width
        ( "h,height", "Height of the output file", cxxopts::value< int >()->default_value( "480" ) ) // Height
        ( "o,output", "Output file", cxxopts::value< std::string >()->default_value( "output.jpg" ) );

    auto args = parser.parse( i_argc, i_argv );
    if ( args.count( "help" ) > 0 )
    {
        PBR_LOG_INFO( "%s\n", parser.help().c_str() );
        exit( 0 );
    }

    ProgramOptions programOptions;
    programOptions.m_width      = args[ "width" ].as< int >();
    programOptions.m_height     = args[ "height" ].as< int >();
    programOptions.m_outputFile = args[ "output" ].as< std::string >();
    return programOptions;
}

int main( int i_argc, char** i_argv )
{
    ProgramOptions options = ParseCommandLineArguments( i_argc, i_argv );

    PBR_LOG_INFO( "[pbrWriteImage]\n" );
    PBR_LOG_INFO( "\tWidth: %i\n", options.m_width );
    PBR_LOG_INFO( "\tHeight: %i\n", options.m_height );
    PBR_LOG_INFO( "\tOutput image file: %s\n", options.m_outputFile.c_str() );

    pbr::RGBImageBuffer image( options.m_width, options.m_height );
    for ( gm::Vec2i coord : image.Extent() )
    {
        float radiance = ( float ) coord.Y() / ( float ) image.Extent().Max().Y();
        image( coord.X(), coord.Y() ) = gm::Vec3f( radiance, radiance, radiance );
    }

    WriteRGBImage( image, options.m_outputFile );

    return 0;
}
