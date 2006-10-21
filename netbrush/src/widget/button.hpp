/*  $Id$
**   __      __ __             ___        __   __ __   __
**  /  \    /  \__| ____    __| _/_______/  |_|__|  | |  |   ____
**  \   \/\/   /  |/    \  / __ |/  ___/\   __\  |  | |  | _/ __ \
**   \        /|  |   |  \/ /_/ |\___ \  |  | |  |  |_|  |_\  ___/
**    \__/\  / |__|___|  /\____ /____  > |__| |__|____/____/\___  >
**         \/          \/      \/    \/                         \/
**  Copyright (C) 2005 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation; either version 2
**  of the License, or (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
** 
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
**  02111-1307, USA.
*/

#ifndef HEADER_BUTTON_HPP
#define HEADER_BUTTON_HPP

#include "widget.hpp"

class Button;

class ButtonCallback
{
public:
  ButtonCallback() {}
  virtual ~ButtonCallback() {}
  virtual void on_press  (Button* button) =0;
  virtual void on_release(Button* button) =0;
  virtual void on_click  (Button* button) =0;
};

/** */
class Button : public Widget
{
private:
  ButtonCallback* callback;
  
  enum State { UP, DOWN };
  State state;
  bool  hover;

  SDL_Surface* up_surface;
  SDL_Surface* down_surface;
  SDL_Surface* hover_surface;

  SDL_Surface* icon;

public:
  Button(SDL_Surface* icon, const Rect& rect, ButtonCallback* callback_);
  ~Button();

  void on_mouse_motion(const MouseMotionEvent& motion);
  void on_mouse_button(const MouseButtonEvent& button);

  void on_enter();
  void on_leave();

  void draw(SDL_Surface* target);
  
private:
  Button (const Button&);
  Button& operator= (const Button&);
};

#endif

/* EOF */