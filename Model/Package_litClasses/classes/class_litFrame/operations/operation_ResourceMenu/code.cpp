//~~ void ResourceMenu(wxCommandEvent& event) [litFrame] ~~
wxMenu aMenu;
std::set<wxString> tokens = milestoneListCtrl->GetResourceTokens();

aMenu.Append(ID_ClearResource ,"clear","", wxITEM_NORMAL);
aMenu.AppendSeparator();

int id = ID_AddResource;

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end(); it++)
{
	wxString aString = *it;
	if (!aString.Trim().empty())
		aMenu.Append(id++,aString,"", wxITEM_NORMAL);
}

PopupMenu(&aMenu);