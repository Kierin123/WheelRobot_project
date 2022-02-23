#include "command.h"

QString Command::getCommand()
{
    return CommandToSend;
}
QString Command::getCommandName()
{
    return CommandName;
}
void Command::setCommand(QString ToSend)
{
    CommandToSend = ToSend;
}
void Command::setCommandName(QString Name)
{
    CommandName = Name;
}
bool Command::isEmpty()
{
    if(CommandToSend.isEmpty() || (CommandName.isEmpty()))
        return true;
    else
        return false;
}
