/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "ModuleXbmcgui.h"
#include "LanguageHook.h"
#include "guilib/GraphicContext.h"
#include "guilib/GUIWindowManager.h"
#include "utils/log.h"

#define NOTIFICATION_INFO     "info"
#define NOTIFICATION_WARNING  "warning"
#define NOTIFICATION_ERROR    "error"

#define INPUT_QWERTY          0
#define INPUT_NUMERIC         1
#define INPUT_DATE            2
#define INPUT_TIME            3
#define INPUT_IPADDRESS       4
#define INPUT_PASSWORD        5

#define PASSWORD_CHOOSE       1
#define PASSWORD_NUMERIC      2
#define PASSWORD_GAMEPAD      4
#define PASSWORD_QWERTY       8
#define PASSWORD_VERIFY       16
#define QWERTY_HIDE_INPUT     32

namespace XBMCAddon
{
  namespace xbmcgui
  {
    void lock()
    {
      CLog::Log(LOGWARNING,"'xbmcgui.lock()' is depreciated and serves no purpose anymore, it will be removed in future releases");
    }

    void unlock()
    {
      CLog::Log(LOGWARNING,"'xbmcgui.unlock()' is depreciated and serves no purpose anymore, it will be removed in future releases");
    }

    long getCurrentWindowId()
    {
      DelayedCallGuard dg;
      CSingleLock gl(g_graphicsContext);
      return g_windowManager.GetActiveWindow();
    }

    long getCurrentWindowDialogId()
    {
      DelayedCallGuard dg;
      CSingleLock gl(g_graphicsContext);
      return g_windowManager.GetTopMostModalDialogID();
    }
    
    const char* getNOTIFICATION_INFO()    { return NOTIFICATION_INFO; }
    const char* getNOTIFICATION_WARNING() { return NOTIFICATION_WARNING; }
    const char* getNOTIFICATION_ERROR()   { return NOTIFICATION_ERROR; }

    // Dialog types
    int getINPUT_QWERTY()       { return INPUT_QWERTY; }
    int getINPUT_NUMERIC()      { return INPUT_NUMERIC; }
    int getINPUT_DATE()         { return INPUT_DATE; }
    int getINPUT_TIME()         { return INPUT_TIME; }
    int getINPUT_IPADDRESS()    { return INPUT_IPADDRESS; }
    int getINPUT_PASSWORD()     { return INPUT_PASSWORD; }
    // Dialog options
    int getPASSWORD_CHOOSE()    { return PASSWORD_CHOOSE; }
    int getPASSWORD_NUMERIC()   { return PASSWORD_NUMERIC; }
    int getPASSWORD_GAMEPAD()   { return PASSWORD_GAMEPAD; }
    int getPASSWORD_QWERTY()    { return PASSWORD_QWERTY; }
    int getPASSWORD_VERIFY()    { return PASSWORD_VERIFY; }
    int getQWERTY_HIDE_INPUT()  { return QWERTY_HIDE_INPUT; }

  }
}
