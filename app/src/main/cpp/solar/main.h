#pragma once

#include <jni.h>

#include "menu/menu.h"
#include "log/logger.h"

namespace Solar {

    namespace Info {

        const char *m_bSolarMarquee = "Solar Kitten v1.0";

    }

    namespace Modules {

        bool m_bToggle = *new bool;
        bool m_bToggle_ = *new bool;
        bool m_bToggle__ = *new bool;

        int m_bSeekBar = *new int;
        int m_bSeekBar_ = *new int;

    }

}