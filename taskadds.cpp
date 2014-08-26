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


#include "taskadds.h"


TaskResult runTask(const QString cmd, const bool useSuid)
{
    return Task::await<TaskResult>( [ & ]() {
        TaskResult r;
        if (useSuid) {
            RootProcess command;
            command.start(cmd);
            command.waitForFinished(-1);
            r.exitCode = command.exitCode();
            r.output = command.readAllStandardOutput();
            r.error = command.readAllStandardError();
        } else {
            QProcess command;
            command.start(cmd);
            command.waitForFinished(-1);
            r.exitCode = command.exitCode();
            r.output = command.readAllStandardOutput();
            r.error = command.readAllStandardError();
        }

        return r;
    });
}
