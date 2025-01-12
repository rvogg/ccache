// Copyright (C) 2019-2021 Joel Rosdahl and other contributors
//
// See doc/AUTHORS.adoc for a complete list of contributors.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#pragma once

#include "Compressor.hpp"

#include <NonCopyable.hpp>

#include <cstdio>

namespace compression {

// A compressor of an uncompressed stream.
class NullCompressor : public Compressor, NonCopyable
{
public:
  // Parameters:
  // - stream: The file to write data to.
  explicit NullCompressor(FILE* stream);

  int8_t actual_compression_level() const override;
  void write(const void* data, size_t count) override;
  void finalize() override;

private:
  FILE* m_stream;
};

} // namespace compression
