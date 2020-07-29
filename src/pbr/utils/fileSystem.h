#pragma once

/// \file utils/fileSystem.h
///
/// Common file system utilities.

#include <pbr/pbr.h>

#include <string>
#include <vector>

PBR_NS_OPEN

/// Sanitize the path \p i_path by reducing multiple consecutive forward slashes ("/")
/// into a single one.
std::string SanitizePath( const std::string& i_path );

/// Get the path identified as the parent of \p i_path.
///
/// \param i_path the path to extract its parent from.
///
/// \return the parent path.
std::string GetParentPath( const std::string& i_path );

/// Join two paths \p i_lhs and \p i_rhs by the "/" delimiter.
///
/// \param i_lhs the left hand side path.
/// \param i_rhs the right hand side path.
///
/// \return the joined path.
std::string JoinPaths( const std::string& i_lhs, const std::string& i_rhs );

/// Read the file at \p i_filePath, and return an array of binary data.
///
/// \param i_filePath the path to the file to read.
///
/// \return the binary data in the form of a vector of bytes.
std::vector< char > ReadFile( const std::string& i_filePath );

PBR_NS_CLOSE
