wxMenu aMenu;

aMenu.Append(ID_ClearProject ,"clear","", wxITEM_NORMAL);
aMenu.AppendSeparator();

std::set<wxString> tokens = milestoneListCtrl->GetProjectTokens();

int id = ID_AddProject;

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end(); it++)
{
	wxString aString = *it;
	if (!aString.Trim().empty())
		aMenu.Append(id++,aString,"", wxITEM_NORMAL);
}

PopupMenu(&aMenu);