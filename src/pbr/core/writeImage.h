#pragma once

/// \file core/writeImage.h
///
/// Utilities for writing a image to disk.

#include <pbr/pbr.h>

#include <gm/types/vec3f.h>

#include <pbr/core/imageBuffer.h>

PBR_NS_OPEN

/// Write an RGB image to disk.
///
/// \param i_imageBuffer Image buffer with RGB floating point values.
/// \param i_filePath The path to save the image.
///
/// \return Whether the image was successfully written to disk.
bool WriteRGBImage( const RGBImageBuffer& i_imageBuffer, const std::string& i_filePath );

PBR_NS_CLOSE
