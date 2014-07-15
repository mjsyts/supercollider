/*
    SuperCollider Qt IDE
    Copyright (c) 2012 Jakob Leben & Tim Blechmann
    http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef SCIDE_CORE_SETTINGS_THEME_HPP_INCLUDED
#define SCIDE_CORE_SETTINGS_THEME_HPP_INCLUDED

#include <QMap>
#include <QList>
#include <QString>
#include <QTextCharFormat>

namespace ScIDE { namespace Settings {

class Manager;

class Theme
{

public:
    Theme(const QString & _name, const Manager *settings = NULL);
    Theme(const QString & _name, const QString & _source);

    ~Theme();

    void setFormat(const QString & key, const QTextCharFormat & format);
    const QTextCharFormat & format(const QString & key);
    QString & name();
    bool locked();
    QList<QString> availableThemes();

    void save();
    void remove();

private:
    void fillUser(const QString & theme, const Manager *settings);
    void fillDefault();

    bool mLocked;
    QMap<QString, QTextCharFormat *> mFormats;
    QString mName;
};

}} // namespace ScIDE:Settings

#endif
