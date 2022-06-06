#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QCheckBox>
#include <string>

class Checkbox : public QCheckBox
{
protected:
    std::string dict;
public:
    Checkbox();
};

#endif // CHECKBOX_H
