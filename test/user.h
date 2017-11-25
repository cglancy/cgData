/**
* Copyright 2017 Charles Glancy (charles@glancyfamily.net)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without restriction, including  without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef CUTEDATA_USER_H
#define CUTEDATA_USER_H
#pragma once

#include "dataobject.h"
#include "datatypes.h"

class User : public CuteData::DataObject
{
    Q_OBJECT
    QD_PROPERTY(name, QString, m_name)
    QD_PROPERTY(email, QString, m_email)
    QD_ONE_TO_MANY_RELATIONSHIP(posts, Post, user)
    QD_ONE_TO_MANY_RELATIONSHIP(comments, Comment, user)
    QD_MANY_TO_MANY_RELATIONSHIP(followers, User, followees)
    QD_ONE_TO_ONE_RELATIONSHIP(profile, UserProfile, user)

public:
    Q_INVOKABLE User() {}

    void init(const QString &name, const QString &email);

    QString name() const { return m_name; }
    void setName(const QString &name) { m_name = name; }

    QString email() const { return m_email; }
    void setEmail(const QString &email) { m_email = email; }
};

#endif // CUTEDATA_USER_H
