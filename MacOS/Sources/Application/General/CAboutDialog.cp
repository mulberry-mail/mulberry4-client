/*
    Copyright (c) 2007 Cyrus Daboo. All rights reserved.
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


// Source for CAboutDialog class

#include "CAboutDialog.h"

#include "CMulberryApp.h"
#include "CPreferences.h"
#include "CRegistration.h"
#include "CStaticText.h"
#include "CTextDisplay.h"

#include <LPushButton.h>

#include <stdio.h>
#include <string.h>

// __________________________________________________________________________________________________
// C L A S S __ C A B O U T D I A L O G
// __________________________________________________________________________________________________

// C O N S T R U C T I O N / D E S T R U C T I O N  M E T H O D S

// Default constructor
CAboutDialog::CAboutDialog()
{
}

// Constructor from stream
CAboutDialog::CAboutDialog(LStream *inStream)
		: LDialogBox(inStream)
{
}

// Default destructor
CAboutDialog::~CAboutDialog()
{
}

// O T H E R  M E T H O D S ____________________________________________________________________________

// Get details of sub-panes
void CAboutDialog::FinishCreateSelf(void)
{
	LStr255 copyStr;

	// Do inherited
	LDialogBox::FinishCreateSelf();

	// Set up version number
	CStaticText* captionPane = (CStaticText*) FindPaneByID(paneid_VersionNumber);
	cdstring txt = captionPane->GetText();
	txt.Substitute(CPreferences::sPrefs->GetVersionText());
	captionPane->SetText(txt);

	// Link controls to this window
	UReanimator::LinkListenerToBroadcasters(this,this,RidL_CAboutDialogBtns);
}
