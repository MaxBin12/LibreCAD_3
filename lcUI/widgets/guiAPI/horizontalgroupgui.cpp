#include "horizontalgroupgui.h"

#include "buttongui.h"
#include "checkboxgui.h"
#include "radiobuttongui.h"

using namespace lc::ui::api;

HorizontalGroupGUI::HorizontalGroupGUI(std::string label, QWidget* parent)
    :
    InputGUI(label, parent)
{
    qhboxlayout = new QHBoxLayout();
    this->setLayout(qhboxlayout);
}

void HorizontalGroupGUI::addWidget(QWidget* newWidget) {
    newWidget->setParent(this);
    _widgets.push_back(newWidget);
    qhboxlayout->addWidget(newWidget);
}

void HorizontalGroupGUI::getLuaValue(kaguya::LuaRef& table) {
    for (QWidget* inputWidget : _widgets) {
        InputGUI* inpgui = qobject_cast<InputGUI*>(inputWidget);
        if (inpgui != nullptr) {
            inpgui->getLuaValue(table);
        }else {
            CheckBoxGUI* checkbox = qobject_cast<CheckBoxGUI*>(inputWidget);
            if (checkbox != nullptr) {
                checkbox->getLuaValue(table);
            }

            RadioButtonGUI* radiobutton = qobject_cast<RadioButtonGUI*>(inputWidget);
            if (radiobutton != nullptr) {
                radiobutton->getLuaValue(table);
            }
        }
    }
}
