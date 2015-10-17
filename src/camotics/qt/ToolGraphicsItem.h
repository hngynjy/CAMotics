/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#ifndef CAMOTICS_TOOL_GRAPHICS_ITEM_H
#define CAMOTICS_TOOL_GRAPHICS_ITEM_H

#include <camotics/sim/Tool.h>
#include <camotics/view/ToolView.h>

#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#include <QtWidgets>
#endif



namespace CAMotics {
  class ToolGraphicsItem : public QGraphicsPixmapItem {
    ToolView toolView;
    unsigned number;
    bool highlight;

  public:
    ToolGraphicsItem(QGraphicsItem *parent = 0);

    unsigned getNumber() const {return number;}

    void update(const Tool &tool, int width, int height);

    // From QGraphicsItem
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
  };
}

#endif // CAMOTICS_TOOL_GRAPHICS_ITEM_H
