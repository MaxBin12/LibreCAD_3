#pragma once

#include <QPushButton>

#include "luainterface.h"

namespace lc
{
    namespace ui
    {
        namespace api
        {
            class ToolbarButton : public QPushButton
            {
                Q_OBJECT

            public:
                ToolbarButton(const char* buttonLabel, const char* icon, kaguya::LuaRef callback, const char* tooltip = "", QWidget* parent = nullptr);

                ToolbarButton(const char* buttonLabel, const char* icon, const char* tooltip = "", QWidget* parent = nullptr);

                std::string label();

                void setLabel(const char* newLabel);

                void setTooltip(const char* newToolTip);

                void addCallback(kaguya::LuaRef callback);

                void changeIcon(const char* newIconPath);

                void remove();

                void setLuaInterface(LuaInterface* luaInterfaceIn);

            private:
                LuaInterface* luaInterface;
                std::string _label;
                std::vector<kaguya::LuaRef> callbacks;
            };
        }
    }
}
