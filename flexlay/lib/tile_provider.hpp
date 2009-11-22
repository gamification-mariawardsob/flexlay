//  $Id$
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_TILE_PROVIDER_HXX
#define HEADER_TILE_PROVIDER_HXX

#include <ClanLib/Display/sprite.h>
#include <ClanLib/Display/pixel_buffer.h>
#include "shared_ptr.hpp"

class TileProviderImpl;

/** TileProvider provides a flexible way to perform load-on-demand for Tiles */
class TileProvider
{
public:
  TileProvider() {}
  TileProvider(TileProviderImpl* impl);

  CL_Sprite      get_sprite() const;
  CL_PixelBuffer get_pixelbuffer() const;

  operator bool() const { return impl.get(); }
private:
  SharedPtr<TileProviderImpl> impl;
};

#endif

/* EOF */