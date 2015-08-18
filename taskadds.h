/***************************************************************************
 *  Copyright (C) 2014  Evgeniy Alekseev                                      *
 *                                                                         *
 *  This library is free software; you can redistribute it and/or          *
 *  modify it under the terms of the GNU Lesser General Public             *
 *  License as published by the Free Software Foundation; either           *
 *  version 3.0 of the License, or (at your option) any later version.     *
 *                                                                         *
 *  This library is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU       *
 *  Lesser General Public License for more details.                        *
 *                                                                         *
 *  You should have received a copy of the GNU Lesser General Public       *
 *  License along with this library.                                       *
 ***************************************************************************/


#ifndef TASKADDS_H
#define TASKADDS_H

#include <QProcess>
#include <unistd.h>

#include "task.h"


class RootProcess : public QProcess
{
protected:
    void setupChildProcess()
    {
        ::setuid(0);
    };
};


struct TaskResult
{
    int exitCode;
    QByteArray error;
    QByteArray output;
    bool status()
    {
        return (exitCode == 0);
    };
};
TaskResult runTask(const QString cmd, const bool useSuid = true);


#endif /* TASKADDS_H */
