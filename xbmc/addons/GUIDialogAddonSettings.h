#pragma once
/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
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
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "dialogs/GUIDialogBoxBase.h"
#include "addons/Addon.h"

class CGUIDialogAddonSettings : public CGUIDialogBoxBase
{
public:
  CGUIDialogAddonSettings(void);
  virtual ~CGUIDialogAddonSettings(void);
  virtual bool OnMessage(CGUIMessage& message);
  virtual bool OnAction(const CAction& action);
  /*! \brief Show the addon settings dialog, allowing the user to configure an addon
   \param addon the addon to configure
   \param saveToDisk whether the changes should be saved to disk or just made local to the addon.  Defaults to true
   \return true if settings were changed and the dialog confirmed, false otherwise.
   */
  static bool ShowAndGetInput(const ADDON::AddonPtr &addon, bool saveToDisk = true);
  virtual void DoProcess(unsigned int currentTime, CDirtyRegionList &dirtyregions);

  CStdString GetCurrentID() const;
protected:
  virtual void OnInitWindow();
  virtual int GetDefaultLabelID(int controlId) const;

private:
  /*! \brief return a (localized) addon string.
   \param value either a character string (which is used directly) or a number to lookup in the addons strings.xml
   \param subsetting whether the character string should be prefixed by "- ", defaults to false
   \return the localized addon string
   */
  CStdString GetString(const char *value, bool subSetting = false) const;

  /*! \brief return a the values for a fileenum setting
   \param path the path to use for files
   \param mask the mask to use
   \param options any options, such as "hideext" to hide extensions
   \return the filenames in the path that match the mask
   */
  std::vector<std::string> GetFileEnumValues(const CStdString &path, const CStdString &mask, const CStdString &options) const;

  /*! \brief Translate list of addon IDs to list of addon names
   \param addonIDslist comma seperated list of addon IDs
   \return comma seperated list of addon names
   */
  CStdString GetAddonNames(const CStdString& addonIDslist) const;

  void CreateSections();
  void FreeSections();
  void CreateControls();
  void FreeControls();
  void EnableControls();
  void SetDefaultSettings();
  bool GetBoolCondition(const CStdString &condition, const int controlId);

  CStdString CleanString(const char *value) const;
  CStdString TranslateTokens(const char *value) const;
  void SetSliderTextValue(const CGUIControl *control, const char *format);
  CStdString GetCondition(const char *condition, bool allowHiddenFocus = false) const;

  void SaveSettings(void);
  bool ShowVirtualKeyboard(int iControl);
  bool TranslateSingleString(const CStdString &strCondition, std::vector<CStdString> &enableVec);

  const TiXmlElement *GetFirstSetting() const;

  ADDON::AddonPtr m_addon;
  CStdString m_strHeading;
  CStdString m_closeAction;
  bool m_changed;
  bool m_saveToDisk; // whether the addon settings should be saved to disk or just stored locally in the addon

  unsigned int m_currentSection;
  unsigned int m_totalSections;

  std::map<CStdString,CStdString> m_settings; // local storage of values
};

