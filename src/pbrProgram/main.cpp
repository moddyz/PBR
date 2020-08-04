// Physically based ray tracing program.

#include <cxxopts.hpp>

#include <pbr/utils/log.h>

/// \struct Program options
///
/// Describes the inputs to the renderer program.
struct ProgramOptions
{
    std::vector< std::string > m_inputFiles; //< The input scene files to the renderer.
    std::string                m_outputFile; //< The output image file to write.
};

/// Parse command line arguments into renderer program options.
ProgramOptions ParseCommandLineArguments( int i_argc, char** i_argv )
{
    // Parse command line arguments.
    cxxopts::Options parser( "pbrProgram", "Physically based ray tracing program." );

    parser.add_options()            // Command line parser.
        ( "h,help", "Print usage" ) //
        ( "o,output", "Output file", cxxopts::value< std::string >()->default_value( "out.ppm" ) ) //
        ( "inputs", "Input file(s)", cxxopts::value< std::vector< std::string > >() );

    parser.parse_positional( {"inputs"} );
    auto args = parser.parse( i_argc, i_argv );
    if ( args.count( "help" ) > 0 )
    {
        PBR_LOG_INFO( "%s\n", parser.help().c_str() );
        exit( 0 );
    }

    if ( args.count( "inputs" ) == 0 )
    {
        PBR_LOG_INFO( "%s\n", parser.help().c_str() );
        exit( -1 );
    }

    ProgramOptions programOptions;
    programOptions.m_inputFiles = args[ "inputs" ].as< std::vector< std::string > >();
    programOptions.m_outputFile = args[ "output" ].as< std::string >();
    return programOptions;
}

int main( int i_argc, char** i_argv )
{
    ProgramOptions options = ParseCommandLineArguments( i_argc, i_argv );

    PBR_LOG_INFO( "[pbrProgram] Physically based rendering program\n" );
    PBR_LOG_INFO( "Input scene file(s): " );
    for ( const std::string& inputFile : options.m_inputFiles )
    {
        PBR_LOG_INFO( "%s ", inputFile.c_str() );
    }
    PBR_LOG_INFO( "\nOutput image file: %s\n", options.m_outputFile.c_str() );

    return 0;
}
