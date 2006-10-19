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

#ifndef HEADER_GLOBALS_HPP
#define HEADER_GLOBALS_HPP

#include "SDL_net.h"

#include <map>
#include <vector>
#include <string>

class StrokeBuffer;
class ScreenBuffer;
class Stroke;
class ClientState;
class DrawingContext;
class DrawingParameter;
class WidgetManager;
class SaturationValuePicker;
class HuePicker;
class AlphaPicker;
class BrushWidget;
class ServerConnection;
class Scrollbar;

extern SDLNet_SocketSet socketset;

extern Scrollbar* horizontal_scrollbar;
extern Scrollbar* vertical_scrollbar;
extern BrushWidget* brush_widget;
extern DrawingContext*   draw_ctx;
extern DrawingParameter* client_draw_param;
extern std::map<int, ClientState*> client_states;
extern ScreenBuffer*     screen_buffer;
extern StrokeBuffer*     stroke_buffer;
extern WidgetManager* widget_manager;

extern SaturationValuePicker* saturation_value_picker;
extern HuePicker*   hue_picker;
extern AlphaPicker* alpha_picker;
extern ServerConnection* server;
extern Stroke* current_stroke;

#endif

/* EOF */