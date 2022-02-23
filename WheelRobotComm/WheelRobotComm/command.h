#ifndef COMMAND_H
#define COMMAND_H

#include<QString>
#include<QVector>

enum
{
    FORWARD_SPEED = 'X',
    BACKWARD_SPEED = 'Z',
    STOP = 'S',
    FORWARD_DISTANCE = 'F',
    BACKWARD_DISTANCE = 'B',
    TURN_LEFT = 'L',
    TURN_RIGHT = 'R',
    MOTOR_LEFT = 'M',
    MOTOR_RIGHT = 'N',
    EXIT = 'E',
    ARC_RIGHT = 'W',
    ARC_LEFT = 'Q',
    CHANGE_FAKTOR_L = 'G',
    CHANGE_FAKTOR_R = 'H',
};




class Command
{
    QString CommandToSend;
    QString CommandName;

public:

    Command() : CommandToSend(""), CommandName("") {}
    Command(QString ToSend, QString Name) : CommandToSend(ToSend), CommandName(Name) {}


    QString getCommand();
    QString getCommandName();
    void setCommand(QString ToSend);
    void setCommandName(QString Name);
    bool isEmpty();

};

const Command availableCommandArray[] =
{
    Command(QString(FORWARD_SPEED),"Forward with speed "),
    Command(QString(BACKWARD_SPEED),"Backward with speed "),
    Command(QString(STOP),"Stop"),
    Command(QString(FORWARD_DISTANCE),"Forward by distance"),
    Command(QString(BACKWARD_DISTANCE),"Backward by distance"),
    Command(QString(TURN_LEFT),"Turn Left"),
    Command(QString(TURN_RIGHT),"Turn Right"),
    Command(QString(MOTOR_LEFT),"Motor left set speed "),
    Command(QString(MOTOR_RIGHT),"Motor right set speed "),
    Command(QString(EXIT),"Exit"),
    Command(QString(ARC_RIGHT),"Arc right "),
    Command(QString(ARC_LEFT),"Arc left "),
    Command(QString(CHANGE_FAKTOR_L),"Factor left "),
    Command(QString(CHANGE_FAKTOR_R),"Factor right "),
};


class CommandVector
{
    QVector<Command> commVector;
public:
    CommandVector()
    {
        commVector.push_back(Command("",""));
    }
    CommandVector(Command commandToPush)
    {
        commVector.push_back(Command(commandToPush.getCommand(),commandToPush.getCommandName()));
    }

    Command* begin()
    {
       return commVector.begin();
    }
    Command* end()
    {
       return commVector.end();
    }

    void clear()
    {
        commVector.clear();
    }

    void remove(qint32 it)
    {
        commVector.remove(it);
    }


    Command getLast()
    {
        return *(commVector.end()-1);
    }

    void pushBack(Command newCommand)
    {
        commVector.push_back(newCommand);
    }

//    Command checkIfAvailable(QString inputString)
//    {
//        for (auto arrayIndex : availableCommandArray) {
//            if(inputString[0] == arrayIndex.getCommand())
//            {
//                if(checkNumeric(inputString,1) &&  checkNumeric(inputString,2) && checkNumeric(inputString,3))
//                {
//                    if(checkColonOnPlace(inputString,4))
//                    {
//                        return Command(arrayIndex.getCommand(), arrayIndex.getCommandName());
//                    } else{}
//                } else{}
//            } else{}

//        }
//        return Command("","");
//    }

//    bool checkNumeric(QString strToCheck, quint32 position)
//    {
//        bool output = false;
//        if(strToCheck.isEmpty())
//        {
//            output = false;
//        } else if(strToCheck.at(position).isDigit())
//        {
//            output = true;
//        }
//        return output;
//    }

//    bool checkColonOnPlace(QString strToCheck, quint32 position)
//    {
//        bool output = false;
//        if(strToCheck.isEmpty())
//        {
//            output = false;
//        } else if(strToCheck.at(position) == ',')
//        {
//            output = true;
//        }
//        return output;
//    }


};

#endif // COMMAND_H
